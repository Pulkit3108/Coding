// Bridge Pattern: Decouple an abstraction from its implementation so that the two can vary independently.
// Use the Bridge pattern when:
// 1. You want to decouple an abstraction from its implementation so that the two can vary independently.
// 2. Changes to the abstraction should not affect the implementation and vice versa.
// 3. You want to avoid a permanent binding between an abstraction and its implementation.
// 4. You want to share an implementation among multiple objects and hide the implementation details from the client.
// Example: A drawing application where different shapes can be drawn using different drawing APIs.


// Implementor interface
interface DrawingAPI {
    void drawCircle(double x, double y, double radius);
}

// ConcreteImplementor1
class DrawingAPI1 implements DrawingAPI {
    @Override
    public void drawCircle(double x, double y, double radius) {
        System.out.println("DrawingAPI1: Drawing circle at (" + x + ", " + y + ") with radius " + radius);
    }
}

// ConcreteImplementor2
class DrawingAPI2 implements DrawingAPI {
    @Override
    public void drawCircle(double x, double y, double radius) {
        System.out.println("DrawingAPI2: Drawing circle at (" + x + ", " + y + ") with radius " + radius);
    }
}

// Abstraction
abstract class Shape {
    protected DrawingAPI drawingAPI;

    protected Shape(DrawingAPI drawingAPI) {
        this.drawingAPI = drawingAPI;
    }

    public abstract void draw();
    public abstract void resizeByPercentage(double pct);
}

// RefinedAbstraction
class CircleShape extends Shape {
    private double x, y, radius;

    public CircleShape(double x, double y, double radius, DrawingAPI drawingAPI) {
        super(drawingAPI);
        this.x = x;
        this.y = y;
        this.radius = radius;
    }

    @Override
    public void draw() {
        drawingAPI.drawCircle(x, y, radius);
    }

    @Override
    public void resizeByPercentage(double pct) {
        radius *= (1.0 + pct / 100.0);
    }
}

// Client
class BridgePatternExample {
    public static void main(String[] args) {
        Shape circle1 = new CircleShape(1, 2, 3, new DrawingAPI1());
        Shape circle2 = new CircleShape(5, 7, 11, new DrawingAPI2());

        circle1.draw();
        circle2.draw();

        circle1.resizeByPercentage(50);
        circle1.draw();
    }
}