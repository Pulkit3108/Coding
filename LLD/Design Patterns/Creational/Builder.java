// Builder Pattern: Separate the construction of a complex object from its representation so that the same construction process can create different representations.
// Use the Builder pattern when:
// 1. The algorithm for creating a complex object should be independent of the parts that make up the object and how they're assembled.
// 2. The construction process must allow different representations for the object that's constructed.
// 3. The construction process must be controlled by a director.
// 4. The construction process should be able to construct different representations of the object using the same construction code.
// 5. You want to construct an object in a step-by-step manner.
// 6. The construction process should be agnostic of the final product form.
// Example: A car can be built in different ways. A car can have a manual or automatic transmission, a sunroof or not, and so on. The car can be built in a step-by-step manner. 

// Product
class Product {
    private String partA;
    private String partB;
    private String partC;

    public void setPartA(String partA) {
        this.partA = partA;
    }

    public void setPartB(String partB) {
        this.partB = partB;
    }

    public void setPartC(String partC) {
        this.partC = partC;
    }

    @Override
    public String toString() {
        return "Product [partA=" + partA + ", partB=" + partB + ", partC=" + partC + "]";
    }
}

// Builder
abstract class Builder {
    protected Product product = new Product();

    public abstract void buildPartA();
    public abstract void buildPartB();
    public abstract void buildPartC();

    public Product getResult() {
        return product;
    }
}

// ConcreteBuilder1
class ConcreteBuilder1 extends Builder {
    @Override
    public void buildPartA() {
        product.setPartA("PartA1");
    }

    @Override
    public void buildPartB() {
        product.setPartB("PartB1");
    }

    @Override
    public void buildPartC() {
        product.setPartC("PartC1");
    }
}

// ConcreteBuilder2
class ConcreteBuilder2 extends Builder {
    @Override
    public void buildPartA() {
        product.setPartA("PartA2");
    }

    @Override
    public void buildPartB() {
        product.setPartB("PartB2");
    }

    @Override
    public void buildPartC() {
        product.setPartC("PartC2");
    }
}

// Director
class Director {
    private Builder builder;

    public void setBuilder(Builder builder) {
        this.builder = builder;
    }

    public Product construct() {
        builder.buildPartA();
        builder.buildPartB();
        builder.buildPartC();
        return builder.getResult();
    }
}

// Client
class BuilderExample {
    public static void main(String[] args) {
        Director director = new Director();

        Builder builder1 = new ConcreteBuilder1();
        director.setBuilder(builder1);
        Product product1 = director.construct();
        System.out.println(product1);

        Builder builder2 = new ConcreteBuilder2();
        director.setBuilder(builder2);
        Product product2 = director.construct();
        System.out.println(product2);
    }
}