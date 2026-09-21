// Strategy Pattern: Define a family of algorithms, encapsulate each one, and make them interchangeable. Strategy lets the algorithm vary independently from clients that use it.
// Use the Strategy pattern when:
// 1. Many related classes differ only in their behavior. Strategies provide a way to configure a class with one of many behaviors.
// 2. You need different variants of an algorithm. For example, you might define algorithms reflecting different space/time trade-offs. Strategies can be used when these variants are implemented as a class hierarchy of algorithms.
// 3. An algorithm uses data that clients shouldn't know about. Use the Strategy pattern to avoid exposing complex, algorithm-specific data structures.
// 4. A class defines many behaviors, and these appear as multiple conditional statements in its operations. Instead of many conditionals, move related conditional branches into their own Strategy class.
// 5. An algorithm has a lot of conditional statements. Instead of many conditionals, move related conditional branches into their own Strategy class.
// Example: A class that can display data in different formats such as HTML, XML, or JSON. The class should be configurable with any of these formats.

// Strategy interface
interface Strategy {
    void execute();
}

// ConcreteStrategyA
class ConcreteStrategyA implements Strategy {
    @Override
    public void execute() {
        System.out.println("Executing Strategy A");
    }
}

// ConcreteStrategyB
class ConcreteStrategyB implements Strategy {
    @Override
    public void execute() {
        System.out.println("Executing Strategy B");
    }
}

// ConcreteStrategyC
class ConcreteStrategyC implements Strategy {
    @Override
    public void execute() {
        System.out.println("Executing Strategy C");
    }
}

// Context
class Context {
    private Strategy strategy;

    public void setStrategy(Strategy strategy) {
        this.strategy = strategy;
    }

    public void executeStrategy() {
        strategy.execute();
    }
}

// Client
class StrategyPatternExample {
    public static void main(String[] args) {
        Context context = new Context();

        // Using Strategy A
        context.setStrategy(new ConcreteStrategyA());
        context.executeStrategy();

        // Using Strategy B
        context.setStrategy(new ConcreteStrategyB());
        context.executeStrategy();

        // Using Strategy C
        context.setStrategy(new ConcreteStrategyC());
        context.executeStrategy();
    }
}