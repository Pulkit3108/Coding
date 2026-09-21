// Low-Level Design: Splitwise Expense Sharing System 💰

// A Splitwise-like expense sharing system designed to efficiently track shared expenses among users, calculate balances, and minimize transactions for debt settlement. The system supports multiple users, various expense types, and provides an optimal solution for debt settlement. It is reliable, maintainable, and offers an intuitive interface for expense management and balance calculation.

// Features:
// • Tracks users and their transactions.
// • Supports expense splitting: equally, percentage-based, or custom amounts.
// • Calculates balances and provides simplified settlement plans.
// • Maintains transaction history for auditing purposes.
// • Optimizes debt settlement to minimize transactions.

import java.util.*;

// =================== Core Entities ===================

class User {
    private final String id;
    private final String name;
    private final String email;

    public User(String id, String name, String email) {
        this.id = id;
        this.name = name;
        this.email = email;
    }

    public String getId() { return id; }
    public String getName() { return name; }
    public String getEmail() { return email; }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof User)) return false;
        User user = (User) o;
        return id.equals(user.id);
    }

    @Override
    public int hashCode() {
        return Objects.hash(id);
    }
}

class Expense {
    private final String id;
    private final String description;
    private final double amount;
    private final User payer;
    private final List<User> participants;
    private final Map<User, Double> shares;
    private final Group group;

    public Expense(String id, String description, double amount, User payer, List<User> participants, Map<User, Double> shares, Group group) {
        this.id = id;
        this.description = description;
        this.amount = amount;
        this.payer = payer;
        this.participants = participants;
        this.shares = shares;
        this.group = group;
    }

    public Expense(String id, String description, double amount, User payer, List<User> participants, Map<User, Double> shares) {
        this(id, description, amount, payer, participants, shares, null);
    }

    public String getId() { return id; }
    public String getDescription() { return description; }
    public double getAmount() { return amount; }
    public User getPayer() { return payer; }
    public List<User> getParticipants() { return participants; }
    public Map<User, Double> getShares() { return shares; }
    public Group getGroup() { return group; }
    public boolean isGroupExpense() { return group != null; }
}

class Transaction {
    private final User from;
    private final User to;
    private final double amount;

    public Transaction(User from, User to, double amount) {
        this.from = from;
        this.to = to;
        this.amount = amount;
    }

    public User getFrom() { return from; }
    public User getTo() { return to; }
    public double getAmount() { return amount; }
}

class UserPair {
    private final User debtor;
    private final User creditor;

    public UserPair(User debtor, User creditor) {
        this.debtor = debtor;
        this.creditor = creditor;
    }

    public User getDebtor() { return debtor; }
    public User getCreditor() { return creditor; }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof UserPair)) return false;
        UserPair that = (UserPair) o;
        return debtor.equals(that.debtor) && creditor.equals(that.creditor);
    }

    @Override
    public int hashCode() {
        return Objects.hash(debtor, creditor);
    }
}

// =================== Split Logic (Factory & Strategies) ===================

interface Split {
    Map<User, Double> calculateSplit(double amount, List<User> participants, Map<String, Object> splitDetails);
}

class EqualSplit implements Split {
    @Override
    public Map<User, Double> calculateSplit(double amount, List<User> participants, Map<String, Object> splitDetails) {
        double share = amount / participants.size();
        Map<User, Double> result = new HashMap<>();
        participants.forEach(user -> result.put(user, share));
        return result;
    }
}

class PercentageSplit implements Split {
    @Override
    public Map<User, Double> calculateSplit(double amount, List<User> participants, Map<String, Object> splitDetails) {
        @SuppressWarnings("unchecked")
        Map<User, Double> percentages = (Map<User, Double>) splitDetails.get("percentages");
        Map<User, Double> result = new HashMap<>();
        participants.forEach(user -> result.put(user, amount * percentages.getOrDefault(user, 0.0) / 100.0));
        return result;
    }
}

class SplitFactory {
    public static Split createSplit(String splitType) {
        switch (splitType) {
            case "EQUAL": return new EqualSplit();
            case "PERCENTAGE": return new PercentageSplit();
            default: throw new IllegalArgumentException("Unknown split type: " + splitType);
        }
    }
}

// =================== Observer Pattern for Expense Updates ===================

interface ExpenseObserver {
    void onExpenseAdded(Expense expense);
    void onExpenseUpdated(Expense expense);
}

interface ExpenseSubject {
    void addObserver(ExpenseObserver observer);
    void removeObserver(ExpenseObserver observer);
    void notifyExpenseAdded(Expense expense);
    void notifyExpenseUpdated(Expense expense);
}

class ExpenseManager implements ExpenseSubject {
    private final List<ExpenseObserver> observers = new ArrayList<>();
    private final List<Expense> expenses = new ArrayList<>();

    @Override
    public void addObserver(ExpenseObserver observer) { observers.add(observer); }
    @Override
    public void removeObserver(ExpenseObserver observer) { observers.remove(observer); }
    @Override
    public void notifyExpenseAdded(Expense expense) { observers.forEach(observer -> observer.onExpenseAdded(expense)); }
    @Override
    public void notifyExpenseUpdated(Expense expense) { observers.forEach(observer -> observer.onExpenseUpdated(expense)); }

    public void addExpense(Expense expense) {
        expenses.add(expense);
        notifyExpenseAdded(expense);
    }

    public List<Expense> getAllExpenses() { return new ArrayList<>(expenses); }
}

// =================== Balance Sheet and Settlement Algorithms ===================

/**
 * Maintains and calculates user balances globally and within groups.
 * It listens to expense updates and computes simplified as well as optimal settlements.
 */
class BalanceSheet implements ExpenseObserver {
    // Global balances stored as "UserPair (debtor, creditor)" -> amount owed.
    private final Map<UserPair, Double> balances = new HashMap<>();
    // Group-specific balances mapped by group ID.
    private final Map<String, Map<UserPair, Double>> groupBalances = new HashMap<>();
    private static final double EPSILON = 0.001;

    @Override
    public void onExpenseAdded(Expense expense) {
        updateBalances(expense);
    }

    @Override
    public void onExpenseUpdated(Expense expense) {
        // For simplicity, we add the new expense without reverting the old state.
        updateBalances(expense);
    }

    /**
     * Updates the balance records from a new expense.
     */
    public void updateBalances(Expense expense) {
        User payer = expense.getPayer();
        Map<User, Double> shares = expense.getShares();
        Group group = expense.getGroup();
        String groupId = (group != null) ? group.getId() : null;
        if (groupId != null && !groupBalances.containsKey(groupId)) {
            groupBalances.put(groupId, new HashMap<>());
        }
        // Update balances only for participants other than the payer.
        for (Map.Entry<User, Double> entry : shares.entrySet()) {
            User participant = entry.getKey();
            double shareAmount = entry.getValue();
            if (participant.equals(payer)) continue;
            // Record that participant owes payer.
            UserPair key = new UserPair(participant, payer);
            balances.put(key, balances.getOrDefault(key, 0.0) + shareAmount);
            if (groupId != null) {
                Map<UserPair, Double> groupMap = groupBalances.get(groupId);
                groupMap.put(key, groupMap.getOrDefault(key, 0.0) + shareAmount);
            }
        }
    }

    /**
     * Returns the net balance between two users (positive value means creditor is owed).
     */
    public double getBalance(User user1, User user2) {
        UserPair pair1 = new UserPair(user1, user2);
        UserPair pair2 = new UserPair(user2, user1);
        double balance1 = balances.getOrDefault(pair1, 0.0);
        double balance2 = balances.getOrDefault(pair2, 0.0);
        return balance1 - balance2;
    }

    /**
     * Returns the total balance of a user considering all transactions.
     * Positive total means the user is owed money overall.
     */
    public double getTotalBalance(User user) {
        double total = 0.0;
        for (Map.Entry<UserPair, Double> entry : balances.entrySet()) {
            UserPair pair = entry.getKey();
            double amount = entry.getValue();
            if (pair.getDebtor().equals(user)) {
                total -= amount;
            } else if (pair.getCreditor().equals(user)) {
                total += amount;
            }
        }
        return total;
    }

    // -------- Group-specific balance methods --------

    public double getGroupBalance(User user1, User user2, String groupId) {
        if (!groupBalances.containsKey(groupId)) return 0.0;
        Map<UserPair, Double> groupMap = groupBalances.get(groupId);
        UserPair key1 = new UserPair(user1, user2);
        UserPair key2 = new UserPair(user2, user1);
        double balance1 = groupMap.getOrDefault(key1, 0.0);
        double balance2 = groupMap.getOrDefault(key2, 0.0);
        return balance1 - balance2;
    }

    public double getGroupTotalBalance(User user, String groupId) {
        if (!groupBalances.containsKey(groupId)) return 0.0;
        double total = 0.0;
        Map<UserPair, Double> groupMap = groupBalances.get(groupId);
        for (Map.Entry<UserPair, Double> entry : groupMap.entrySet()) {
            UserPair pair = entry.getKey();
            double amount = entry.getValue();
            if (pair.getDebtor().equals(user)) total -= amount;
            else if (pair.getCreditor().equals(user)) total += amount;
        }
        return total;
    }

    public Map<UserPair, Double> getAllBalances() {
        return new HashMap<>(balances);
    }

    public Map<UserPair, Double> getGroupBalances(String groupId) {
        if (!groupBalances.containsKey(groupId)) return new HashMap<>();
        return new HashMap<>(groupBalances.get(groupId));
    }

    // -------- Settlement Algorithms --------

    /**
     * Calculates simplified settlements using a greedy algorithm from a balance map.
     */
    private List<Transaction> calculateSimplifiedSettlements(Map<UserPair, Double> balanceMap) {
        // Compute net balance per user.
        Map<User, Double> netBalances = new HashMap<>();
        for (Map.Entry<UserPair, Double> entry : balanceMap.entrySet()) {
            UserPair pair = entry.getKey();
            double amount = entry.getValue();
            netBalances.put(pair.getDebtor(), netBalances.getOrDefault(pair.getDebtor(), 0.0) - amount);
            netBalances.put(pair.getCreditor(), netBalances.getOrDefault(pair.getCreditor(), 0.0) + amount);
        }
        // Separate into debtors and creditors.
        List<Map.Entry<User, Double>> debtors = new ArrayList<>();
        List<Map.Entry<User, Double>> creditors = new ArrayList<>();
        for (Map.Entry<User, Double> entry : netBalances.entrySet()) {
            if (Math.abs(entry.getValue()) < EPSILON) continue;
            if (entry.getValue() < 0) debtors.add(entry);
            else creditors.add(entry);
        }
        // Sort by absolute balance descending.
        debtors.sort((a, b) -> Double.compare(Math.abs(b.getValue()), Math.abs(a.getValue())));
        creditors.sort((a, b) -> Double.compare(Math.abs(b.getValue()), Math.abs(a.getValue())));
        List<Transaction> transactions = new ArrayList<>();
        int i = 0, j = 0;
        while (i < debtors.size() && j < creditors.size()) {
            Map.Entry<User, Double> debtorEntry = debtors.get(i);
            Map.Entry<User, Double> creditorEntry = creditors.get(j);
            double transferAmount = Math.min(Math.abs(debtorEntry.getValue()), creditorEntry.getValue());
            if (transferAmount > EPSILON) {
                transactions.add(new Transaction(debtorEntry.getKey(), creditorEntry.getKey(), transferAmount));
            }
            debtorEntry.setValue(debtorEntry.getValue() + transferAmount);
            creditorEntry.setValue(creditorEntry.getValue() - transferAmount);
            if (Math.abs(debtorEntry.getValue()) < EPSILON) i++;
            if (Math.abs(creditorEntry.getValue()) < EPSILON) j++;
        }
        return transactions;
    }

    public List<Transaction> getSimplifiedSettlements() {
        return calculateSimplifiedSettlements(balances);
    }

    public List<Transaction> getGroupSimplifiedSettlements(String groupId) {
        if (!groupBalances.containsKey(groupId)) return new ArrayList<>();
        return calculateSimplifiedSettlements(groupBalances.get(groupId));
    }

    /**
     * Calculates the optimal minimum number of transactions needed (using DP) to settle all debts.
     */
    public int getOptimalMinimumSettlements() {
        // Compute net balance per user.
        Map<User, Double> netBalances = new HashMap<>();
        for (Map.Entry<UserPair, Double> entry : balances.entrySet()) {
            UserPair pair = entry.getKey();
            double amount = entry.getValue();
            netBalances.put(pair.getDebtor(), netBalances.getOrDefault(pair.getDebtor(), 0.0) - amount);
            netBalances.put(pair.getCreditor(), netBalances.getOrDefault(pair.getCreditor(), 0.0) + amount);
        }
        List<Double> balanceValues = new ArrayList<>();
        for (double value : netBalances.values()) {
            if (Math.abs(value) > EPSILON) balanceValues.add(value);
        }
        int n = balanceValues.size();
        int[] dp = new int[1 << n];
        Arrays.fill(dp, -1);
        dp[0] = 0;
        // Maximum number of zero-sum subsets found.
        int maxZeroSumGroups = dfs((1 << n) - 1, dp, balanceValues);
        return n - maxZeroSumGroups;
    }

    // Helper method to compute sum for a given subset represented by bitmask.
    private double sumForSubset(List<Double> values, int mask) {
        double sum = 0;
        for (int i = 0; i < values.size(); i++) {
            if ((mask & (1 << i)) != 0) {
                sum += values.get(i);
            }
        }
        return sum;
    }

    // DFS with memoization to find maximum number of zero-sum subgroups.
    private int dfs(int mask, int[] dp, List<Double> balanceValues) {
        if (mask == 0) return 0;
        if (dp[mask] != -1) return dp[mask];
        int n = balanceValues.size();
        int maxGroups = 0;
        // Try every submask.
        for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
            if (Math.abs(sumForSubset(balanceValues, submask)) < EPSILON) {
                maxGroups = Math.max(maxGroups, 1 + dfs(mask ^ submask, dp, balanceValues));
            }
        }
        dp[mask] = maxGroups;
        return maxGroups;
    }
}

// =================== Group and Group Manager ===================

/**
 * Represents a collection of users sharing common expenses.
 */
class Group {
    private final String id;
    private final String name;
    private final String description;
    private final Set<User> members = new HashSet<>();
    private final List<Expense> expenses = new ArrayList<>();

    public Group(String id, String name, String description) {
        this.id = id;
        this.name = name;
        this.description = description;
    }

    // Getters
    public String getId()            { return id; }
    public String getName()          { return name; }
    public String getDescription()   { return description; }
    public Set<User> getMembers()    { return Collections.unmodifiableSet(members); }
    public List<Expense> getExpenses(){ return Collections.unmodifiableList(expenses); }

    // Group modifications.
    public void addMember(User user)      { members.add(user); }
    public void removeMember(User user)   { members.remove(user); }
    public void addExpense(Expense expense){ expenses.add(expense); }
    public boolean isMember(User user)    { return members.contains(user); }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Group)) return false;
        Group group = (Group) o;
        return id.equals(group.id);
    }

    @Override
    public int hashCode() {
        return Objects.hash(id);
    }
}

/**
 * Manages groups and integrates group expenses into the expense and balance system.
 */
class GroupManager {
    private final Map<String, Group> groups = new HashMap<>();
    private final ExpenseManager expenseManager;
    private final BalanceSheet balanceSheet;

    public GroupManager(ExpenseManager expenseManager, BalanceSheet balanceSheet) {
        this.expenseManager = expenseManager;
        this.balanceSheet = balanceSheet;
    }

    public Group createGroup(String id, String name, String description) {
        Group group = new Group(id, name, description);
        groups.put(id, group);
        return group;
    }

    /**
     * Adds an expense to a group after validating all participants and payer.
     */
    public void addExpenseToGroup(Expense expense, Group group) {
        for (User participant : expense.getParticipants()) {
            if (!group.isMember(participant)) {
                throw new IllegalArgumentException("User " + participant.getName() +
                        " is not a member of group " + group.getName());
            }
        }
        if (!group.isMember(expense.getPayer())) {
            throw new IllegalArgumentException("Payer " + expense.getPayer().getName() +
                    " is not a member of group " + group.getName());
        }
        group.addExpense(expense);
        expenseManager.addExpense(expense);
    }

    public Group getGroup(String id) {
        return groups.get(id);
    }

    public Collection<Group> getAllGroups() {
        return Collections.unmodifiableCollection(groups.values());
    }

    public List<Expense> getGroupExpenses(Group group) {
        return group.getExpenses();
    }

    public double getGroupBalance(User user1, User user2, Group group) {
        return balanceSheet.getGroupBalance(user1, user2, group.getId());
    }

    public double getGroupTotalBalance(User user, Group group) {
        return balanceSheet.getGroupTotalBalance(user, group.getId());
    }

    public Map<UserPair, Double> getGroupBalances(Group group) {
        return balanceSheet.getGroupBalances(group.getId());
    }

    public List<Transaction> getGroupSettlements(Group group) {
        return balanceSheet.getGroupSimplifiedSettlements(group.getId());
    }
}

// =================== Client Code ===================

/**
 * Main system entry point for the Splitwise expense sharing application.
 */
class SplitwiseSystem {
    public static void main(String[] args) {
        // Create users.
        User alice   = new User("u1", "Alice", "alice@example.com");
        User bob     = new User("u2", "Bob", "bob@example.com");
        User charlie = new User("u3", "Charlie", "charlie@example.com");
        User david   = new User("u4", "David", "david@example.com");

        // Initialize ExpenseManager and BalanceSheet.
        ExpenseManager expenseManager = new ExpenseManager();
        BalanceSheet balanceSheet = new BalanceSheet();
        expenseManager.addObserver(balanceSheet);

        // Initialize GroupManager.
        GroupManager groupManager = new GroupManager(expenseManager, balanceSheet);

        // ---------------- Group Setup ----------------
        Group roommates = groupManager.createGroup("g1", "Roommates", "Shared apartment expenses");
        roommates.addMember(alice);
        roommates.addMember(bob);
        roommates.addMember(charlie);

        Group tripGroup = groupManager.createGroup("g2", "Weekend Trip", "Weekend trip expenses");
        tripGroup.addMember(alice);
        tripGroup.addMember(bob);
        tripGroup.addMember(david);

        // Expense split strategies.
        Split equalSplit = SplitFactory.createSplit("EQUAL");
        Map<String, Object> emptyDetails = new HashMap<>();

        // ---------------- Group Expense: Roommates ----------------
        List<User> roommatesParticipants = new ArrayList<>(roommates.getMembers());

        // Alice pays for groceries with equal split.
        Map<User, Double> groceryShares = equalSplit.calculateSplit(90.0, roommatesParticipants, emptyDetails);
        Expense groceryExpense = new Expense("e1", "Groceries", 90.0, alice, roommatesParticipants, groceryShares, roommates);
        groupManager.addExpenseToGroup(groceryExpense, roommates);

        // Bob pays for utilities with percentage split.
        Map<String, Object> percentageDetails = new HashMap<>();
        Map<User, Double> percentages = new HashMap<>();
        percentages.put(alice, 33.3);
        percentages.put(bob, 33.3);
        percentages.put(charlie, 33.4);
        percentageDetails.put("percentages", percentages);
        Split percentageSplit = SplitFactory.createSplit("PERCENTAGE");
        Map<User, Double> utilityShares = percentageSplit.calculateSplit(120.0, roommatesParticipants, percentageDetails);
        Expense utilityExpense = new Expense("e2", "Utilities", 120.0, bob, roommatesParticipants, utilityShares, roommates);
        groupManager.addExpenseToGroup(utilityExpense, roommates);

        // ---------------- Group Expense: Trip Group ----------------
        List<User> tripParticipants = new ArrayList<>(tripGroup.getMembers());
        Map<User, Double> hotelShares = equalSplit.calculateSplit(300.0, tripParticipants, emptyDetails);
        Expense hotelExpense = new Expense("e3", "Hotel", 300.0, alice, tripParticipants, hotelShares, tripGroup);
        groupManager.addExpenseToGroup(hotelExpense, tripGroup);

        // ---------------- Non-group Expense ----------------
        List<User> nonGroupParticipants = Arrays.asList(alice, david);
        Map<User, Double> lunchShares = equalSplit.calculateSplit(30.0, nonGroupParticipants, emptyDetails);
        Expense lunchExpense = new Expense("e4", "Lunch", 30.0, david, nonGroupParticipants, lunchShares);
        expenseManager.addExpense(lunchExpense);

        // ---------------- Print Settlements ----------------
        System.out.println("=== Roommates Group Settlements ===");
        List<Transaction> roommateSettlements = groupManager.getGroupSettlements(roommates);
        for (Transaction transaction : roommateSettlements) {
            System.out.println(transaction.getFrom().getName() + " pays " +
                    transaction.getTo().getName() + " $" + transaction.getAmount());
        }

        System.out.println("\n=== Trip Group Settlements ===");
        List<Transaction> tripSettlements = groupManager.getGroupSettlements(tripGroup);
        for (Transaction transaction : tripSettlements) {
            System.out.println(transaction.getFrom().getName() + " pays " +
                    transaction.getTo().getName() + " $" + transaction.getAmount());
        }

        System.out.println("\n=== Overall Settlements ===");
        List<Transaction> allSettlements = balanceSheet.getSimplifiedSettlements();
        for (Transaction transaction : allSettlements) {
            System.out.println(transaction.getFrom().getName() + " pays " +
                    transaction.getTo().getName() + " $" + transaction.getAmount());
        }

        System.out.println("\n=== User Balances Within Groups ===");
        System.out.println("Alice's balance in Roommates: $" + groupManager.getGroupTotalBalance(alice, roommates));
        System.out.println("Bob's balance in Roommates: $" + groupManager.getGroupTotalBalance(bob, roommates));
        System.out.println("Alice's balance in Trip group: $" + groupManager.getGroupTotalBalance(alice, tripGroup));
        System.out.println("David's balance in Trip group: $" + groupManager.getGroupTotalBalance(david, tripGroup));

        System.out.println("\n=== Overall User Balances ===");
        System.out.println("Alice's total balance: $" + balanceSheet.getTotalBalance(alice));
        System.out.println("Bob's total balance: $" + balanceSheet.getTotalBalance(bob));
        System.out.println("Charlie's total balance: $" + balanceSheet.getTotalBalance(charlie));
        System.out.println("David's total balance: $" + balanceSheet.getTotalBalance(david));

        int optimalSettlements = balanceSheet.getOptimalMinimumSettlements();
        System.out.println("\nOptimal Minimum Settlements (DP): " + optimalSettlements);
    }
}
