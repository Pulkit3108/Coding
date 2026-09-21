// Low-Level Design: Vending Machine System 🥤

// A vending machine system is designed to manage product inventory, handle customer selections, process payments, and dispense products. 
// The system supports multiple product types, manages inventory availability, handles various payment methods, and ensures a seamless purchase experience. 
// It is reliable, handles different machine states, and supports secure payment strategies.

// Features of the System:

// Setup:
// • The vending machine has an inventory of products (e.g., beverages, snacks).
// • Products have attributes like ID, name, price, and quantity.
// • The system tracks product availability and manages inventory.

// Operation:
// • Users can browse available products and select items to purchase.
// • The vending machine has states: idle, item selected, payment pending, dispensing, and maintenance.
// • The system accepts multiple payment methods (cash, credit card, mobile payment).
// • Once payment is confirmed, the machine dispenses the selected product and returns change if applicable.

// Safety Features:
// • Prevents dispensing when products are out of stock.
// • Ensures secure payment validation.
// • Tracks all purchases and inventory changes via audit trails.
// • Maintenance mode disables user interaction during servicing.

import java.util.*;

// Enum representing different types of items in the vending machine
enum ItemType {
    COKE, PEPSI, JUICE, SODA
}

// Class representing an item in the vending machine
class Item {
    private final ItemType type;
    private final int price;

    public Item(ItemType type, int price) {
        this.type = type;
        this.price = price;
    }

    public ItemType getType() {
        return type;
    }

    public int getPrice() {
        return price;
    }
}

// Class representing a slot in the vending machine that holds multiple items
class ItemShelf {
    private final int code;
    private final Queue<Item> items;

    public ItemShelf(int code) {
        this.code = code;
        this.items = new LinkedList<>();
    }

    public int getCode() {
        return code;
    }

    public boolean isSoldOut() {
        return items.isEmpty();
    }

    public void addItem(Item item) {
        items.add(item);
    }

    public Item removeItem() throws Exception {
        if (isSoldOut()) {
            throw new Exception("Item is sold out");
        }
        return items.poll();
    }

    public Item peekItem() {
        return items.peek();
    }
}

// Enum representing different denominations of coins
enum Coin {
    ONE_RUPEE(1), TWO_RUPEES(2), FIVE_RUPEES(5), TEN_RUPEES(10);

    private final int value;

    Coin(int value) {
        this.value = value;
    }

    public int getValue() {
        return value;
    }
}

// Class representing the inventory of the vending machine
class Inventory {
    private final Map<Integer, ItemShelf> shelves;

    public Inventory(int shelfCount) {
        shelves = new HashMap<>();
        for (int i = 0; i < shelfCount; i++) {
            shelves.put(101 + i, new ItemShelf(101 + i));
        }
    }

    public ItemShelf getShelf(int code) throws Exception {
        if (!shelves.containsKey(code)) {
            throw new Exception("Invalid shelf code");
        }
        return shelves.get(code);
    }

    public void addItem(int code, Item item) throws Exception {
        getShelf(code).addItem(item);
    }

    public Item removeItem(int code) throws Exception {
        return getShelf(code).removeItem();
    }

    public boolean hasItems() {
        return shelves.values().stream().anyMatch(shelf -> !shelf.isSoldOut());
    }
}

// Interface defining the common methods for all states
interface VendingMachineState {
    void handle(VendingMachineContext context);
}

// Context class that maintains state and handles transitions in the vending machine
class VendingMachineContext {
    private VendingMachineState currentState;
    private final Inventory inventory;
    private final List<Coin> insertedCoins;
    private int selectedItemCode;

    public VendingMachineContext(int shelfCount) {
        this.inventory = new Inventory(shelfCount);
        this.insertedCoins = new ArrayList<>();
        this.currentState = new IdleState();
    }

    public void setState(VendingMachineState state) {
        this.currentState = state;
    }

    public void insertCoin(Coin coin) {
        insertedCoins.add(coin);
        currentState.handle(this);
    }

    public void selectItem(int code) {
        this.selectedItemCode = code;
        currentState.handle(this);
    }

    public void dispenseItem() {
        currentState.handle(this);
    }

    public int getTotalInsertedAmount() {
        return insertedCoins.stream().mapToInt(Coin::getValue).sum();
    }

    public void reset() {
        insertedCoins.clear();
        selectedItemCode = 0;
        setState(new IdleState());
    }

    public Inventory getInventory() {
        return inventory;
    }

    public int getSelectedItemCode() {
        return selectedItemCode;
    }

    public VendingMachineState getCurrentState() {
        return currentState;
    }

    public List<Coin> getInsertedCoins() {
        return insertedCoins;
    }

    public void setSelectedItemCode(int selectedItemCode) {
        this.selectedItemCode = selectedItemCode;
    }
}

// Implementation of the Idle state
class IdleState implements VendingMachineState {
    @Override
    public void handle(VendingMachineContext context) {
        if (context.getTotalInsertedAmount() > 0) {
            context.setState(new HasMoneyState());
        }
    }
}

// Implementation of the Has Money state
class HasMoneyState implements VendingMachineState {
    @Override
    public void handle(VendingMachineContext context) {
        if (context.getSelectedItemCode() > 0) {
            context.setState(new SelectionState());
        }
    }
}

// Implementation of the Dispense state
class DispenseState implements VendingMachineState {
    @Override
    public void handle(VendingMachineContext context) {
        try {
            ItemShelf shelf = context.getInventory().getShelf(context.getSelectedItemCode());
            Item item = shelf.removeItem(); // Remove the item from the shelf
            int change = context.getTotalInsertedAmount() - item.getPrice();
            System.out.println("Dispensing: " + item.getType());
            if (change > 0) {
                System.out.println("Returning change: " + change);
            }
            context.reset();
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
            context.reset();
        }
    }
}

// Implementation of the Out of Stock state
class OutOfStockState implements VendingMachineState {
    @Override
    public void handle(VendingMachineContext context) {
        System.out.println("Selected item is out of stock.");
        context.reset();
    }
}

// Implementation of the Selection state
class SelectionState implements VendingMachineState {
    @Override
    public void handle(VendingMachineContext context) {
        try {
            ItemShelf shelf = context.getInventory().getShelf(context.getSelectedItemCode());
            if (shelf.isSoldOut()) {
                context.setState(new OutOfStockState());
                context.getCurrentState().handle(context); // Transition to OutOfStockState
            } else {
                Item item = shelf.peekItem(); // Use the new getter method
                if (context.getTotalInsertedAmount() >= item.getPrice()) {
                    context.setState(new DispenseState());
                    context.getCurrentState().handle(context); // Transition to DispenseState
                } else {
                    System.out.println("Insufficient funds. Please insert more coins.");
                }
            }
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
            context.reset();
        }
    }
}

// Main class to run the vending machine
class VendingMachine {
    public static void main(String[] args) {
        VendingMachineContext vendingMachine = new VendingMachineContext(10);

        try {
            // Fill inventory
            for (int i = 0; i < 10; i++) {
                ItemType type = i < 3 ? ItemType.COKE : i < 6 ? ItemType.PEPSI : ItemType.JUICE;
                vendingMachine.getInventory().addItem(101 + i, new Item(type, 10 + i));
            }

            // Simulate user actions
            vendingMachine.insertCoin(Coin.TEN_RUPEES);
            vendingMachine.insertCoin(Coin.FIVE_RUPEES);
            vendingMachine.selectItem(101);
            vendingMachine.dispenseItem();
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}