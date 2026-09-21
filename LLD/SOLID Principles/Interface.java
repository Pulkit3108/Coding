// Interface Segregation Principle: Clients should not be forced to depend on interfaces they do not use.
// Use the Interface Segregation Principle when:
// 1. You want to avoid forcing clients to implement methods they do not need.
// 2. You want to create smaller, more specific interfaces to improve code maintainability and readability.
// 3. You want to reduce the impact of changes in your code.


// General interface violating ISP
interface Worker {
    void work();
    void eat();
}

// Specific interfaces adhering to ISP
interface Workable {
    void work();
}

interface Eatable {
    void eat();
}

// Concrete class implementing only the Workable interface
class Developer implements Workable {
    @Override
    public void work() {
        System.out.println("Developer is working");
    }
}

// Concrete class implementing both Workable and Eatable interfaces
class OfficeWorker implements Workable, Eatable {
    @Override
    public void work() {
        System.out.println("Office worker is working");
    }

    @Override
    public void eat() {
        System.out.println("Office worker is eating");
    }
}

// Client
class InterfaceSegregationPrincipleExample {
    public static void main(String[] args) {
        Workable developer = new Developer();
        developer.work();

        OfficeWorker officeWorker = new OfficeWorker();
        officeWorker.work();
        officeWorker.eat();
    }
}