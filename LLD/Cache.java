// This code implements a pluggable caching system with the following features:
// 1. Put: Add a key-value pair to the cache.
// 2. Get: Retrieve a value using its key.
// 3. Eviction: Automatically remove a key when the cache is full, based on a pluggable eviction policy.
// The storage mechanism (e.g., InMemory, RDBMS, NoSQL) and eviction policy (e.g., LRU, LFU, FIFO) are pluggable.
// The implementation adheres to SOLID principles and is designed for extensibility.

import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;

interface CacheStorage<K, V> {
    void put(K key, V value);
    V get(K key);
    void remove(K key);
    boolean isFull();
}

interface EvictionPolicy<K> {
    void keyAccessed(K key);
    K evictKey();
}

public class Cache<K, V> {
    private final CacheStorage<K, V> storage;
    private final EvictionPolicy<K> evictionPolicy;

    public Cache(CacheStorage<K, V> storage, EvictionPolicy<K> evictionPolicy) {
        this.storage = storage;
        this.evictionPolicy = evictionPolicy;
    }

    public void put(K key, V value) {
        if (storage.isFull()) {
            K evictedKey = evictionPolicy.evictKey();
            if (evictedKey != null) {
                storage.remove(evictedKey);
            }
        }
        storage.put(key, value);
        evictionPolicy.keyAccessed(key);
    }

    public V get(K key) {
        V value = storage.get(key);
        if (value != null) {
            evictionPolicy.keyAccessed(key);
        }
        return value;
    }
}

class LRUEvictionPolicy<K> implements EvictionPolicy<K> {
    private final LinkedHashMap<K, Boolean> accessOrder;

    public LRUEvictionPolicy() {
        this.accessOrder = new LinkedHashMap<>(16, 0.75f, true);
    }

    @Override
    public void keyAccessed(K key) {
        accessOrder.put(key, true);
    }

    @Override
    public K evictKey() {
        if (accessOrder.isEmpty()) {
            return null;
        }
        K oldestKey = accessOrder.keySet().iterator().next();
        accessOrder.remove(oldestKey);
        return oldestKey;
    }
}

class InMemoryStorage<K, V> implements CacheStorage<K, V> {
    private final Map<K, V> storage;
    private final int capacity;

    public InMemoryStorage(int capacity) {
        this.capacity = capacity;
        this.storage = new HashMap<>();
    }

    @Override
    public void put(K key, V value) {
        storage.put(key, value);
    }

    @Override
    public V get(K key) {
        return storage.get(key);
    }

    @Override
    public void remove(K key) {
        storage.remove(key);
    }

    @Override
    public boolean isFull() {
        return storage.size() >= capacity;
    }
}

class Main {
    public static void main(String[] args) {
        CacheStorage<String, String> storage = new InMemoryStorage<>(3);
        EvictionPolicy<String> evictionPolicy = new LRUEvictionPolicy<>();
        Cache<String, String> cache = new Cache<>(storage, evictionPolicy);

        cache.put("key1", "value1");
        cache.put("key2", "value2");
        cache.put("key3", "value3");
        System.out.println(cache.get("key1")); // Output: value1
        cache.put("key4", "value4"); // Evicts key2 (LRU)
        System.out.println(cache.get("key2")); // Output: null
        System.out.println(cache.get("key3")); // Output: value3
    }
}