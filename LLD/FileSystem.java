// Low-Level Design: File System 📂

// Introduction:
// A File System is a core component of an operating system that organizes, stores, and manages files and directories on storage devices. 
// It provides a hierarchical structure for efficient data storage, retrieval, and manipulation.

// Core Concepts:
// 1. Hierarchical Structure: Files and directories are organized in a tree-like hierarchy.
// 2. File Attributes: Each file has metadata such as name, size, creation time, and permissions.
// 3. Directory Management: Directories can contain files and other directories.
// 4. File Operations: Supports basic operations like create, read, update, and delete (CRUD).
// 5. Path-Based Access: Resources are accessed using string paths like "/documents/report.txt".

import java.time.LocalDateTime;
import java.util.*;

// ----- Base Abstract Class representing a File System Node -----
abstract class FileSystemNode {
    private final String name;
    private final Map<String, FileSystemNode> children;
    private final LocalDateTime createdAt;
    private LocalDateTime modifiedAt;

    public FileSystemNode(String name) {
        this.name = name;
        this.children = new HashMap<>();
        this.createdAt = LocalDateTime.now();
        this.modifiedAt = LocalDateTime.now();
    }

    public void addChild(String name, FileSystemNode child) {
        children.put(name, child);
        updateModifiedTime();
    }

    public boolean hasChild(String name) {
        return children.containsKey(name);
    }

    public FileSystemNode getChild(String name) {
        return children.get(name);
    }

    public boolean removeChild(String name) {
        if (children.remove(name) != null) {
            updateModifiedTime();
            return true;
        }
        return false;
    }

    public Collection<FileSystemNode> getChildren() {
        return children.values();
    }

    public String getName() {
        return name;
    }

    public LocalDateTime getCreatedAt() {
        return createdAt;
    }

    public LocalDateTime getModifiedAt() {
        return modifiedAt;
    }

    protected void updateModifiedTime() {
        modifiedAt = LocalDateTime.now();
    }

    public abstract boolean isFile();
    public abstract void display(int depth);
}

// ----- File class representing leaf nodes -----
class File extends FileSystemNode {
    private String content = "";
    private final String extension;

    public File(String name) {
        super(name);
        this.extension = extractExtension(name);
    }

    private String extractExtension(String name) {
        int dotIndex = name.lastIndexOf('.');
        return (dotIndex > 0) ? name.substring(dotIndex + 1) : "";
    }

    public void setContent(String content) {
        this.content = content;
        updateModifiedTime();
    }

    public String getContent() {
        return content;
    }

    public String getExtension() {
        return extension;
    }

    @Override
    public boolean isFile() {
        return true;
    }

    @Override
    public void display(int depth) {
        String indent = " ".repeat(depth * 2);
        System.out.println(indent + "📄 " + getName());
    }
}

// ----- Directory class representing composite nodes -----
class Directory extends FileSystemNode {

    public Directory(String name) {
        super(name);
    }

    @Override
    public boolean isFile() {
        return false;
    }

    @Override
    public void display(int depth) {
        String indent = " ".repeat(depth * 2);
        System.out.println(indent + "📁 " + getName() + " (" + getChildren().size() + " items)");
        for (FileSystemNode child : getChildren()) {
            child.display(depth + 1);
        }
    }
}

// ----- Core FileSystem class using trie-like path mapping -----
class FileSystem {
    private final FileSystemNode root;

    public FileSystem() {
        this.root = new Directory("/");
    }

    public boolean isValidFilePath(String path) {
        return path != null && !path.isEmpty() && path.startsWith("/");
    }

    public boolean createPath(String path) {
        if (!isValidFilePath(path)) return false;

        String[] components = path.split("/");
        FileSystemNode current = root;

        for (int i = 1; i < components.length - 1; i++) {
            String component = components[i].trim();
            if (component.isEmpty()) continue;

            if (!current.hasChild(component)) {
                current.addChild(component, new Directory(component));
            }
            current = current.getChild(component);
            if (current.isFile()) return false;
        }

        String lastComponent = components[components.length - 1].trim();
        if (lastComponent.isEmpty() || current.hasChild(lastComponent)) return false;

        FileSystemNode newNode = lastComponent.contains(".") ? new File(lastComponent) : new Directory(lastComponent);
        current.addChild(lastComponent, newNode);
        return true;
    }

    private FileSystemNode getNode(String path) {
        if (!isValidFilePath(path)) return null;
        if (path.equals("/")) return root;

        String[] components = path.split("/");
        FileSystemNode current = root;

        for (int i = 1; i < components.length; i++) {
            String component = components[i].trim();
            if (component.isEmpty()) continue;

            if (!current.hasChild(component)) return null;
            current = current.getChild(component);
        }
        return current;
    }

    public boolean deletePath(String path) {
        if (!isValidFilePath(path) || path.equals("/")) return false;

        String parentPath = getParentPath(path);
        FileSystemNode parent = getNode(parentPath);
        if (parent == null || parent.isFile()) return false;

        String lastComponent = path.substring(path.lastIndexOf('/') + 1);
        return parent.removeChild(lastComponent);
    }

    private String getParentPath(String path) {
        int lastSlash = path.lastIndexOf('/');
        return (lastSlash <= 0) ? "/" : path.substring(0, lastSlash);
    }

    public void display() {
        root.display(0);
    }

    public boolean setFileContent(String path, String content) {
        FileSystemNode node = getNode(path);
        if (node == null || !node.isFile()) return false;

        ((File) node).setContent(content);
        return true;
    }

    public String getFileContent(String path) {
        FileSystemNode node = getNode(path);
        if (node == null || !node.isFile()) return null;

        return ((File) node).getContent();
    }
}

// ----- Client Code for Testing the File System -----
class FileSystemClient {
    public static void main(String[] args) {
        FileSystem fs = new FileSystem();
        Scanner scanner = new Scanner(System.in);

        System.out.println("File System Manager - Commands:");
        System.out.println("1. create <path>             - Create a new file or directory");
        System.out.println("2. write <path> <content>    - Write content to a file");
        System.out.println("3. read <path>               - Read content from a file");
        System.out.println("4. delete <path>             - Delete a file or directory");
        System.out.println("5. display                   - Show the entire file system structure");
        System.out.println("6. exit                      - Exit the program");

        boolean isRunning = true;
        while (isRunning) {
            System.out.print("\nEnter command: ");
            String input = scanner.nextLine().trim();
            if (input.isEmpty()) continue;

            String[] parts = input.split("\\s+", 3);
            String command = parts[0].toLowerCase();

            switch (command) {
                case "create":
                    if (parts.length >= 2) {
                        boolean created = fs.createPath(parts[1]);
                        System.out.println(created ? "Path created successfully." : "Failed to create path.");
                    } else {
                        System.out.println("Usage: create <path>");
                    }
                    break;
                case "write":
                    if (parts.length >= 3) {
                        boolean written = fs.setFileContent(parts[1], parts[2]);
                        System.out.println(written ? "Content written successfully." : "Failed to write content.");
                    } else {
                        System.out.println("Usage: write <path> <content>");
                    }
                    break;
                case "read":
                    if (parts.length >= 2) {
                        String content = fs.getFileContent(parts[1]);
                        System.out.println(content != null ? "Content: " + content : "Failed to read content.");
                    } else {
                        System.out.println("Usage: read <path>");
                    }
                    break;
                case "delete":
                    if (parts.length >= 2) {
                        boolean deleted = fs.deletePath(parts[1]);
                        System.out.println(deleted ? "Path deleted successfully." : "Failed to delete path.");
                    } else {
                        System.out.println("Usage: delete <path>");
                    }
                    break;
                case "display":
                    System.out.println("\nFile System Structure:");
                    fs.display();
                    break;
                case "exit":
                    isRunning = false;
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Unknown command. Available commands: create, write, read, delete, display, exit");
                    break;
            }
        }
        scanner.close();
    }
}
