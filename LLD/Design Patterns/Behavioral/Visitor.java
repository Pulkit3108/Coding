// Visitor Pattern: Visitor pattern is used when we have to perform an operation on a group of similar kind of Objects. With the help of visitor pattern, we can move the operational logic from the objects to another class.
// Use the Visitor pattern when:
// 1. You want to perform an operation on a group of objects.
// 2. You want to avoid putting operational logic in the classes of the objects.
// 3. You want to separate the operational logic from the objects.
// 4. You want to perform an operation on different classes of objects.
// 5. You want to perform multiple operations on different classes of objects.
// Example: A shopping cart where you can add different items (books, clothes, electronics, etc.) and calculate the total cost.

// Element interface
interface ItemElement {
    void accept(ShoppingCartVisitor visitor);
}

// ConcreteElement1: Book
class Book implements ItemElement {
    private int price;
    private String isbnNumber;

    public Book(int price, String isbnNumber) {
        this.price = price;
        this.isbnNumber = isbnNumber;
    }

    public int getPrice() {
        return price;
    }

    public String getIsbnNumber() {
        return isbnNumber;
    }

    @Override
    public void accept(ShoppingCartVisitor visitor) {
        visitor.visit(this);
    }
}

// ConcreteElement2: Fruit
class Fruit implements ItemElement {
    private int pricePerKg;
    private int weight;
    private String name;

    public Fruit(int pricePerKg, int weight, String name) {
        this.pricePerKg = pricePerKg;
        this.weight = weight;
        this.name = name;
    }

    public int getPricePerKg() {
        return pricePerKg;
    }

    public int getWeight() {
        return weight;
    }

    public String getName() {
        return name;
    }

    @Override
    public void accept(ShoppingCartVisitor visitor) {
        visitor.visit(this);
    }
}

// Visitor interface
interface ShoppingCartVisitor {
    void visit(Book book);
    void visit(Fruit fruit);
}

// ConcreteVisitor
class ShoppingCartVisitorImpl implements ShoppingCartVisitor {
    @Override
    public void visit(Book book) {
        int cost = book.getPrice();
        System.out.println("Book ISBN::" + book.getIsbnNumber() + " cost =" + cost);
    }

    @Override
    public void visit(Fruit fruit) {
        int cost = fruit.getPricePerKg() * fruit.getWeight();
        System.out.println(fruit.getName() + " cost = " + cost);
    }
}

// Client
class VisitorPatternExample {
    public static void main(String[] args) {
        ItemElement[] items = new ItemElement[] {
            new Book(20, "1234"),
            new Book(100, "5678"),
            new Fruit(10, 2, "Banana"),
            new Fruit(5, 5, "Apple")
        };

        int total = calculatePrice(items);
        System.out.println("Total Cost = " + total);
    }

    private static int calculatePrice(ItemElement[] items) {
        ShoppingCartVisitor visitor = new ShoppingCartVisitorImpl();
        int sum = 0;
        for (ItemElement item : items) {
            item.accept(visitor);
        }
        return sum;
    }
}