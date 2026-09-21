// Low-Level Design: Cache System 💾
//
// A cache system efficiently stores and retrieves data under constrained capacity,
// applies eviction policies, and supports concurrent access with per-key ordering.
//
// Setup:
// • Configurable maximum capacity.
// • Entries: unique key → value.
// • Supports multiple eviction policies (e.g., LRU).
// • Operations: put, get, remove.
//
// Features:
// • Thread-safe concurrent access.
// • Write-through to underlying DB storage.
// • LRU eviction when capacity reached.
// • Per-key task ordering via a pool of single-thread executors.
// • Cache hit/miss tracking.
//
import java.util.*;
import java.util.concurrent.*;
import java.util.function.Supplier;
import java.util.stream.Collectors;

// --------- Storage Interfaces ---------
interface CacheStorage<K, V> {
    void put(K key, V value) throws Exception;
    V get(K key) throws Exception;
    void remove(K key) throws Exception;
    boolean containsKey(K key);
    int size();
    int getCapacity();
}

interface DBStorage<K, V> {
    void write(K key, V value) throws Exception;
    V read(K key) throws Exception;
    void delete(K key) throws Exception;
}

// --------- In-Memory Cache Implementation ---------
class InMemoryCacheStorage<K, V> implements CacheStorage<K, V> {
    private final ConcurrentMap<K, V> cache;
    private final int capacity;

    public InMemoryCacheStorage(int capacity) {
        this.capacity = capacity;
        this.cache = new ConcurrentHashMap<>();
    }
    public void put(K key, V value) throws Exception {
        cache.put(key, value);
    }
    public V get(K key) throws Exception {
        V v = cache.get(key);
        if (v == null) throw new Exception("Cache miss for key: " + key);
        return v;
    }
    public void remove(K key) {
        cache.remove(key);
    }
    public boolean containsKey(K key) {
        return cache.containsKey(key);
    }
    public int size() { return cache.size(); }
    public int getCapacity() { return capacity; }
}

// --------- Mock DB Storage ---------
class SimpleDBStorage<K, V> implements DBStorage<K, V> {
    private final ConcurrentMap<K, V> db = new ConcurrentHashMap<>();
    public void write(K key, V value) {
        db.put(key, value);
    }
    public V read(K key) throws Exception {
        V v = db.get(key);
        if (v == null) throw new Exception("DB miss for key: " + key);
        return v;
    }
    public void delete(K key) {
        db.remove(key);
    }
}

// --------- Write Policy (Write-Through) ---------
interface WritePolicy<K, V> {
    void write(K key, V value,
               CacheStorage<K, V> cache,
               DBStorage<K, V> db) throws Exception;
}

class WriteThroughPolicy<K, V> implements WritePolicy<K, V> {
    public void write(K key, V value,
                      CacheStorage<K, V> cache,
                      DBStorage<K, V> db) throws Exception {
        CompletableFuture<Void> f1 = CompletableFuture.runAsync(() -> {
            try { cache.put(key, value); }
            catch (Exception e) { throw new CompletionException(e); }
        });
        CompletableFuture<Void> f2 = CompletableFuture.runAsync(() -> {
            try { db.write(key, value); }
            catch (Exception e) { throw new CompletionException(e); }
        });
        CompletableFuture.allOf(f1, f2).join();
    }
}

// --------- Eviction Algorithm (LRU) ---------
interface EvictionAlgorithm<K> {
    void keyAccessed(K key);
    K evictKey();
}

class DoublyLinkedListNode<K> {
    final K key;
    DoublyLinkedListNode<K> prev, next;
    DoublyLinkedListNode(K key) { this.key = key; }
}

class DoublyLinkedList<K> {
    private DoublyLinkedListNode<K> head, tail;
    public void moveToTail(DoublyLinkedListNode<K> node) {
        if (node == tail) return;
        if (node.prev != null) node.prev.next = node.next;
        else head = node.next;
        if (node.next != null) node.next.prev = node.prev;
        else tail = node.prev;
        node.prev = tail;
        node.next = null;
        if (tail != null) tail.next = node;
        tail = node;
        if (head == null) head = tail;
    }
    public void add(K key, Map<K, DoublyLinkedListNode<K>> map) {
        var node = new DoublyLinkedListNode<>(key);
        map.put(key, node);
        if (tail == null) {
            head = node;
            tail = node;
        } else {
            tail.next = node;
            node.prev = tail;
            tail = node;
        }
    }
    public K removeHead() {
        if (head == null) return null;
        K k = head.key;
        mapRemove(head, k);
        return k;
    }
    private void mapRemove(DoublyLinkedListNode<K> node, K k) {
        if (node.next != null) node.next.prev = null;
        head = node.next;
        if (head == null) tail = null;
    }
}

class LRUEvictionAlgorithm<K> implements EvictionAlgorithm<K> {
    private final DoublyLinkedList<K> dll = new DoublyLinkedList<>();
    private final Map<K, DoublyLinkedListNode<K>> map = new HashMap<>();
    public synchronized void keyAccessed(K key) {
        if (map.containsKey(key)) dll.moveToTail(map.get(key));
        else dll.add(key, map);
    }
    public synchronized K evictKey() {
        K k = dll.removeHead();
        if (k != null) map.remove(k);
        return k;
    }
}

// --------- Key-Based Executor for Per-Key Ordering ---------
class KeyBasedExecutor {
    private final ExecutorService[] executors;
    public KeyBasedExecutor(int n) {
        executors = new ExecutorService[n];
        for (int i = 0; i < n; i++) executors[i] = Executors.newSingleThreadExecutor();
    }
    <T> CompletableFuture<T> submit(Object key, Supplier<T> task) {
        int idx = Math.abs(key.hashCode() % executors.length);
        return CompletableFuture.supplyAsync(task, executors[idx]);
    }
    void shutdown() { Arrays.stream(executors).forEach(ExecutorService::shutdown); }
}

// --------- Cache Class ---------
class Cache<K, V> {
    private final CacheStorage<K, V> cacheStorage;
    private final DBStorage<K, V> dbStorage;
    private final WritePolicy<K, V> writePolicy;
    private final EvictionAlgorithm<K> evictionAlg;
    private final KeyBasedExecutor executor;

    public Cache(CacheStorage<K, V> cacheStorage,
                 DBStorage<K, V> dbStorage,
                 WritePolicy<K, V> writePolicy,
                 EvictionAlgorithm<K> evictionAlg,
                 int numExecutors) {
        this.cacheStorage = cacheStorage;
        this.dbStorage = dbStorage;
        this.writePolicy = writePolicy;
        this.evictionAlg = evictionAlg;
        this.executor   = new KeyBasedExecutor(numExecutors);
    }

    public CompletableFuture<V> accessData(K key) {
        return executor.submit(key, () -> {
            try {
                if (!cacheStorage.containsKey(key)) throw new Exception("Cache miss");
                evictionAlg.keyAccessed(key);
                return cacheStorage.get(key);
            } catch (Exception e) {
                throw new CompletionException(e);
            }
        });
    }

    public CompletableFuture<Void> updateData(K key, V value) {
        return executor.submit(key, () -> {
            try {
                if (!cacheStorage.containsKey(key) &&
                    cacheStorage.size() >= cacheStorage.getCapacity()) {
                    K evicted = evictionAlg.evictKey();
                    if (evicted != null) cacheStorage.remove(evicted);
                }
                writePolicy.write(key, value, cacheStorage, dbStorage);
                evictionAlg.keyAccessed(key);
                return null;
            } catch (Exception e) {
                throw new CompletionException(e);
            }
        });
    }

    public void shutdown() { executor.shutdown(); }
}

// --------- Demo ---------
class CacheDemo {
    public static void main(String[] args) {
        var cacheStor = new InMemoryCacheStorage<String, String>(5);
        var dbStor    = new SimpleDBStorage<String, String>();
        var wp        = new WriteThroughPolicy<String, String>();
        var lru       = new LRUEvictionAlgorithm<String>();
        var cache     = new Cache<>(cacheStor, dbStor, wp, lru, 4);

        // populate
        cache.updateData("A", "Apple").join();
        cache.updateData("B", "Banana").join();
        cache.updateData("C", "Cherry").join();
        cache.updateData("D", "Durian").join();
        cache.updateData("E", "Elderberry").join();
        // triggers eviction of "A"
        cache.updateData("F", "Fig").join();

        try {
            System.out.println("A: " + cache.accessData("A").join());
        } catch (Exception ignore) {
            System.out.println("A is evicted or missing");
        }

        System.out.println("F: " + cache.accessData("F").join());
        cache.shutdown();
    }
}
