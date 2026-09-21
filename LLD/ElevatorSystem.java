// Low-Level Design: Elevator System 🏗️

// An elevator system is designed to efficiently transport people between floors in a building. 
// The system handles multiple requests, optimizes elevator movement, and ensures safety. 
// It accommodates different priorities, handles emergency situations, and provides a smooth user experience.

// System Rules:

// Setup:
// • The building has multiple floors and multiple elevators.
// • Elevators can be called from any floor and can travel to any floor.
// • Each elevator has a maximum capacity and weight limit.
// • The system schedules elevator movement based on requests and optimizes for efficiency.

// Operation:
// • Users can request an elevator from any floor using up/down buttons.
// • Inside the elevator, users can select destination floors.
// • The system prioritizes and schedules requests efficiently.
// • Elevators display their current floor and direction.

// Safety Features:
// • Emergency stop functionality.
// • Overload detection prevents movement if capacity is exceeded.
// • Door sensors prevent doors from closing if obstructed.

import java.util.*;

// Enum to represent the direction of the elevator
enum Direction {
    UP, DOWN, IDLE
}

// Enum to represent the state of the elevator
enum ElevatorState {
    IDLE, MOVING, STOPPED, MAINTENANCE
}

// Observer interface for handling elevator events
interface ElevatorObserver {
    void onElevatorStateChange(Elevator elevator, ElevatorState state);
    void onElevatorFloorChange(Elevator elevator, int floor);
}

// Represents a floor in a building
class Floor {
    private final int floorNumber;

    public Floor(int floorNumber) {
        this.floorNumber = floorNumber;
    }

    public int getFloorNumber() {
        return floorNumber;
    }
}

// Represents an elevator request
class ElevatorRequest {
    private final int floor;
    private final Direction direction;
    private final boolean isInternalRequest;

    public ElevatorRequest(int floor, Direction direction, boolean isInternalRequest) {
        this.floor = floor;
        this.direction = direction;
        this.isInternalRequest = isInternalRequest;
    }

    public int getFloor() {
        return floor;
    }

    public Direction getDirection() {
        return direction;
    }

    public boolean isInternalRequest() {
        return isInternalRequest;
    }
}

// Core Elevator class
class Elevator {
    private final int id;
    private int currentFloor;
    private Direction direction;
    private ElevatorState state;
    private final List<ElevatorObserver> observers;
    private final Queue<ElevatorRequest> requests;

    public Elevator(int id) {
        this.id = id;
        this.currentFloor = 1;
        this.direction = Direction.IDLE;
        this.state = ElevatorState.IDLE;
        this.observers = new ArrayList<>();
        this.requests = new LinkedList<>();
    }

    public int getId() {
        return id;
    }

    public int getCurrentFloor() {
        return currentFloor;
    }

    public Direction getDirection() {
        return direction;
    }

    public ElevatorState getState() {
        return state;
    }

    public void addObserver(ElevatorObserver observer) {
        observers.add(observer);
    }

    public void addRequest(ElevatorRequest request) {
        if (!requests.contains(request)) {
            requests.add(request);
            if (state == ElevatorState.IDLE) {
                direction = request.getFloor() > currentFloor ? Direction.UP : Direction.DOWN;
                setState(ElevatorState.MOVING);
            }
        }
    }

    public void moveToNextStop() {
        if (state != ElevatorState.MOVING || requests.isEmpty()) return;

        ElevatorRequest nextRequest = requests.poll();
        int targetFloor = nextRequest.getFloor();

        while (currentFloor != targetFloor) {
            currentFloor += (direction == Direction.UP) ? 1 : -1;
            notifyFloorChange();
        }

        completeArrival();
    }

    private void completeArrival() {
        setState(ElevatorState.STOPPED);
        if (requests.isEmpty()) {
            direction = Direction.IDLE;
            setState(ElevatorState.IDLE);
        } else {
            direction = requests.peek().getFloor() > currentFloor ? Direction.UP : Direction.DOWN;
            setState(ElevatorState.MOVING);
        }
    }

    private void setState(ElevatorState newState) {
        this.state = newState;
        notifyStateChange();
    }

    private void notifyStateChange() {
        for (ElevatorObserver observer : observers) {
            observer.onElevatorStateChange(this, state);
        }
    }

    private void notifyFloorChange() {
        for (ElevatorObserver observer : observers) {
            observer.onElevatorFloorChange(this, currentFloor);
        }
    }

    public Queue<ElevatorRequest> getRequestsQueue() {
        return new LinkedList<>(requests);
    }
}

// Strategy interface for scheduling
interface SchedulingStrategy {
    int getNextStop(Elevator elevator);
}

// First-Come-First-Serve Scheduling Strategy
class FCFSSchedulingStrategy implements SchedulingStrategy {
    @Override
    public int getNextStop(Elevator elevator) {
        return elevator.getRequestsQueue().peek().getFloor();
    }
}

// LOOK Scheduling Strategy
class LookSchedulingStrategy implements SchedulingStrategy {
    @Override
    public int getNextStop(Elevator elevator) {
        Queue<ElevatorRequest> requests = elevator.getRequestsQueue();
        int currentFloor = elevator.getCurrentFloor();
        Direction direction = elevator.getDirection();

        // Find the nearest request in the current direction
        int nextStop = -1;
        for (ElevatorRequest request : requests) {
            if ((direction == Direction.UP && request.getFloor() > currentFloor) ||
                (direction == Direction.DOWN && request.getFloor() < currentFloor)) {
                nextStop = request.getFloor();
                break;
            }
        }

        // If no request in the current direction, reverse direction
        if (nextStop == -1) {
            direction = (direction == Direction.UP) ? Direction.DOWN : Direction.UP;
            for (ElevatorRequest request : requests) {
                if ((direction == Direction.UP && request.getFloor() > currentFloor) ||
                    (direction == Direction.DOWN && request.getFloor() < currentFloor)) {
                    nextStop = request.getFloor();
                    break;
                }
            }
        }

        return nextStop;
    }
}

// SCAN Scheduling Strategy
class ScanSchedulingStrategy implements SchedulingStrategy {
    @Override
    public int getNextStop(Elevator elevator) {
        Queue<ElevatorRequest> requests = elevator.getRequestsQueue();
        int currentFloor = elevator.getCurrentFloor();
        Direction direction = elevator.getDirection();

        // Sort requests by floor number
        List<ElevatorRequest> sortedRequests = new ArrayList<>(requests);
        sortedRequests.sort(Comparator.comparingInt(ElevatorRequest::getFloor));

        // Find the next stop in the current direction
        for (ElevatorRequest request : sortedRequests) {
            if ((direction == Direction.UP && request.getFloor() > currentFloor) ||
                (direction == Direction.DOWN && request.getFloor() < currentFloor)) {
                return request.getFloor();
            }
        }

        // If no request in the current direction, reverse direction and find the next stop
        direction = (direction == Direction.UP) ? Direction.DOWN : Direction.UP;
        for (ElevatorRequest request : sortedRequests) {
            if ((direction == Direction.UP && request.getFloor() > currentFloor) ||
                (direction == Direction.DOWN && request.getFloor() < currentFloor)) {
                return request.getFloor();
            }
        }

        return -1; // No valid next stop
    }
}

// Elevator Controller class
class ElevatorController {
    private final List<Elevator> elevators;
    private final List<Floor> floors;
    private SchedulingStrategy schedulingStrategy;

    public ElevatorController(int numberOfElevators, int numberOfFloors) {
        this.elevators = new ArrayList<>();
        this.floors = new ArrayList<>();
        this.schedulingStrategy = new FCFSSchedulingStrategy();

        for (int i = 1; i <= numberOfElevators; i++) {
            elevators.add(new Elevator(i));
        }

        for (int i = 1; i <= numberOfFloors; i++) {
            floors.add(new Floor(i));
        }
    }

    public void setSchedulingStrategy(SchedulingStrategy strategy) {
        this.schedulingStrategy = strategy;
    }

    public void requestElevator(int floorNumber, Direction direction) {
        Elevator selectedElevator = findNearestElevator(floorNumber, direction);
        if (selectedElevator != null) {
            selectedElevator.addRequest(new ElevatorRequest(floorNumber, direction, false));
        }
    }

    public void requestFloor(int elevatorId, int floorNumber) {
        Elevator elevator = getElevatorById(elevatorId);
        if (elevator != null) {
            Direction direction = floorNumber > elevator.getCurrentFloor() ? Direction.UP : Direction.DOWN;
            elevator.addRequest(new ElevatorRequest(floorNumber, direction, true));
        }
    }

    private Elevator findNearestElevator(int floorNumber, Direction direction) {
        Elevator nearestElevator = null;
        int minDistance = Integer.MAX_VALUE;

        for (Elevator elevator : elevators) {
            if (elevator.getState() == ElevatorState.IDLE || elevator.getDirection() == direction) {
                int distance = Math.abs(elevator.getCurrentFloor() - floorNumber);
                if (distance < minDistance) {
                    minDistance = distance;
                    nearestElevator = elevator;
                }
            }
        }

        return nearestElevator;
    }

    private Elevator getElevatorById(int elevatorId) {
        for (Elevator elevator : elevators) {
            if (elevator.getId() == elevatorId) {
                return elevator;
            }
        }
        return null;
    }

    public void step() {
        for (Elevator elevator : elevators) {
            if (!elevator.getRequestsQueue().isEmpty()) {
                int nextStop = schedulingStrategy.getNextStop(elevator);
                elevator.moveToNextStop();
            }
        }
    }

    public List<Elevator> getElevators() {
        return elevators;
    }
}

// Main class to run the elevator system simulation
class ElevatorSystemMain {
    public static void main(String[] args) {
        Building building = new Building("Office Tower", 10, 3);
        ElevatorController controller = building.getElevatorController();

        Scanner scanner = new Scanner(System.in);
        boolean running = true;

        System.out.println("Elevator System Simulation");
        System.out.println("Building: " + building.getName());
        System.out.println("Floors: " + building.getNumberOfFloors());
        System.out.println("Elevators: " + controller.getElevators().size());

        while (running) {
            System.out.println("\nSelect an option:");
            System.out.println("1. Request elevator (external)");
            System.out.println("2. Request floor (internal)");
            System.out.println("3. Simulate next step");
            System.out.println("4. Exit simulation");

            int choice = scanner.nextInt();
            switch (choice) {
                case 1:
                    System.out.print("Enter floor number: ");
                    int floorNum = scanner.nextInt();
                    System.out.print("Direction (1 for UP, 2 for DOWN): ");
                    int dirChoice = scanner.nextInt();
                    Direction dir = dirChoice == 1 ? Direction.UP : Direction.DOWN;
                    controller.requestElevator(floorNum, dir);
                    break;
                case 2:
                    System.out.print("Enter elevator ID: ");
                    int elevatorId = scanner.nextInt();
                    System.out.print("Enter destination floor: ");
                    int destFloor = scanner.nextInt();
                    controller.requestFloor(elevatorId, destFloor);
                    break;
                case 3:
                    controller.step();
                    displayElevatorStatus(controller.getElevators());
                    break;
                case 4:
                    running = false;
                    break;
                default:
                    System.out.println("Invalid choice!");
            }
        }

        scanner.close();
        System.out.println("Simulation ended");
    }

    private static void displayElevatorStatus(List<Elevator> elevators) {
        System.out.println("\nElevator Status:");
        for (Elevator elevator : elevators) {
            System.out.println("Elevator " + elevator.getId() + ": Floor " + elevator.getCurrentFloor() +
                    ", Direction " + elevator.getDirection() + ", State " + elevator.getState());
        }
    }
}

// Represents a building with elevators and multiple floors
class Building {
    private final String name;
    private final int numberOfFloors;
    private final ElevatorController elevatorController;

    public Building(String name, int numberOfFloors, int numberOfElevators) {
        this.name = name;
        this.numberOfFloors = numberOfFloors;
        this.elevatorController = new ElevatorController(numberOfElevators, numberOfFloors);
    }

    public String getName() {
        return name;
    }

    public int getNumberOfFloors() {
        return numberOfFloors;
    }

    public ElevatorController getElevatorController() {
        return elevatorController;
    }
}