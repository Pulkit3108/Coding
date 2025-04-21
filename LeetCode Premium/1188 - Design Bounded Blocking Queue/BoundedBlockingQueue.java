// Problem Statement
// Design a thread-safe bounded blocking queue that holds integer elements in FIFO order. 
// The queue has a fixed maximum capacity. The class should support the following methods:

// BoundedBlockingQueue(int capacity)
// Initialize the queue with a maximum capacity.

// void enqueue(int element) throws InterruptedException
// Add an element to the end of the queue.
// If the queue is full, the calling thread must block until space becomes available.

// int dequeue() throws InterruptedException
// Remove and return the element at the front of the queue.
// If the queue is empty, the calling thread must block until an element becomes available.

// int size()
// Return the current number of elements in the queue.
// This method must return immediately without blocking.

// All methods must be thread-safe and may be called by multiple threads concurrently.

// Constraints:
// 1 <= capacity <= 1000
// Total number of calls to enqueue, dequeue, and size will not exceed 10^4.
// Calls to enqueue/dequeue may block, but no deadlock should occur.

// Examples:

// Example 1:
// Input:
// ["BoundedBlockingQueue","enqueue","enqueue","enqueue","dequeue","dequeue","enqueue","size"]
// [[2],[1],[0],[2],[],[],[3],[]]

// Output:
// [null,null,null,null,1,0,null,1]

// Explanation:
// BoundedBlockingQueue q = new BoundedBlockingQueue(2);
// q.enqueue(1);   // queue = [1]
// q.enqueue(0);   // queue = [1,0]
// q.enqueue(2);   // blocks until a dequeue, then queue = [1,0,2] but since capacity=2 
//                 // it waits internally and only enqueues after a dequeue.
// q.dequeue();    // returns 1, queue = [0]
// q.dequeue();    // returns 0, queue = []
// q.enqueue(3);   // queue = [3]
// q.size();       // returns 1

public class BoundedBlockingQueue {
    private Semaphore availableSlots;
    private Semaphore availableItems;
    private ConcurrentLinkedDeque<Integer> queue;

    public BoundedBlockingQueue(int capacity) {
        this.queue = new ConcurrentLinkedDeque<>();
        this.availableSlots = new Semaphore(capacity);
        this.availableItems = new Semaphore(0);
    }

    public void enqueue(int element) throws InterruptedException {
        availableSlots.acquire();
        queue.addLast(element);
        availableItems.release();
    }

    public int dequeue() throws InterruptedException {
        availableItems.acquire();
        int element = queue.removeFirst();
        availableSlots.release();
        return element;
    }

    public int size() {
        return queue.size();
    }
}
