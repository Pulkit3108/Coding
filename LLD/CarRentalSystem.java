// Low-Level Design: Car Rental System 🚗

// A car rental system designed to efficiently manage vehicle inventory, handle reservations, process payments, and track rental operations. 
// The system supports multiple vehicle types, manages availability across locations, handles user reservations, and provides a seamless rental experience. 
// It is scalable, reliable, and capable of handling concurrent operations.

// Features:
// 1. Multi-location rental stores with independent vehicle inventories.
// 2. Vehicles categorized by type (economy, luxury, SUV, etc.) with attributes like registration number, model, make, year, and rental price.
// 3. Users can search, filter, and sort vehicles based on location, date range, and preferences.
// 4. Reservations can be created, modified, or canceled, with proper availability tracking to prevent conflicts.
// 5. Payment processing supports multiple methods (credit card, cash, PayPal).
// 6. Secure user authentication and audit trails for transactions.
// 7. Fleet maintenance through damage reports and condition monitoring.

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;

// Enums for Vehicle Types, Status, and Reservation Status
enum VehicleType {
    ECONOMY, LUXURY, SUV, VAN, BIKE, AUTO
}

enum VehicleStatus {
    AVAILABLE, RESERVED, RENTED, MAINTENANCE, OUT_OF_SERVICE
}

enum ReservationStatus {
    PENDING, CONFIRMED, IN_PROGRESS, COMPLETED, CANCELED
}

// Abstract base class for all vehicles
abstract class Vehicle {
    private final String registrationNumber;
    private final String make;
    private final String model;
    private final int year;
    private final VehicleType type;
    private VehicleStatus status;
    private final double baseRentalPrice;

    public Vehicle(String registrationNumber, String make, String model, int year, VehicleType type, double baseRentalPrice) {
        this.registrationNumber = registrationNumber;
        this.make = make;
        this.model = model;
        this.year = year;
        this.type = type;
        this.baseRentalPrice = baseRentalPrice;
        this.status = VehicleStatus.AVAILABLE;
    }

    public abstract double calculateRentalFee(int days);

    // Getters and setters
    public String getRegistrationNumber() { return registrationNumber; }
    public VehicleStatus getStatus() { return status; }
    public void setStatus(VehicleStatus status) { this.status = status; }
    public double getBaseRentalPrice() { return baseRentalPrice; }
}

// Concrete Vehicle Implementations
class EconomyVehicle extends Vehicle {
    private static final double RATE_MULTIPLIER = 1.0;

    public EconomyVehicle(String registrationNumber, String make, String model, int year, double baseRentalPrice) {
        super(registrationNumber, make, model, year, VehicleType.ECONOMY, baseRentalPrice);
    }

    @Override
    public double calculateRentalFee(int days) {
        return getBaseRentalPrice() * RATE_MULTIPLIER * days;
    }
}

class LuxuryVehicle extends Vehicle {
    private static final double RATE_MULTIPLIER = 2.5;
    private static final double PREMIUM_FEE = 50.0;

    public LuxuryVehicle(String registrationNumber, String make, String model, int year, double baseRentalPrice) {
        super(registrationNumber, make, model, year, VehicleType.LUXURY, baseRentalPrice);
    }

    @Override
    public double calculateRentalFee(int days) {
        return (getBaseRentalPrice() * RATE_MULTIPLIER + PREMIUM_FEE) * days;
    }
}

class SUVVehicle extends Vehicle {
    private static final double RATE_MULTIPLIER = 1.5;

    public SUVVehicle(String registrationNumber, String make, String model, int year, double baseRentalPrice) {
        super(registrationNumber, make, model, year, VehicleType.SUV, baseRentalPrice);
    }

    @Override
    public double calculateRentalFee(int days) {
        return getBaseRentalPrice() * RATE_MULTIPLIER * days;
    }
}

class VanVehicle extends Vehicle {
    private static final double RATE_MULTIPLIER = 1.3;

    public VanVehicle(String registrationNumber, String make, String model, int year, double baseRentalPrice) {
        super(registrationNumber, make, model, year, VehicleType.VAN, baseRentalPrice);
    }

    @Override
    public double calculateRentalFee(int days) {
        return getBaseRentalPrice() * RATE_MULTIPLIER * days;
    }
}

class BikeVehicle extends Vehicle {
    private static final double RATE_MULTIPLIER = 0.5;

    public BikeVehicle(String registrationNumber, String make, String model, int year, double baseRentalPrice) {
        super(registrationNumber, make, model, year, VehicleType.BIKE, baseRentalPrice);
    }

    @Override
    public double calculateRentalFee(int days) {
        return getBaseRentalPrice() * RATE_MULTIPLIER * days;
    }
}

class AutoVehicle extends Vehicle {
    private static final double RATE_MULTIPLIER = 1.2;

    public AutoVehicle(String registrationNumber, String make, String model, int year, double baseRentalPrice) {
        super(registrationNumber, make, model, year, VehicleType.AUTO, baseRentalPrice);
    }

    @Override
    public double calculateRentalFee(int days) {
        return getBaseRentalPrice() * RATE_MULTIPLIER * days;
    }
}

// Factory for creating vehicles based on type
class VehicleFactory {
    public static Vehicle createVehicle(VehicleType type, String registrationNumber, String make, String model, int year, double baseRentalPrice) {
        switch (type) {
            case ECONOMY: return new EconomyVehicle(registrationNumber, make, model, year, baseRentalPrice);
            case LUXURY: return new LuxuryVehicle(registrationNumber, make, model, year, baseRentalPrice);
            case SUV: return new SUVVehicle(registrationNumber, make, model, year, baseRentalPrice);
            case VAN: return new VanVehicle(registrationNumber, make, model, year, baseRentalPrice);
            case BIKE: return new BikeVehicle(registrationNumber, make, model, year, baseRentalPrice);
            case AUTO: return new AutoVehicle(registrationNumber, make, model, year, baseRentalPrice);
            default: throw new IllegalArgumentException("Unsupported vehicle type: " + type);
        }
    }
}

// Location class
class Location {
    private final String address;
    private final String city;
    private final String state;
    private final String zipCode;

    public Location(String address, String city, String state, String zipCode) {
        this.address = address;
        this.city = city;
        this.state = state;
        this.zipCode = zipCode;
    }

    // Getters
    public String getAddress() { return address; }
    public String getCity() { return city; }
    public String getState() { return state; }
    public String getZipCode() { return zipCode; }
}

// Rental Store class manages its vehicle inventory
class RentalStore {
    private final int id;
    private final String name;
    private final Location location;
    private final Map<String, Vehicle> vehicles = new HashMap<>();

    public RentalStore(int id, String name, Location location) {
        this.id = id;
        this.name = name;
        this.location = location;
    }

    public int getId() { return id; }
    public void addVehicle(Vehicle vehicle) { vehicles.put(vehicle.getRegistrationNumber(), vehicle); }
    public Vehicle getVehicle(String registrationNumber) { return vehicles.get(registrationNumber); }
    public List<Vehicle> getAvailableVehicles() {
        List<Vehicle> availableVehicles = new ArrayList<>();
        for (Vehicle vehicle : vehicles.values()) {
            if (vehicle.getStatus() == VehicleStatus.AVAILABLE) {
                availableVehicles.add(vehicle);
            }
        }
        return availableVehicles;
    }
}

// User class with basic registration details and reservation history
class User {
    private final int id;
    private final String name;
    private final String email;
    private final String phone;
    private final String driversLicense;
    private final List<Reservation> reservations = new ArrayList<>();

    public User(int id, String name, String email, String phone, String driversLicense) {
        this.id = id;
        this.name = name;
        this.email = email;
        this.phone = phone;
        this.driversLicense = driversLicense;
    }

    public int getId() { return id; }
    public void addReservation(Reservation reservation) { reservations.add(reservation); }
}

// Reservation class to manage the reservation lifecycle and amount calculation
class Reservation {
    private final int id;
    private final User user;
    private final Vehicle vehicle;
    private final RentalStore pickupStore;
    private final RentalStore returnStore;
    private final Date startDate;
    private final Date endDate;
    private ReservationStatus status;
    private final double totalAmount;

    public Reservation(int id, User user, Vehicle vehicle, RentalStore pickupStore, RentalStore returnStore, Date startDate, Date endDate) {
        this.id = id;
        this.user = user;
        this.vehicle = vehicle;
        this.pickupStore = pickupStore;
        this.returnStore = returnStore;
        this.startDate = startDate;
        this.endDate = endDate;
        this.status = ReservationStatus.PENDING;
        this.totalAmount = vehicle.calculateRentalFee(calculateRentalDays(startDate, endDate));
    }

    private int calculateRentalDays(Date start, Date end) {
        long diffMillis = end.getTime() - start.getTime();
        return (int) (diffMillis / (1000 * 60 * 60 * 24)) + 1;
    }

    public int getId() { return id; }
    public double getTotalAmount() { return totalAmount; }
    public void confirmReservation() { if (status == ReservationStatus.PENDING) { status = ReservationStatus.CONFIRMED; vehicle.setStatus(VehicleStatus.RESERVED); } }
    public void startRental() { if (status == ReservationStatus.CONFIRMED) { status = ReservationStatus.IN_PROGRESS; vehicle.setStatus(VehicleStatus.RENTED); } }
    public void completeRental() { if (status == ReservationStatus.IN_PROGRESS) { status = ReservationStatus.COMPLETED; vehicle.setStatus(VehicleStatus.AVAILABLE); } }
    public void cancelReservation() { if (status == ReservationStatus.PENDING || status == ReservationStatus.CONFIRMED) { status = ReservationStatus.CANCELED; vehicle.setStatus(VehicleStatus.AVAILABLE); } }
}

// Reservation Manager
class ReservationManager {
    private final Map<Integer, Reservation> reservations = new HashMap<>();
    private int nextReservationId = 1;

    public Reservation createReservation(User user, Vehicle vehicle, RentalStore pickupStore, RentalStore returnStore, Date startDate, Date endDate) {
        Reservation reservation = new Reservation(nextReservationId++, user, vehicle, pickupStore, returnStore, startDate, endDate);
        reservations.put(reservation.getId(), reservation);
        user.addReservation(reservation);
        return reservation;
    }

    public Reservation getReservation(int reservationId) { return reservations.get(reservationId); }
    public void confirmReservation(int reservationId) { Optional.ofNullable(reservations.get(reservationId)).ifPresent(Reservation::confirmReservation); }
    public void startRental(int reservationId) { Optional.ofNullable(reservations.get(reservationId)).ifPresent(Reservation::startRental); }
    public void completeRental(int reservationId) { Optional.ofNullable(reservations.get(reservationId)).ifPresent(Reservation::completeRental); }
    public void cancelReservation(int reservationId) { Optional.ofNullable(reservations.get(reservationId)).ifPresent(Reservation::cancelReservation); }
}

// Payment strategy interface and implementations
interface PaymentStrategy {
    boolean processPayment(double amount);
}

class CreditCardPayment implements PaymentStrategy {
    @Override
    public boolean processPayment(double amount) {
        System.out.println("Processing credit card payment for $" + amount);
        return true;
    }
}

class CashPayment implements PaymentStrategy {
    @Override
    public boolean processPayment(double amount) {
        System.out.println("Processing cash payment for $" + amount);
        return true;
    }
}

class PayPalPayment implements PaymentStrategy {
    @Override
    public boolean processPayment(double amount) {
        System.out.println("Processing PayPal payment for $" + amount);
        return true;
    }
}

// Payment Processor
class PaymentProcessor {
    public boolean processPayment(double amount, PaymentStrategy paymentStrategy) {
        return paymentStrategy.processPayment(amount);
    }
}

// Singleton Rental System
class RentalSystem {
    private static RentalSystem instance;
    private final List<RentalStore> stores = new ArrayList<>();
    private final ReservationManager reservationManager = new ReservationManager();
    private final PaymentProcessor paymentProcessor = new PaymentProcessor();
    private final Map<Integer, User> users = new HashMap<>();
    private int nextUserId = 1;

    private RentalSystem() {}

    public static synchronized RentalSystem getInstance() {
        if (instance == null) {
            instance = new RentalSystem();
        }
        return instance;
    }

    public void addStore(RentalStore store) { stores.add(store); }
    public RentalStore getStore(int storeId) { return stores.stream().filter(store -> store.getId() == storeId).findFirst().orElse(null); }
    public User registerUser(String name, String email, String phone, String driversLicense) {
        User user = new User(nextUserId++, name, email, phone, driversLicense);
        users.put(user.getId(), user);
        return user;
    }

    public Reservation createReservation(int userId, String vehicleRegistration, int pickupStoreId, int returnStoreId, Date startDate, Date endDate) {
        User user = users.get(userId);
        RentalStore pickupStore = getStore(pickupStoreId);
        RentalStore returnStore = getStore(returnStoreId);
        if (user != null && pickupStore != null) {
            Vehicle vehicle = pickupStore.getVehicle(vehicleRegistration);
            if (vehicle != null) {
                return reservationManager.createReservation(user, vehicle, pickupStore, returnStore, startDate, endDate);
            }
        }
        return null;
    }

    public boolean processPayment(int reservationId, PaymentStrategy paymentStrategy) {
        Reservation reservation = reservationManager.getReservation(reservationId);
        if (reservation != null) {
            boolean result = paymentProcessor.processPayment(reservation.getTotalAmount(), paymentStrategy);
            if (result) {
                reservationManager.confirmReservation(reservationId);
                return true;
            }
        }
        return false;
    }

    public void startRental(int reservationId) { reservationManager.startRental(reservationId); }
    public void completeRental(int reservationId) { reservationManager.completeRental(reservationId); }
    public void cancelReservation(int reservationId) { reservationManager.cancelReservation(reservationId); }
}

// Main application class
class CarRental {
    public static void main(String[] args) throws ParseException {
        SimpleDateFormat sdf = new SimpleDateFormat("MM/dd/yyyy");
        RentalSystem rentalSystem = RentalSystem.getInstance();

        // Setup stores and vehicles
        RentalStore store1 = new RentalStore(1, "Downtown Rentals", new Location("123 Main St", "New York", "NY", "10001"));
        RentalStore store2 = new RentalStore(2, "Airport Rentals", new Location("456 Airport Rd", "Los Angeles", "CA", "90045"));
        rentalSystem.addStore(store1);
        rentalSystem.addStore(store2);

        Vehicle economyCar = VehicleFactory.createVehicle(VehicleType.ECONOMY, "EC001", "Toyota", "Corolla", 2022, 50.0);
        store1.addVehicle(economyCar);

        // Register user and create reservation
        User user1 = rentalSystem.registerUser("John Doe", "john@example.com", "123-456-7890", "DL12345");
        Reservation reservation1 = rentalSystem.createReservation(user1.getId(), "EC001", 1, 1, sdf.parse("03/01/2025"), sdf.parse("03/05/2025"));

        if (reservation1 != null) {
            System.out.println("Reservation created. Total amount: $" + reservation1.getTotalAmount());
            PaymentStrategy paymentStrategy = new CreditCardPayment();
            if (rentalSystem.processPayment(reservation1.getId(), paymentStrategy)) {
                System.out.println("Payment successful. Starting rental...");
                rentalSystem.startRental(reservation1.getId());
                rentalSystem.completeRental(reservation1.getId());
                System.out.println("Rental completed.");
            } else {
                System.out.println("Payment failed.");
            }
        } else {
            System.out.println("Reservation creation failed.");
        }
    }
}
