// Low-Level Design: Snake & Food Game 🐍🍏
// The Snake & Food game is a grid-based arcade game where the player controls a snake to eat food and grow in length while avoiding collisions with walls or itself. The game ends when the snake collides with a wall or its own body.

// Game Rules:
// 1. The game is played on an N x N grid.
// 2. The snake starts at an initial position with a length of 1.
// 3. The player controls the snake's movement using directional inputs (Up, Down, Left, Right).
// 4. Eating food increases the snake's length, and new food spawns randomly on the grid.
// 5. The game ends if the snake collides with the grid boundary or itself.

import java.util.*;

// Position class to represent coordinates on the grid
class Position {
    public final int row;
    public final int col;

    public Position(int row, int col) {
        this.row = row;
        this.col = col;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (!(obj instanceof Position)) return false;
        Position other = (Position) obj;
        return this.row == other.row && this.col == other.col;
    }

    @Override
    public int hashCode() {
        return Objects.hash(row, col);
    }
}

// Singleton class representing the game board
class GameBoard {
    private static GameBoard instance;
    private final int width;
    private final int height;

    private GameBoard(int width, int height) {
        this.width = width;
        this.height = height;
    }

    public static GameBoard getInstance(int width, int height) {
        if (instance == null) {
            instance = new GameBoard(width, height);
        }
        return instance;
    }

    public int getWidth() {
        return width;
    }

    public int getHeight() {
        return height;
    }

    public boolean isOutOfBounds(Position position) {
        return position.row < 0 || position.row >= height || position.col < 0 || position.col >= width;
    }
}

// Snake class to manage the snake's body and movement
class Snake {
    private final Deque<Position> body;
    private final Set<Position> bodySet;

    public Snake(Position initialPosition) {
        this.body = new LinkedList<>();
        this.bodySet = new HashSet<>();
        this.body.addFirst(initialPosition);
        this.bodySet.add(initialPosition);
    }

    public Position getHead() {
        return body.peekFirst();
    }

    public boolean contains(Position position) {
        return bodySet.contains(position);
    }

    public void move(Position newHead, boolean grow) {
        body.addFirst(newHead);
        bodySet.add(newHead);
        if (!grow) {
            Position tail = body.removeLast();
            bodySet.remove(tail);
        }
    }

    public int getLength() {
        return body.size();
    }
}

// Food class to manage food positions on the grid
class Food {
    private final List<Position> foodPositions;
    private int currentIndex;

    public Food(List<Position> foodPositions) {
        this.foodPositions = foodPositions;
        this.currentIndex = 0;
    }

    public Position getCurrentFood() {
        return currentIndex < foodPositions.size() ? foodPositions.get(currentIndex) : null;
    }

    public void consumeFood() {
        currentIndex++;
    }
}

// Movement strategy interface for snake movement
interface MovementStrategy {
    Position getNextPosition(Position currentHead, String direction);
}

// Human movement strategy implementation
class HumanMovementStrategy implements MovementStrategy {
    @Override
    public Position getNextPosition(Position currentHead, String direction) {
        int row = currentHead.row;
        int col = currentHead.col;

        switch (direction) {
            case "U": return new Position(row - 1, col); // Up
            case "D": return new Position(row + 1, col); // Down
            case "L": return new Position(row, col - 1); // Left
            case "R": return new Position(row, col + 1); // Right
            default: throw new IllegalArgumentException("Invalid direction: " + direction);
        }
    }
}

// SimulateSnakeGame class to manage the game logic
class SimulateSnakeGame {
    private final GameBoard board;
    private final Snake snake;
    private final Food food;
    private final MovementStrategy movementStrategy;
    private int score;

    public SimulateSnakeGame(int width, int height, List<Position> foodPositions) {
        this.board = GameBoard.getInstance(width, height);
        this.snake = new Snake(new Position(0, 0)); // Snake starts at (0, 0)
        this.food = new Food(foodPositions);
        this.movementStrategy = new HumanMovementStrategy();
        this.score = 0;
    }

    public int getScore() {
        return score;
    }

    public boolean move(String direction) {
        Position currentHead = snake.getHead();
        Position newHead = movementStrategy.getNextPosition(currentHead, direction);

        // Check for collisions
        if (board.isOutOfBounds(newHead) || (snake.contains(newHead) && !newHead.equals(snake.getHead()))) {
            return false; // Game over
        }

        // Check if food is eaten
        boolean grow = false;
        if (newHead.equals(food.getCurrentFood())) {
            grow = true;
            food.consumeFood();
            score++;
        }

        // Move the snake
        snake.move(newHead, grow);
        return true; // Continue game
    }

    public void displayBoard() {
        int width = board.getWidth();
        int height = board.getHeight();
        Position foodPosition = food.getCurrentFood();

        for (int row = 0; row < height; row++) {
            for (int col = 0; col < width; col++) {
                Position position = new Position(row, col);
                if (snake.getHead().equals(position)) {
                    System.out.print("H "); // Head of the snake
                } else if (snake.contains(position)) {
                    System.out.print("S "); // Body of the snake
                } else if (foodPosition != null && foodPosition.equals(position)) {
                    System.out.print("F "); // Food
                } else {
                    System.out.print(". "); // Empty cell
                }
            }
            System.out.println();
        }
    }
}

// Main class to run the game
class SnakeGame {
    public static void main(String[] args) {
        // Define game configuration
        int width = 10;
        int height = 10;
        List<Position> foodPositions = Arrays.asList(
            new Position(2, 2),
            new Position(4, 4),
            new Position(6, 6),
            new Position(8, 8)
        );

        // Initialize the game
        SimulateSnakeGame game = new SimulateSnakeGame(width, height, foodPositions);

        // Display game instructions
        System.out.println("===== SNAKE GAME =====");
        System.out.println("Controls: W (Up), S (Down), A (Left), D (Right), Q (Quit)");
        System.out.println("Eat food to grow your snake and increase your score.");
        System.out.println("Don't hit the walls or bite yourself!");
        System.out.println("=======================");

        Scanner scanner = new Scanner(System.in);
        boolean gameRunning = true;

        // Main game loop
        while (gameRunning) {
            game.displayBoard();
            System.out.print("Enter move (W/A/S/D) or Q to quit: ");
            String input = scanner.nextLine().toUpperCase();

            if (input.equals("Q")) {
                System.out.println("Game ended by player. Final score: " + game.getScore());
                gameRunning = false;
                continue;
            }

            String direction = convertInput(input);
            if (direction.isEmpty()) {
                System.out.println("Invalid input! Use W/A/S/D to move or Q to quit.");
                continue;
            }

            if (!game.move(direction)) {
                System.out.println("GAME OVER! You hit a wall or bit yourself.");
                System.out.println("Final score: " + game.getScore());
                gameRunning = false;
            }
        }

        scanner.close();
        System.out.println("Thanks for playing!");
    }

    private static String convertInput(String input) {
        switch (input) {
            case "W": return "U"; // Up
            case "S": return "D"; // Down
            case "A": return "L"; // Left
            case "D": return "R"; // Right
            default: return ""; // Invalid input
        }
    }
}