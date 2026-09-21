// Low-Level Design: ATM Machine System 💰

// This ATM system handles customer banking operations such as authentication, 
// transaction processing, and cash inventory management. It supports multiple 
// transaction types, maintains security, and provides a seamless user experience. 
// The system is designed to handle various states of operation reliably.

// System Rules:

// Setup:
// • The ATM maintains a cash inventory with different denominations.
// • Cards have attributes like card number, PIN, and associated account details.
// • Users must authenticate before accessing their accounts.

// Operation:
// • Users insert their cards and enter their PIN for authentication.
// • The ATM operates in states: idle, has card, select operation, transaction processing.
// • Users can perform operations like cash withdrawal and balance inquiry.
// • Cards are returned after completing operations.

// Safety Features:
// • PIN validation ensures secure authentication.
// • Transactions are validated for accuracy and security.
// • Transaction logs are maintained for auditing.
// • Maintenance mode disables user interaction during servicing.

import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

// =================== Core Entities ===================

/**
 * Represents a user's bank card with card number, PIN, and associated account details.
 */
class Card {
    private String cardNumber;
    private int pin;
    private String accountNumber;

    public Card(String cardNumber, int pin, String accountNumber) {
        this.cardNumber = cardNumber;
        this.pin = pin;
        this.accountNumber = accountNumber;
    }

    // Getters
    public String getCardNumber() {
        return cardNumber;
    }
    
    public String getAccountNumber() {
        return accountNumber;
    }
    
    // Validate entered PIN
    public boolean validatePin(int enteredPin) {
        return this.pin == enteredPin;
    }
}

/**
 * Represents a bank account with an account number and balance.
 */
class Account {
    private String accountNumber;
    private double balance;

    public Account(String accountNumber, double initialBalance) {
        this.accountNumber = accountNumber;
        this.balance = initialBalance;
    }

    // Withdraw money if sufficient funds exist; returns true if successful.
    public boolean withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }

    // Deposit money to the account.
    public void deposit(double amount) {
        balance += amount;
    }

    // Getters
    public double getBalance() {
        return balance;
    }

    public String getAccountNumber() {
        return accountNumber;
    }
}

/**
 * Enumerates different cash denominations available in the ATM.
 */
enum CashType {
    BILL_100(100),
    BILL_50(50),
    BILL_20(20),
    BILL_10(10),
    BILL_5(5),
    BILL_1(1);

    private final int value;

    CashType(int value) {
        this.value = value;
    }

    public int getValue() {
        return value;
    }
}

/**
 * Manages the ATM's cash inventory for all supported denominations.
 */
class ATMInventory {
    private Map<CashType, Integer> cashInventory;

    public ATMInventory() {
        cashInventory = new HashMap<>();
        initializeInventory();
    }

    // Initialize inventory with preset counts.
    private void initializeInventory() {
        cashInventory.put(CashType.BILL_100, 10);
        cashInventory.put(CashType.BILL_50, 10);
        cashInventory.put(CashType.BILL_20, 20);
        cashInventory.put(CashType.BILL_10, 30);
        cashInventory.put(CashType.BILL_5, 20);
        cashInventory.put(CashType.BILL_1, 50);
    }

    // Get total cash amount.
    public int getTotalCash() {
        int total = 0;
        for (Map.Entry<CashType, Integer> entry : cashInventory.entrySet()) {
            total += entry.getKey().getValue() * entry.getValue();
        }
        return total;
    }

    // Check if sufficient cash is available.
    public boolean hasSufficientCash(int amount) {
        return getTotalCash() >= amount;
    }

    /**
     * Dispense cash if possible. Returns a map of denominations to counts dispensed,
     * or null if unable to dispense the exact amount.
     */
    public Map<CashType, Integer> dispenseCash(int amount) {
        if (!hasSufficientCash(amount)) {
            return null;
        }
        Map<CashType, Integer> dispensedCash = new HashMap<>();
        int remainingAmount = amount;
        // Dispense larger denominations first.
        for (CashType cashType : CashType.values()) {
            int available = cashInventory.get(cashType);
            int countNeeded = remainingAmount / cashType.getValue();
            int countToDispense = Math.min(countNeeded, available);
            if (countToDispense > 0) {
                dispensedCash.put(cashType, countToDispense);
                remainingAmount -= countToDispense * cashType.getValue();
                cashInventory.put(cashType, available - countToDispense);
            }
        }
        if (remainingAmount > 0) {
            // Rollback dispensed cash if exact amount cannot be given.
            for (Map.Entry<CashType, Integer> entry : dispensedCash.entrySet()) {
                cashInventory.put(entry.getKey(), cashInventory.get(entry.getKey()) + entry.getValue());
            }
            return null;
        }
        return dispensedCash;
    }

    // Refill cash for maintenance.
    public void addCash(CashType cashType, int count) {
        cashInventory.put(cashType, cashInventory.get(cashType) + count);
    }
}

// =================== State Pattern for ATM States ===================

/**
 * ATMState interface defines the contract for different ATM states.
 */
interface ATMState {
    String getStateName();
    ATMState next(ATMMachineContext context);
}

/**
 * IdleState: ATM awaits card insertion.
 */
class IdleState implements ATMState {
    public IdleState() {
        System.out.println("ATM is Idle: Please insert your card.");
    }

    @Override
    public String getStateName() {
        return "IdleState";
    }

    @Override
    public ATMState next(ATMMachineContext context) {
        if (context.getCurrentCard() != null) {
            return context.getStateFactory().createHasCardState();
        }
        return this;
    }
}

/**
 * HasCardState: Card inserted; user must enter PIN.
 */
class HasCardState implements ATMState {
    public HasCardState() {
        System.out.println("Card detected. Please enter your PIN.");
    }
    @Override
    public String getStateName() {
        return "HasCardState";
    }
    @Override
    public ATMState next(ATMMachineContext context) {
        if (context.getCurrentCard() == null) {
            return context.getStateFactory().createIdleState();
        }
        if (context.getCurrentAccount() != null) {
            return context.getStateFactory().createSelectOperationState();
        }
        return this;
    }
}

/**
 * SelectOperationState: User selects a transaction type.
 */
class SelectOperationState implements ATMState {
    public SelectOperationState() {
        System.out.println("Select operation: 1. Withdraw Cash   2. Check Balance");
    }
    @Override
    public String getStateName() {
        return "SelectOperationState";
    }
    @Override
    public ATMState next(ATMMachineContext context) {
        if (context.getCurrentCard() == null) {
            return context.getStateFactory().createIdleState();
        }
        if (context.getSelectedOperation() != null) {
            return context.getStateFactory().createTransactionState();
        }
        return this;
    }
}

/**
 * TransactionState: Processes the selected transaction.
 */
class TransactionState implements ATMState {
    public TransactionState() {
        System.out.println("Processing transaction...");
    }
    @Override
    public String getStateName() {
        return "TransactionState";
    }
    @Override
    public ATMState next(ATMMachineContext context) {
        // After completing, return to select operation.
        return context.getStateFactory().createSelectOperationState();
    }
}

/**
 * ATMStateFactory: Singleton factory to create ATMState instances.
 */
class ATMStateFactory {
    private static ATMStateFactory instance = null;
    private ATMStateFactory() {}

    public static ATMStateFactory getInstance() {
        if (instance == null) {
            instance = new ATMStateFactory();
        }
        return instance;
    }
    public ATMState createIdleState() {
        return new IdleState();
    }
    public ATMState createHasCardState() {
        return new HasCardState();
    }
    public ATMState createSelectOperationState() {
        return new SelectOperationState();
    }
    public ATMState createTransactionState() {
        return new TransactionState();
    }
}

/**
 * TransactionType: Enumerates available ATM operations.
 */
enum TransactionType {
    WITHDRAW_CASH,
    CHECK_BALANCE
}

// =================== ATM Machine Context (Core Controller) ===================

/**
 * ATMMachineContext: Central controller managing ATM operations and state transitions.
 */
class ATMMachineContext {
    private ATMState currentState;
    private Card currentCard;
    private Account currentAccount;
    private ATMInventory atmInventory;
    private Map<String, Account> accounts;  // Simple in-memory account store.
    private ATMStateFactory stateFactory;
    private TransactionType selectedOperation;

    public ATMMachineContext() {
        stateFactory = ATMStateFactory.getInstance();
        currentState = stateFactory.createIdleState();
        atmInventory = new ATMInventory();
        accounts = new HashMap<>();
        System.out.println("ATM initialized in state: " + currentState.getStateName());
    }

    // Advance to next state based on current state logic.
    public void advanceState() {
        currentState = currentState.next(this);
        System.out.println("ATM State changed to: " + currentState.getStateName());
    }

    // Insert a card – allowed only in IdleState.
    public void insertCard(Card card) {
        if (currentState instanceof IdleState) {
            System.out.println("Card inserted.");
            currentCard = card;
            advanceState();
        } else {
            System.out.println("Cannot insert card in current state: " + currentState.getStateName());
        }
    }

    // Enter PIN for authentication.
    public void enterPin(int pin) {
        if (currentState instanceof HasCardState) {
            if (currentCard.validatePin(pin)) {
                System.out.println("PIN validated successfully.");
                currentAccount = accounts.get(currentCard.getAccountNumber());
                advanceState();
            } else {
                System.out.println("Invalid PIN. Please try again.");
            }
        } else {
            System.out.println("PIN entry not allowed in state: " + currentState.getStateName());
        }
    }

    // User selects a transaction type.
    public void selectOperation(TransactionType transactionType) {
        if (currentState instanceof SelectOperationState) {
            System.out.println("Operation selected: " + transactionType);
            selectedOperation = transactionType;
            advanceState();
        } else {
            System.out.println("Operation selection not allowed in state: " + currentState.getStateName());
        }
    }

    // Perform the chosen transaction.
    public void performTransaction(double amount) {
        if (currentState instanceof TransactionState) {
            try {
                if (selectedOperation == TransactionType.WITHDRAW_CASH) {
                    performWithdrawal(amount);
                } else if (selectedOperation == TransactionType.CHECK_BALANCE) {
                    checkBalance();
                }
                advanceState();
            } catch (Exception e) {
                System.out.println("Transaction error: " + e.getMessage());
                currentState = stateFactory.createSelectOperationState();
            }
        } else {
            System.out.println("Cannot perform transaction in state: " + currentState.getStateName());
        }
    }

    // Return the card to the user and reset the ATM.
    public void returnCard() {
        if (currentState instanceof HasCardState || currentState instanceof SelectOperationState || currentState instanceof TransactionState) {
            System.out.println("Card returned. Thank you!");
            resetATM();
        } else {
            System.out.println("No card to return in state: " + currentState.getStateName());
        }
    }

    // Cancel the transaction.
    public void cancelTransaction() {
        System.out.println("Transaction cancelled.");
        returnCard();
    }

    // Helper: Process cash withdrawal.
    private void performWithdrawal(double amount) throws Exception {
        if (!currentAccount.withdraw(amount)) {
            throw new Exception("Insufficient funds in account.");
        }
        if (!atmInventory.hasSufficientCash((int) amount)) {
            currentAccount.deposit(amount);  // rollback
            throw new Exception("ATM has insufficient cash.");
        }
        Map<CashType, Integer> dispensed = atmInventory.dispenseCash((int) amount);
        if (dispensed == null) {
            currentAccount.deposit(amount);  // rollback
            throw new Exception("Cannot dispense the exact amount.");
        }
        System.out.println("Please collect your cash:");
        for (Map.Entry<CashType, Integer> entry : dispensed.entrySet()) {
            System.out.println(entry.getValue() + " x $" + entry.getKey().getValue());
        }
    }

    // Helper: Check account balance.
    private void checkBalance() {
        System.out.println("Your current balance is: $" + currentAccount.getBalance());
    }

    // Reset ATM context to Idle state.
    private void resetATM() {
        currentCard = null;
        currentAccount = null;
        selectedOperation = null;
        currentState = stateFactory.createIdleState();
    }

    // Methods to manage accounts (for demo purposes).
    public void addAccount(Account account) {
        accounts.put(account.getAccountNumber(), account);
    }
    
    // Getters
    public ATMState getCurrentState() {
        return currentState;
    }
    public Card getCurrentCard() {
        return currentCard;
    }
    public Account getCurrentAccount() {
        return currentAccount;
    }
    public ATMInventory getATMInventory() {
        return atmInventory;
    }
    public TransactionType getSelectedOperation() {
        return selectedOperation;
    }
    public ATMStateFactory getStateFactory() {
        return stateFactory;
    }
}

// =================== Main Method / Client Code ===================

/**
 * ATMDemo: Demonstrates a sample ATM workflow.
 */
class ATMDemo {
    public static void main(String[] args) {
        ATMMachineContext atm = new ATMMachineContext();
        
        // Add sample accounts.
        atm.addAccount(new Account("123456", 1000.0));
        atm.addAccount(new Account("654321", 500.0));
        
        try {
            System.out.println("=== ATM Demo Starting ===");
            
            // Insert card.
            atm.insertCard(new Card("123456", 1234, "123456"));
            
            // Authenticate.
            atm.enterPin(1234);
            
            // Select withdrawal.
            atm.selectOperation(TransactionType.WITHDRAW_CASH);
            atm.performTransaction(100.0);
            
            // Select balance check.
            atm.selectOperation(TransactionType.CHECK_BALANCE);
            atm.performTransaction(0.0);
            
            // Return card.
            atm.returnCard();
            
            System.out.println("=== ATM Demo Completed ===");
        } catch (Exception e) {
            System.out.println("Error occurred: " + e.getMessage());
        }
    }
}
