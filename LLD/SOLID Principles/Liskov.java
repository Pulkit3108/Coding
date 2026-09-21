// Liskov Substitution Principle: Objects of a superclass should be replaceable with objects of its subclasses without affecting the behavior of the program.
// Use the Liskov Substitution Principle when:
// 1. You want to ensure that subclasses can be used interchangeably with their superclass without altering the correctness of the program.
// 2. You want to promote code reusability and polymorphism.


// Superclass
class Bird {
    public void fly() {
        System.out.println("Bird is flying");
    }
}

// Subclass that adheres to LSP
class Sparrow extends Bird {
    @Override
    public void fly() {
        System.out.println("Sparrow is flying");
    }
}

// Subclass that violates LSP
class Ostrich extends Bird {
    @Override
    public void fly() {
        throw new UnsupportedOperationException("Ostrich can't fly");
    }
}

// Client
class LiskovSubstitutionPrincipleExample {
    public static void main(String[] args) {
        Bird sparrow = new Sparrow();
        Bird ostrich = new Ostrich();

        makeBirdFly(sparrow);
        makeBirdFly(ostrich); // This will throw an exception, violating LSP
    }

    public static void makeBirdFly(Bird bird) {
        bird.fly();
    }
}