// Low-Level Design: Inventory Management System 🏗️

// An inventory management system is designed to efficiently track, manage, and optimize product inventory within a business. 
// The system handles multiple warehouses, tracks stock levels, processes orders, and ensures timely replenishment. 
// It accommodates different product types, supports various inventory operations, and provides accurate reporting.

// Rules of the System:
// Setup:
// • The business has multiple warehouses and can store multiple product types.
// • Products can be added, removed, or transferred between warehouses.
// • Each product has attributes like SKU (Stock Keeping Unit - Unique ID), name, price, quantity, and threshold.
// • The system tracks inventory levels and triggers alerts for low stock.

// Operations:
// • Users can add, remove, or transfer products between warehouses.
// • Stock levels are updated when products are received or shipped.
// • The system generates reports on inventory status and movement.
// • Inventory can be searched and filtered based on various criteria.

// Safety Features:
// • Threshold alerts prevent stockouts.
// • Audit trails track all inventory changes.
// • Access control limits who can perform different inventory operations.

import java.util.*;
import java.util.concurrent.ConcurrentHashMap;

// Enum for Product Categories
enum ProductCategory {
    ELECTRONICS, CLOTHING, GROCERY
}

// Abstract Product class
abstract class Product {
    private final String sku;
    private final String name;
    private final double price;
    private int quantity;
    private final int threshold;
    private final ProductCategory category;

    public Product(String sku, String name, double price, int quantity, int threshold, ProductCategory category) {
        this.sku = sku;
        this.name = name;
        this.price = price;
        this.quantity = quantity;
        this.threshold = threshold;
        this.category = category;
    }

    // Getters
    public String getSku() { return sku; }
    public String getName() { return name; }
    public double getPrice() { return price; }
    public int getQuantity() { return quantity; }
    public int getThreshold() { return threshold; }
    public ProductCategory getCategory() { return category; }

    // Thread-safe stock operations
    public synchronized void addStock(int quantity) { this.quantity += quantity; }
    public synchronized void removeStock(int quantity) { this.quantity -= quantity; }
}

// Concrete Product classes
class ElectronicsProduct extends Product {
    private final String brand;
    private final int warrantyPeriod;

    public ElectronicsProduct(String sku, String name, double price, int quantity, int threshold, String brand, int warrantyPeriod) {
        super(sku, name, price, quantity, threshold, ProductCategory.ELECTRONICS);
        this.brand = brand;
        this.warrantyPeriod = warrantyPeriod;
    }

    // Getters
    public String getBrand() { return brand; }
    public int getWarrantyPeriod() { return warrantyPeriod; }
}

class ClothingProduct extends Product {
    private final String size;
    private final String material;

    public ClothingProduct(String sku, String name, double price, int quantity, int threshold, String size, String material) {
        super(sku, name, price, quantity, threshold, ProductCategory.CLOTHING);
        this.size = size;
        this.material = material;
    }

    // Getters
    public String getSize() { return size; }
    public String getMaterial() { return material; }
}

class GroceryProduct extends Product {
    private final Date expiryDate;

    public GroceryProduct(String sku, String name, double price, int quantity, int threshold, Date expiryDate) {
        super(sku, name, price, quantity, threshold, ProductCategory.GROCERY);
        this.expiryDate = expiryDate;
    }

    // Getter
    public Date getExpiryDate() { return expiryDate; }
}

// Product Factory class
class ProductFactory {
    public Product createProduct(ProductCategory category, String sku, String name, double price, int quantity, int threshold, Object... additionalParams) {
        switch (category) {
            case ELECTRONICS:
                return new ElectronicsProduct(sku, name, price, quantity, threshold, (String) additionalParams[0], (int) additionalParams[1]);
            case CLOTHING:
                return new ClothingProduct(sku, name, price, quantity, threshold, (String) additionalParams[0], (String) additionalParams[1]);
            case GROCERY:
                return new GroceryProduct(sku, name, price, quantity, threshold, (Date) additionalParams[0]);
            default:
                throw new IllegalArgumentException("Unsupported product category: " + category);
        }
    }
}

// Warehouse class
class Warehouse {
    private final int id;
    private final String name;
    private final String location;
    private final Map<String, Product> products;

    public Warehouse(int id, String name, String location) {
        this.id = id;
        this.name = name;
        this.location = location;
        this.products = new ConcurrentHashMap<>();
    }

    public synchronized void addProduct(Product product, int quantity) {
        products.putIfAbsent(product.getSku(), product);
        products.get(product.getSku()).addStock(quantity);
    }

    public synchronized boolean removeProduct(String sku, int quantity) {
        Product product = products.get(sku);
        if (product != null && product.getQuantity() >= quantity) {
            product.removeStock(quantity);
            if (product.getQuantity() == 0) products.remove(sku);
            return true;
        }
        return false;
    }

    public int getAvailableQuantity(String sku) {
        Product product = products.get(sku);
        return product != null ? product.getQuantity() : 0;
    }

    public Collection<Product> getAllProducts() {
        return products.values();
    }
}

// Observer interface for inventory alerts
interface InventoryObserver {
    void update(Product product);
}

// Concrete observer: Notifies suppliers
class SupplierNotifier implements InventoryObserver {
    private final String supplierName;
    private final String contactEmail;

    public SupplierNotifier(String supplierName, String contactEmail) {
        this.supplierName = supplierName;
        this.contactEmail = contactEmail;
    }

    @Override
    public void update(Product product) {
        System.out.println("Notifying supplier " + supplierName + " at " + contactEmail +
                " about low stock for product: " + product.getName());
    }
}

// Concrete observer: Sends alerts to admin dashboard
class DashboardAlertSystem implements InventoryObserver {
    private final String alertLevel;
    private final List<String> adminUsers;

    public DashboardAlertSystem(String alertLevel, List<String> adminUsers) {
        this.alertLevel = alertLevel;
        this.adminUsers = adminUsers;
    }

    @Override
    public void update(Product product) {
        System.out.println("Sending " + alertLevel + " alert to admins: " + adminUsers +
                " for low stock of product: " + product.getName());
    }
}

// Inventory Manager (Singleton) with observer support
class InventoryManager {
    private static InventoryManager instance;
    private final List<Warehouse> warehouses;
    private final ProductFactory productFactory;
    private ReplenishmentStrategy replenishmentStrategy;
    private final List<InventoryObserver> observers;

    private InventoryManager() {
        warehouses = Collections.synchronizedList(new ArrayList<>());
        productFactory = new ProductFactory();
        observers = new ArrayList<>();
    }

    public static synchronized InventoryManager getInstance() {
        if (instance == null) instance = new InventoryManager();
        return instance;
    }

    public void setReplenishmentStrategy(ReplenishmentStrategy strategy) {
        this.replenishmentStrategy = strategy;
    }

    public void addWarehouse(Warehouse warehouse) {
        warehouses.add(warehouse);
    }

    public void addObserver(InventoryObserver observer) {
        observers.add(observer);
    }

    public void removeObserver(InventoryObserver observer) {
        observers.remove(observer);
    }

    private void notifyObservers(Product product) {
        for (InventoryObserver observer : observers) {
            observer.update(product);
        }
    }

    public Product getProductBySku(String sku) {
        synchronized (warehouses) {
            for (Warehouse warehouse : warehouses) {
                Product product = warehouse.getAllProducts().stream()
                        .filter(p -> p.getSku().equals(sku))
                        .findFirst()
                        .orElse(null);
                if (product != null) return product;
            }
        }
        return null;
    }

    public void checkAndReplenish(String sku) {
        Product product = getProductBySku(sku);
        if (product != null && product.getQuantity() < product.getThreshold()) {
            notifyObservers(product); // Notify observers about low stock
            if (replenishmentStrategy != null) {
                replenishmentStrategy.replenish(product);
            }
        }
    }
}

// Replenishment Strategy Interface
interface ReplenishmentStrategy {
    void replenish(Product product);
}

class JustInTimeStrategy implements ReplenishmentStrategy {
    @Override
    public void replenish(Product product) {
        System.out.println("Replenishing " + product.getName() + " using Just-In-Time strategy.");
    }
}

class BulkOrderStrategy implements ReplenishmentStrategy {
    @Override
    public void replenish(Product product) {
        System.out.println("Replenishing " + product.getName() + " using Bulk Order strategy.");
    }
}

// Main class
class Inventory {
    public static void main(String[] args) {
        InventoryManager manager = InventoryManager.getInstance();
        Warehouse warehouse = new Warehouse(1, "Main Warehouse", "New York");
        manager.addWarehouse(warehouse);

        ProductFactory factory = new ProductFactory();
        Product laptop = factory.createProduct(ProductCategory.ELECTRONICS, "SKU123", "Laptop", 1000.0, 10, 5, "BrandX", 24);
        warehouse.addProduct(laptop, 10);

        // Add observers
        manager.addObserver(new SupplierNotifier("TechSupplier", "supplier@tech.com"));
        manager.addObserver(new DashboardAlertSystem("HIGH", Arrays.asList("admin1@company.com", "admin2@company.com")));

        manager.setReplenishmentStrategy(new JustInTimeStrategy());
        manager.checkAndReplenish("SKU123");
    }
}