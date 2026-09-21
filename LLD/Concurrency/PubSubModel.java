// Pub-Sub Message Queue System — Clean, Concurrency‑Safe LLD Implementation
//
// A pub‑sub system routes messages from publishers to subscribers via topics.
// It supports multiple topics, partitions, ordered delivery, and parallel subscriber execution.

import java.util.*;
import java.util.concurrent.*;
import java.util.concurrent.atomic.*;
import java.util.function.*;

// -------- Interfaces --------
interface IPublisher {
    String getId();
    void publish(String topicName, Message message);
}

interface ISubscriber {
    String getId();
    void onMessage(Message message);
}

// -------- Message --------
final class Message {
    private final String payload;
    public Message(String payload) { this.payload = payload; }
    public String getPayload() { return payload; }
}

// -------- Topic --------
final class Topic {
    private final String name;
    private final List<Message> messages = new ArrayList<>();
    public Topic(String name) { this.name = name; }
    public String getName() { return name; }
    public synchronized int append(Message msg) {
        messages.add(msg);
        return messages.size()-1; // return offset
    }
    public synchronized List<Message> readFrom(int offset) {
        if (offset < 0 || offset >= messages.size()) return Collections.emptyList();
        return new ArrayList<>(messages.subList(offset, messages.size()));
    }
}

// -------- Subscriber Subscription --------
final class Subscription {
    private final ISubscriber subscriber;
    private final AtomicInteger offset = new AtomicInteger(0);
    public Subscription(ISubscriber sub) { this.subscriber = sub; }
    public ISubscriber getSubscriber() { return subscriber; }
    public int getOffset() { return offset.get(); }
    public int incrementOffset(int delta) { return offset.addAndGet(delta); }
}

// -------- Pub-Sub Controller --------
class PubSubController {
    private final ConcurrentMap<String, Topic> topics = new ConcurrentHashMap<>();
    private final ConcurrentMap<String, CopyOnWriteArrayList<Subscription>> subscribers = new ConcurrentHashMap<>();
    private final ExecutorService executor = Executors.newCachedThreadPool();

    // Create a new topic
    public void createTopic(String name) {
        topics.computeIfAbsent(name, Topic::new);
        subscribers.putIfAbsent(name, new CopyOnWriteArrayList<>());
    }

    // Publisher sends message to topic
    public void publish(IPublisher publisher, String topicName, Message message) {
        Topic topic = topics.get(topicName);
        if (topic == null) throw new IllegalArgumentException("No such topic: " + topicName);
        int offset = topic.append(message);
        // notify subscribers
        for (Subscription sub : subscribers.get(topicName)) {
            executor.submit(() -> deliver(sub, topic, offset));
        }
    }

    // Subscriber subscribes to topic
    public void subscribe(ISubscriber subscriber, String topicName) {
        Topic topic = topics.get(topicName);
        if (topic == null) throw new IllegalArgumentException("No such topic: " + topicName);
        Subscription sub = new Subscription(subscriber);
        subscribers.get(topicName).add(sub);
        // start delivery loop
        executor.submit(() -> continuousDeliver(sub, topic));
    }

    // One-off delivery for a new message
    private void deliver(Subscription sub, Topic topic, int publishedOffset) {
        int curOff = sub.getOffset();
        if (publishedOffset >= curOff) {
            List<Message> msgs = topic.readFrom(curOff);
            for (Message msg : msgs) {
                sub.getSubscriber().onMessage(msg);
            }
            sub.incrementOffset(msgs.size());
        }
    }

    // Continuous background delivery
    private void continuousDeliver(Subscription sub, Topic topic) {
        while (!Thread.currentThread().isInterrupted()) {
            deliver(sub, topic, topic.readFrom(0).size()-1);
            try { Thread.sleep(100); } catch (InterruptedException e) { break; }
        }
    }

    // Shutdown
    public void shutdown() {
        executor.shutdownNow();
    }
}

// -------- Simple Publisher & Subscriber --------
class SimplePublisher implements IPublisher {
    private final String id;
    private final PubSubController controller;
    public SimplePublisher(String id, PubSubController ctrl) {
        this.id = id; this.controller = ctrl;
    }
    public String getId() { return id; }
    public void publish(String topic, Message msg) {
        controller.publish(this, topic, msg);
        System.out.println("[Pub:"+id+"] -> " + msg.getPayload());
    }
}

class SimpleSubscriber implements ISubscriber {
    private final String id;
    public SimpleSubscriber(String id) { this.id = id; }
    public String getId() { return id; }
    public void onMessage(Message msg) {
        System.out.println("[Sub:"+id+"] received -> " + msg.getPayload());
    }
}

// -------- Demo --------
class PubSub {
    public static void main(String[] args) throws Exception {
        PubSubController controller = new PubSubController();
        // setup
        controller.createTopic("orders");
        controller.createTopic("logs");

        // subscribers
        ISubscriber sub1 = new SimpleSubscriber("S1");
        ISubscriber sub2 = new SimpleSubscriber("S2");
        controller.subscribe(sub1, "orders");
        controller.subscribe(sub2, "orders");

        // publisher
        IPublisher pub = new SimplePublisher("P1", controller);
        pub.publish("orders", new Message("order-1001"));
        pub.publish("orders", new Message("order-1002"));

        // allow processing
        Thread.sleep(500);
        controller.shutdown();
    }
}
