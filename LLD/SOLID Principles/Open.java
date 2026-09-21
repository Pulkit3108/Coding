// Open Closed Principle: A class should be open for extension but closed for modification.
// Use the Open Closed Principle when:
// 1. You want to allow the behavior of a class to be extended without modifying its source code.
// 2. You want to promote code reusability and maintainability.


// Base class
abstract class Shape {
    public abstract void draw();
}

// Concrete class 1
class Circle extends Shape {
    @Override
    public void draw() {
        System.out.println("Drawing Circle");
    }
}

// Concrete class 2
class Rectangle extends Shape {
    @Override
    public void draw() {
        System.out.println("Drawing Rectangle");
    }
}

// New concrete class that extends the base class without modifying it
class Triangle extends Shape {
    @Override
    public void draw() {
        System.out.println("Drawing Triangle");
    }
}

// Client
class OpenClosedPrincipleExample {
    public static void main(String[] args) {
        Shape circle = new Circle();
        Shape rectangle = new Rectangle();
        Shape triangle = new Triangle();

        drawShape(circle);
        drawShape(rectangle);
        drawShape(triangle);
    }

    public static void drawShape(Shape shape) {
        shape.draw();
    }
}