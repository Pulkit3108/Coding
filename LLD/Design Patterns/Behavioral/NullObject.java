// Null Object Pattern: Provide an object as a surrogate for the absence of an object of a given type. 
// Use the Null Object pattern when:
// 1. You want to avoid null checks and simplify code.
// 2. You want to provide a default behavior in case an object is not available.
// 3. You want to encapsulate the absence of an object by providing a neutral object with default behavior.
// Example: A customer management system where a null customer object is replaced with a NullCustomer object that provides default behavior.


// Abstract class or interface
abstract class AbstractCustomer {
    protected String name;

    public abstract boolean isNil();
    public abstract String getName();
}

// Real object
class RealCustomer extends AbstractCustomer {
    public RealCustomer(String name) {
        this.name = name;
    }

    @Override
    public boolean isNil() {
        return false;
    }

    @Override
    public String getName() {
        return name;
    }
}

// Null object
class NullCustomer extends AbstractCustomer {
    @Override
    public boolean isNil() {
        return true;
    }

    @Override
    public String getName() {
        return "Not Available";
    }
}

// Factory class to get customer objects
class CustomerFactory {
    public static final String[] names = {"Rob", "Joe", "Julie"};

    public static AbstractCustomer getCustomer(String name) {
        for (String n : names) {
            if (n.equalsIgnoreCase(name)) {
                return new RealCustomer(name);
            }
        }
        return new NullCustomer();
    }
}

// Client
class NullObjectPatternExample {
    public static void main(String[] args) {
        AbstractCustomer customer1 = CustomerFactory.getCustomer("Rob");
        AbstractCustomer customer2 = CustomerFactory.getCustomer("Bob");
        AbstractCustomer customer3 = CustomerFactory.getCustomer("Julie");
        AbstractCustomer customer4 = CustomerFactory.getCustomer("Laura");

        System.out.println("Customers:");
        System.out.println(customer1.getName());
        System.out.println(customer2.getName());
        System.out.println(customer3.getName());
        System.out.println(customer4.getName());
    }
}