// Low-Level Design: Tic Tac Toe Game 🎲
// Tic Tac Toe is a two-player game played on a 3x3 grid. Players alternate turns placing their symbols ("X" or "O") on the grid. 
// The goal is to align three of their symbols in a row, column, or diagonal. The game ends when a player wins or the grid is full, resulting in a draw.

// Game Rules:
// • The game is played on a 3x3 grid. One player uses 'X', and the other uses 'O'.
// • A player wins by placing three of their symbols in a row, column, or diagonal.
// • The game ends in a draw if all cells are filled without a winner.
// • Players can only place their symbol in an empty cell. Invalid moves are not allowed.

import java.util.Scanner;

// Enum for symbols
enum Symbol {
    X, O, EMPTY
}

// Observer Pattern: Interface for observing game state changes
interface GameObserver {
    void onGameStateChange(String message);
}

// Concrete Observer: Console-based observer
class ConsoleObserver implements GameObserver {
    @Override
    public void onGameStateChange(String message) {
        System.out.println(message);
    }
}

// Board class
class Board {
    private final Symbol[][] grid;
    private final int size;

    public Board(int size) {
        this.size = size;
        this.grid = new Symbol[size][size];
        initializeBoard();
    }

    private void initializeBoard() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                grid[i][j] = Symbol.EMPTY;
            }
        }
    }

    public boolean isCellEmpty(int row, int col) {
        return grid[row][col] == Symbol.EMPTY;
    }

    public void placeSymbol(int row, int col, Symbol symbol) {
        grid[row][col] = symbol;
    }

    public void displayBoard() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                System.out.print((grid[i][j] == Symbol.EMPTY ? "-" : grid[i][j]) + " ");
            }
            System.out.println();
        }
    }

    public boolean checkWin(int row, int col, Symbol symbol) {
        // Check row
        if (isWinningLine(row, 0, 0, 1, symbol)) return true;
        // Check column
        if (isWinningLine(0, col, 1, 0, symbol)) return true;
        // Check main diagonal
        if (row == col && isWinningLine(0, 0, 1, 1, symbol)) return true;
        // Check anti-diagonal
        if (row + col == size - 1 && isWinningLine(0, size - 1, 1, -1, symbol)) return true;

        return false;
    }

    private boolean isWinningLine(int startRow, int startCol, int rowStep, int colStep, Symbol symbol) {
        for (int i = 0; i < size; i++) {
            if (grid[startRow + i * rowStep][startCol + i * colStep] != symbol) {
                return false;
            }
        }
        return true;
    }

    public boolean isFull() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (grid[i][j] == Symbol.EMPTY) {
                    return false;
                }
            }
        }
        return true;
    }

    public boolean isValidMove(Position move) {
        return move.row >= 0 && move.row < size && move.col >= 0 && move.col < size && isCellEmpty(move.row, move.col);
    }
}

// Player class
class Player {
    private final String name;
    private final Symbol symbol;
    private final PlayerStrategy strategy;

    public Player(String name, Symbol symbol, PlayerStrategy strategy) {
        this.name = name;
        this.symbol = symbol;
        this.strategy = strategy;
    }

    public String getName() {
        return name;
    }

    public Symbol getSymbol() {
        return symbol;
    }

    public Position makeMove(Board board) {
        return strategy.makeMove(board);
    }
}

// Strategy Pattern: Interface for Player Moves
interface PlayerStrategy {
    Position makeMove(Board board);
}

// Concrete Strategy: Human Player
class HumanPlayerStrategy implements PlayerStrategy {
    private final Scanner scanner;
    private final String playerName;

    public HumanPlayerStrategy(String playerName) {
        this.playerName = playerName;
        this.scanner = new Scanner(System.in);
    }

    @Override
    public Position makeMove(Board board) {
        while (true) {
            System.out.printf("%s, enter your move (row and column): ", playerName);
            try {
                int row = scanner.nextInt();
                int col = scanner.nextInt();
                Position move = new Position(row, col);
                if (board.isValidMove(move)) {
                    return move;
                }
                System.out.println("Invalid move. Try again.");
            } catch (Exception e) {
                System.out.println("Invalid input. Please enter numbers.");
                scanner.nextLine(); // Clear input buffer
            }
        }
    }
}

// Position class to represent a move
class Position {
    public final int row;
    public final int col;

    public Position(int row, int col) {
        this.row = row;
        this.col = col;
    }
}

// State Pattern: Game State Management
interface GameState {
    void next(GameContext context);
    boolean isGameOver();
}

class XTurnState implements GameState {
    @Override
    public void next(GameContext context) {
        context.setState(new OTurnState());
    }

    @Override
    public boolean isGameOver() {
        return false;
    }
}

class OTurnState implements GameState {
    @Override
    public void next(GameContext context) {
        context.setState(new XTurnState());
    }

    @Override
    public boolean isGameOver() {
        return false;
    }
}

class XWonState implements GameState {
    @Override
    public void next(GameContext context) {
        // Game over, no next state
    }

    @Override
    public boolean isGameOver() {
        return true;
    }
}

class OWonState implements GameState {
    @Override
    public void next(GameContext context) {
        // Game over, no next state
    }

    @Override
    public boolean isGameOver() {
        return true;
    }
}

class DrawState implements GameState {
    @Override
    public void next(GameContext context) {
        // Game over, no next state
    }

    @Override
    public boolean isGameOver() {
        return true;
    }
}

class GameContext {
    private GameState currentState;

    public GameContext() {
        currentState = new XTurnState();
    }

    public void setState(GameState state) {
        this.currentState = state;
    }

    public void next() {
        currentState.next(this);
    }

    public boolean isGameOver() {
        return currentState.isGameOver();
    }

    public GameState getCurrentState() {
        return currentState;
    }
}

// BoardGames interface
interface BoardGames {
    void play();
}

// TicTacToeGame class
class TicTacToeGame implements BoardGames {
    private final Board board;
    private final Player playerX;
    private final Player playerO;
    private Player currentPlayer;
    private final GameContext gameContext;

    public TicTacToeGame(PlayerStrategy xStrategy, PlayerStrategy oStrategy, int boardSize) {
        this.board = new Board(boardSize);
        this.playerX = new Player("Player X", Symbol.X, xStrategy);
        this.playerO = new Player("Player O", Symbol.O, oStrategy);
        this.currentPlayer = playerX;
        this.gameContext = new GameContext();
    }

    @Override
    public void play() {
        while (!gameContext.isGameOver()) {
            board.displayBoard();
            Position move = currentPlayer.makeMove(board);
            board.placeSymbol(move.row, move.col, currentPlayer.getSymbol());
            if (board.checkWin(move.row, move.col, currentPlayer.getSymbol())) {
                gameContext.setState(currentPlayer == playerX ? new XWonState() : new OWonState());
            } else if (board.isFull()) {
                gameContext.setState(new DrawState());
            } else {
                gameContext.next();
                switchPlayer();
            }
        }
        announceResult();
    }

    private void switchPlayer() {
        currentPlayer = (currentPlayer == playerX) ? playerO : playerX;
    }

    private void announceResult() {
        board.displayBoard();
        GameState state = gameContext.getCurrentState();
        if (state instanceof XWonState) {
            System.out.println("Player X wins!");
        } else if (state instanceof OWonState) {
            System.out.println("Player O wins!");
        } else {
            System.out.println("It's a draw!");
        }
    }
}

// Main class
class TicTacToe {
    public static void main(String[] args) {
        PlayerStrategy xStrategy = new HumanPlayerStrategy("Player X");
        PlayerStrategy oStrategy = new HumanPlayerStrategy("Player O");

        TicTacToeGame game = new TicTacToeGame(xStrategy, oStrategy, 3);
        game.play();
    }
}