// Singleton Pattern: Creational design pattern that restricts the instantiation of a class to one object.
// It is used when only one object is needed to coordinate actions across the system.
// Use cases: Logger, Configuration, Cache, Thread Pool, Database Connection, etc.

// Singleton class using double checked locking
public class Singleton {
    private static volatile Singleton instance = null;

    private Singleton() {
        System.out.println("Singleton instance created");
    }

    public static Singleton getInstance() {
        if (instance == null) {
            synchronized (Singleton.class) {
                if (instance == null) {
                    instance = new Singleton();
                }
            }
        }
        return instance;
    }
}

// Singleton class using the Bill Pugh implementation
class BillPughSingleton {
    private BillPughSingleton() {
        System.out.println("Singleton instance created");
    }

    private static class SingletonHelper {
        private static final BillPughSingleton INSTANCE = new BillPughSingleton();
    }

    public static BillPughSingleton getInstance() {
        return SingletonHelper.INSTANCE;
    }
}
