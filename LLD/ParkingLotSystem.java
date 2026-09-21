// Low-Level Design: Parking Lot System 🏧
//
// A parking lot management system is designed to handle the operations of parking vehicles, 
// collecting payments, and managing available space efficiently. The system should be able to 
// accommodate different types of vehicles, provide payment options, and ensure a smooth user experience.
//
// Rules of the System:
//
// Setup:
// • The parking lot has multiple slots available for parking.
// • Different types of vehicles (bike, car, truck) can occupy different slot sizes.
// • Each vehicle is issued a parking ticket upon entry.
// • The system calculates the parking fee based on the duration of stay and vehicle type.
//
// Exit and Payment:
// • A vehicle needs to make a payment before exiting.
// • Multiple payment methods (Cash, Card, UPI) should be supported.
// • Once payment is successful, the vehicle is allowed to exit, and the parking slot is freed.
//
// Illegal Actions:
// • A vehicle cannot park in an already occupied slot.
// • Vehicles cannot vacate without completing the payment process.
//
// Implementation Details:
// • The system uses a strategy pattern for calculating parking fees and processing payments.
// • The parking lot maintains a list of parking slots and provides methods to park and vacate vehicles.
// • Each parking slot is associated with a specific vehicle type and tracks its occupancy status.
// • The main class simulates the parking lot operations, including parking, payment, and vacating slots.

import java.util.*;

// Enum for Vehicle Types
enum VehicleType {
    CAR, BIKE, TRUCK
}

// Enum for Duration Types
enum DurationType {
    HOURS, DAYS
}

// Abstract Vehicle Class
abstract class Vehicle {
    private String licensePlate;
    private VehicleType type;

    public Vehicle(String licensePlate, VehicleType type) {
        this.licensePlate = licensePlate;
        this.type = type;
    }

    public String getLicensePlate() {
        return licensePlate;
    }

    public VehicleType getType() {
        return type;
    }
}

// Concrete Vehicle Classes
class Car extends Vehicle {
    public Car(String licensePlate) {
        super(licensePlate, VehicleType.CAR);
    }
}

class Bike extends Vehicle {
    public Bike(String licensePlate) {
        super(licensePlate, VehicleType.BIKE);
    }
}

// Parking Slot Class
class ParkingSlot {
    private int slotNumber;
    private VehicleType slotType;
    private boolean isOccupied;
    private Vehicle parkedVehicle;

    public ParkingSlot(int slotNumber, VehicleType slotType) {
        this.slotNumber = slotNumber;
        this.slotType = slotType;
        this.isOccupied = false;
    }

    public boolean isOccupied() {
        return isOccupied;
    }

    public boolean canPark(Vehicle vehicle) {
        return !isOccupied && vehicle.getType() == slotType;
    }

    public void parkVehicle(Vehicle vehicle) {
        if (!canPark(vehicle)) {
            throw new IllegalStateException("Cannot park vehicle in this slot.");
        }
        this.parkedVehicle = vehicle;
        this.isOccupied = true;
    }

    public void vacate() {
        if (!isOccupied) {
            throw new IllegalStateException("Slot is already vacant.");
        }
        this.parkedVehicle = null;
        this.isOccupied = false;
    }

    public int getSlotNumber() {
        return slotNumber;
    }

    public Vehicle getParkedVehicle() {
        return parkedVehicle;
    }
}

// Parking Fee Strategy Interface
interface ParkingFeeStrategy {
    double calculateFee(VehicleType vehicleType, int duration, DurationType durationType);
}

// Basic Hourly Rate Strategy
class BasicHourlyRateStrategy implements ParkingFeeStrategy {
    @Override
    public double calculateFee(VehicleType vehicleType, int duration, DurationType durationType) {
        double ratePerHour = switch (vehicleType) {
            case CAR -> 10.0;
            case BIKE -> 5.0;
            case TRUCK -> 15.0;
        };
        return durationType == DurationType.HOURS ? duration * ratePerHour : duration * ratePerHour * 24;
    }
}

// Payment Strategy Interface
interface PaymentStrategy {
    void processPayment(double amount);
}

// Concrete Payment Strategies
class CashPayment implements PaymentStrategy {
    @Override
    public void processPayment(double amount) {
        System.out.println("Paid $" + amount + " using Cash.");
    }
}

class CreditCardPayment implements PaymentStrategy {
    @Override
    public void processPayment(double amount) {
        System.out.println("Paid $" + amount + " using Credit Card.");
    }
}

// Parking Lot Class
class ParkingLot {
    private List<ParkingSlot> parkingSlots;

    public ParkingLot(List<ParkingSlot> parkingSlots) {
        this.parkingSlots = parkingSlots;
    }

    public ParkingSlot findAvailableSlot(VehicleType vehicleType) {
        for (ParkingSlot slot : parkingSlots) {
            if (!slot.isOccupied() && slot.canPark(new Vehicle("", vehicleType) {})) {
                return slot;
            }
        }
        return null;
    }

    public void parkVehicle(Vehicle vehicle) {
        ParkingSlot slot = findAvailableSlot(vehicle.getType());
        if (slot == null) {
            System.out.println("No available slot for " + vehicle.getType());
            return;
        }
        slot.parkVehicle(vehicle);
        System.out.println("Vehicle parked in slot: " + slot.getSlotNumber());
    }

    public void vacateSlot(ParkingSlot slot, Vehicle vehicle) {
        if (slot.isOccupied() && slot.getParkedVehicle().equals(vehicle)) {
            slot.vacate();
            System.out.println("Vehicle vacated slot: " + slot.getSlotNumber());
        } else {
            System.out.println("Invalid operation. Slot is either vacant or vehicle mismatch.");
        }
    }
}

// Main Class to Simulate Parking Lot
class ParkingLotSimulator {
    public static void main(String[] args) {
        List<ParkingSlot> slots = new ArrayList<>();
        slots.add(new ParkingSlot(1, VehicleType.CAR));
        slots.add(new ParkingSlot(2, VehicleType.CAR));
        slots.add(new ParkingSlot(3, VehicleType.BIKE));
        slots.add(new ParkingSlot(4, VehicleType.BIKE));

        ParkingLot parkingLot = new ParkingLot(slots);
        ParkingFeeStrategy feeStrategy = new BasicHourlyRateStrategy();

        Vehicle car = new Car("CAR123");
        Vehicle bike = new Bike("BIKE456");

        parkingLot.parkVehicle(car);
        parkingLot.parkVehicle(bike);

        double carFee = feeStrategy.calculateFee(car.getType(), 2, DurationType.HOURS);
        PaymentStrategy carPayment = new CreditCardPayment();
        carPayment.processPayment(carFee);

        double bikeFee = feeStrategy.calculateFee(bike.getType(), 3, DurationType.HOURS);
        PaymentStrategy bikePayment = new CashPayment();
        bikePayment.processPayment(bikeFee);

        parkingLot.vacateSlot(slots.get(0), car);
        parkingLot.vacateSlot(slots.get(2), bike);
    }
}