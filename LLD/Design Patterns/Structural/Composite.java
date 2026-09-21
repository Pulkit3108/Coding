// Composite Pattern: Compose objects into tree structures to represent part-whole hierarchies. Composite lets clients treat individual objects and compositions of objects uniformly.
// Use the Composite pattern when:
// 1. You want to represent part-whole hierarchies of objects.
// 2. You want clients to be able to ignore the difference between compositions of objects and individual objects.
// 3. You want to make the client simple by allowing it to treat individual objects and compositions uniformly.
// Example: A file system where files and directories are represented as part-whole hierarchies.

import java.util.ArrayList;
import java.util.List;

// Component
interface FileSystemComponent {
    void showDetails();
}

// Leaf
class File implements FileSystemComponent {
    private String name;

    public File(String name) {
        this.name = name;
    }

    @Override
    public void showDetails() {
        System.out.println("File: " + name);
    }
}

// Composite
class Directory implements FileSystemComponent {
    private String name;
    private List<FileSystemComponent> components = new ArrayList<>();

    public Directory(String name) {
        this.name = name;
    }

    public void addComponent(FileSystemComponent component) {
        components.add(component);
    }

    public void removeComponent(FileSystemComponent component) {
        components.remove(component);
    }

    @Override
    public void showDetails() {
        System.out.println("Directory: " + name);
        for (FileSystemComponent component : components) {
            component.showDetails();
        }
    }
}

// Client
class CompositePatternExample {
    public static void main(String[] args) {
        FileSystemComponent file1 = new File("file1.txt");
        FileSystemComponent file2 = new File("file2.txt");
        FileSystemComponent file3 = new File("file3.txt");

        Directory directory1 = new Directory("dir1");
        Directory directory2 = new Directory("dir2");

        directory1.addComponent(file1);
        directory1.addComponent(file2);

        directory2.addComponent(file3);
        directory2.addComponent(directory1);

        directory2.showDetails();
    }
}