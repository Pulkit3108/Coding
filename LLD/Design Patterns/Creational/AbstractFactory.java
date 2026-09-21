// Abstract Factory Pattern: Provide an interface for creating families of related or dependent objects without specifying their concrete classes.
// Use the Abstract Factory pattern when:
// 1. A system should be independent of how its products are created, composed, and represented.
// 2. A system should be configured with multiple families of products.
// 3. A family of related product objects is designed to be used together, and you need to enforce this constraint.
// 4. You want to provide a class library of products, and you want to reveal just their interfaces, not their implementations.
// 5. The lifetime of the dependency is conceptually shorter than the lifetime of the dependent.
// 6. You need a run-time value to construct a particular dependency.
// Example: Dark and Light themes for an application. Each theme has a button and a dialog box. The button and dialog box of a theme should be consistent with each other.

// AbstractProductA
interface AbstractProductA {
    void operationA();
}

// AbstractProductB
interface AbstractProductB {
    void operationB();
}

// ConcreteProductA1
class ConcreteProductA1 implements AbstractProductA {
    @Override
    public void operationA() {
        System.out.println("Operation A1");
    }
}

// ConcreteProductA2
class ConcreteProductA2 implements AbstractProductA {
    @Override
    public void operationA() {
        System.out.println("Operation A2");
    }
}

// ConcreteProductB1
class ConcreteProductB1 implements AbstractProductB {
    @Override
    public void operationB() {
        System.out.println("Operation B1");
    }
}

// ConcreteProductB2
class ConcreteProductB2 implements AbstractProductB {
    @Override
    public void operationB() {
        System.out.println("Operation B2");
    }
}

// AbstractFactory
interface AbstractFactory {
    AbstractProductA createProductA();
    AbstractProductB createProductB();
}

// ConcreteFactory1
class ConcreteFactory1 implements AbstractFactory {
    @Override
    public AbstractProductA createProductA() {
        return new ConcreteProductA1();
    }

    @Override
    public AbstractProductB createProductB() {
        return new ConcreteProductB1();
    }
}

// ConcreteFactory2
class ConcreteFactory2 implements AbstractFactory {
    @Override
    public AbstractProductA createProductA() {
        return new ConcreteProductA2();
    }

    @Override
    public AbstractProductB createProductB() {
        return new ConcreteProductB2();
    }
}

// Client
class AbstractFactoryExample {
    private AbstractProductA productA;
    private AbstractProductB productB;

    public AbstractFactoryExample(AbstractFactory factory) {
        productA = factory.createProductA();
        productB = factory.createProductB();
    }

    public void run() {
        productA.operationA();
        productB.operationB();
    }

    public static void main(String[] args) {
        AbstractFactory factory1 = new ConcreteFactory1();
        AbstractFactoryExample example1 = new AbstractFactoryExample(factory1);
        example1.run();

        AbstractFactory factory2 = new ConcreteFactory2();
        AbstractFactoryExample example2 = new AbstractFactoryExample(factory2);
        example2.run();
    }
}