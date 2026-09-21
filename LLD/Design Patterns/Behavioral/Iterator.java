// Iterator Pattern: Provides a way to access the elements of an aggregate object sequentially without exposing its underlying representation.
// Use the Iterator pattern when:
// 1. You want to access the elements of an aggregate object without exposing its underlying representation.
// 2. You want to support multiple traversals of aggregate objects.
// 3. You want to provide a uniform interface for traversing different aggregate structures (that is, to support polymorphic iteration).
// 4. You need to provide a way to access the elements of an aggregate object sequentially without exposing its underlying representation.
// 5. You need to provide multiple types of iterators.
// Example: A collection of books in a library.

import java.util.ArrayList;
import java.util.List;

// Iterator interface
interface Iterator<T> {
    boolean hasNext();
    T next();
}

// Concrete Iterator
class BookIterator implements Iterator<Book> {
    private List<Book> books;
    private int position;

    public BookIterator(List<Book> books) {
        this.books = books;
        this.position = 0;
    }

    @Override
    public boolean hasNext() {
        return position < books.size();
    }

    @Override
    public Book next() {
        return books.get(position++);
    }
}

// Aggregate interface
interface Aggregate<T> {
    Iterator<T> createIterator();
}

// Concrete Aggregate
class BookCollection implements Aggregate<Book> {
    private List<Book> books;

    public BookCollection() {
        books = new ArrayList<>();
    }

    public void addBook(Book book) {
        books.add(book);
    }

    @Override
    public Iterator<Book> createIterator() {
        return new BookIterator(books);
    }
}

// Book class
class Book {
    private String title;

    public Book(String title) {
        this.title = title;
    }

    public String getTitle() {
        return title;
    }
}

// Client
class IteratorPatternExample {
    public static void main(String[] args) {
        BookCollection bookCollection = new BookCollection();
        bookCollection.addBook(new Book("Design Patterns"));
        bookCollection.addBook(new Book("Refactoring"));
        bookCollection.addBook(new Book("Clean Code"));

        Iterator<Book> iterator = bookCollection.createIterator();
        while (iterator.hasNext()) {
            Book book = iterator.next();
            System.out.println("Book: " + book.getTitle());
        }
    }
}