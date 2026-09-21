// Factory Method Pattern: Define an interface for creating an object, but let subclasses decide which class to instantiate. Factory Method lets a class defer instantiation to subclasses.
// Use the Factory Method pattern when:
// 1. A class can't anticipate the class of objects it must create.
// 2. A class wants its subclasses to specify the objects it creates.
// 3. Classes delegate responsibility to one of several helper subclasses, and you want to localize the knowledge of which helper subclass is the delegate.
// 4. You want to localize the knowledge of which class gets created.
// 5. You want to give users of your library or framework a way to extend its internal components.
// 6. You want to promote the idea of coding to an interface, not an implementation.
// Example: An asteroid game where on each level, a different type of asteroid is created. The game should be able to create different types of asteroids without changing the game code.

// Product
interface Product {
    void operation();
}

// ConcreteProductA
class ConcreteProductA implements Product {
    @Override
    public void operation() {
        System.out.println("Operation of ConcreteProductA");
    }
}

// ConcreteProductB
class ConcreteProductB implements Product {
    @Override
    public void operation() {
        System.out.println("Operation of ConcreteProductB");
    }
}

// Creator
abstract class Creator {
    public abstract Product factoryMethod();

    public void someOperation() {
        Product product = factoryMethod();
        product.operation();
    }
}

// ConcreteCreatorA
class ConcreteCreatorA extends Creator {
    @Override
    public Product factoryMethod() {
        return new ConcreteProductA();
    }
}

// ConcreteCreatorB
class ConcreteCreatorB extends Creator {
    @Override
    public Product factoryMethod() {
        return new ConcreteProductB();
    }
}

// Client
class FactoryMethodExample {
    public static void main(String[] args) {
        Creator creatorA = new ConcreteCreatorA();
        creatorA.someOperation();

        Creator creatorB = new ConcreteCreatorB();
        creatorB.someOperation();
    }
}
