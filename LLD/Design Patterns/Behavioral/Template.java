// Template Method Pattern: Defines the program skeleton of an algorithm in a method, called template method, which defers some steps to subclasses. It lets one redefine certain steps of an algorithm without changing the algorithm's structure.
// Use the Template method pattern when:
// 1. You want to let clients extend only particular steps of an algorithm, but not the whole algorithm or its structure.
// 2. You have several classes that contain almost identical algorithms with some minor differences.
// 3. You have a complex algorithm that may benefit from dividing it into smaller, simpler steps.
// 4. You want to let clients override only specific parts of an algorithm, but not the whole algorithm or its structure.
// Example: A template method defines the steps of an algorithm and allows subclasses to provide the implementation for one or more steps.

// AbstractClass
abstract class DataProcessor {
    // Template method
    public final void process() {
        readData();
        processData();
        writeData();
    }

    // Steps to be implemented by subclasses
    protected abstract void readData();
    protected abstract void processData();
    protected abstract void writeData();
}

// ConcreteClass1
class CSVDataProcessor extends DataProcessor {
    @Override
    protected void readData() {
        System.out.println("Reading data from CSV file");
    }

    @Override
    protected void processData() {
        System.out.println("Processing CSV data");
    }

    @Override
    protected void writeData() {
        System.out.println("Writing data to CSV file");
    }
}

// ConcreteClass2
class XMLDataProcessor extends DataProcessor {
    @Override
    protected void readData() {
        System.out.println("Reading data from XML file");
    }

    @Override
    protected void processData() {
        System.out.println("Processing XML data");
    }

    @Override
    protected void writeData() {
        System.out.println("Writing data to XML file");
    }
}

// Client
class TemplateMethodPatternExample {
    public static void main(String[] args) {
        DataProcessor csvProcessor = new CSVDataProcessor();
        csvProcessor.process();

        DataProcessor xmlProcessor = new XMLDataProcessor();
        xmlProcessor.process();
    }
}