// Prototype Pattern: Specify the kinds of objects to create using a prototypical instance, and create new objects by copying this prototype.
// Use the Prototype pattern when:
// 1. A system should be independent of how its products are created, composed, and represented.
// 2. Instances of a class can have one of only a few different combinations of state.
// 3. The cost of creating a new object is more expensive than copying an existing one.
// 4. You want to avoid subclasses of an object creator in the client application, like the Abstract Factory pattern does.
// 5. You want to avoid the inherent cost of creating a new object in the standard way (e.g., using the `new` keyword).
// Example: A game where the player can save the state of the game and load it later. The game should be able to create a new game state by copying an existing game state.

// Prototype
interface Prototype extends Cloneable {
    Prototype clone();
}

// ConcretePrototype1
class ConcretePrototype1 implements Prototype {
    private String field;

    public ConcretePrototype1(String field) {
        this.field = field;
    }

    @Override
    public Prototype clone() {
        return new ConcretePrototype1(this.field);
    }

    @Override
    public String toString() {
        return "ConcretePrototype1 [field=" + field + "]";
    }
}

// ConcretePrototype2
class ConcretePrototype2 implements Prototype {
    private String field;

    public ConcretePrototype2(String field) {
        this.field = field;
    }

    @Override
    public Prototype clone() {
        return new ConcretePrototype2(this.field);
    }

    @Override
    public String toString() {
        return "ConcretePrototype2 [field=" + field + "]";
    }
}

// Client
class PrototypePatternExample {
    public static void main(String[] args) {
        ConcretePrototype1 prototype1 = new ConcretePrototype1("Prototype1");
        ConcretePrototype2 prototype2 = new ConcretePrototype2("Prototype2");

        Prototype clone1 = prototype1.clone();
        Prototype clone2 = prototype2.clone();

        System.out.println(clone1);
        System.out.println(clone2);
    }
}