// Low-Level Design: Chess Game
// Chess is a strategy game played between two players on an 8x8 grid. Each player commands an army of 16 pieces: one king, one queen, two rooks, two knights, two bishops, and eight pawns. The objective is to checkmate the opponent's king, placing it in a position where it cannot escape capture.

// Key Features:
// 1. Board Setup:
//    - 8x8 grid with alternating colors.
//    - Each player has 16 pieces in predefined positions. White always starts first.

// 2. Piece Movements:
//    - King: Moves one square in any direction.
//    - Queen: Moves any number of squares in any direction.
//    - Rook: Moves any number of squares horizontally or vertically.
//    - Bishop: Moves any number of squares diagonally.
//    - Knight: Moves in an "L" shape: two squares in one direction and one square perpendicular.
//    - Pawn: Moves forward one square, captures diagonally, and can move two squares forward on its first move.

// 3. Special Moves:
//    - Castling: A move involving the king and a rook.
//    - En Passant: A special pawn capture move.
//    - Pawn Promotion: A pawn reaching the far end of the board can be promoted to another piece.

// 4. Game End Conditions:
//    - Checkmate: A king is in check and cannot escape.
//    - Stalemate: A player has no legal moves, and their king is not in check.
//    - Draw: By agreement, threefold repetition, fifty-move rule, or insufficient material.

import java.util.ArrayList;
import java.util.Scanner;

// Player class
class Player {
    private final String name;
    private final boolean isWhiteSide;

    public Player(String name, boolean isWhiteSide) {
        this.name = name;
        this.isWhiteSide = isWhiteSide;
    }

    public String getName() {
        return name;
    }

    public boolean isWhiteSide() {
        return isWhiteSide;
    }
}

// Enum for game status
enum Status {
    ACTIVE, BLACK_WIN, WHITE_WIN, STALEMATE, DRAW;
}

// Abstract Piece class
abstract class Piece {
    private final boolean isWhitePiece;
    private boolean isCaptured = false;
    private final MovementStrategy movementStrategy;

    public Piece(boolean isWhitePiece, MovementStrategy movementStrategy) {
        this.isWhitePiece = isWhitePiece;
        this.movementStrategy = movementStrategy;
    }

    public boolean isWhite() {
        return isWhitePiece;
    }

    public boolean isCaptured() {
        return isCaptured;
    }

    public void setCaptured(boolean captured) {
        this.isCaptured = captured;
    }

    public boolean canMove(Board board, Cell startCell, Cell endCell) {
        return movementStrategy.canMove(board, startCell, endCell);
    }
}

// King class with movement strategy
class King extends Piece {
    public King(boolean isWhitePiece) {
        super(isWhitePiece, new KingMovementStrategy());
    }
}

// Queen class
class Queen extends Piece {
    public Queen(boolean isWhitePiece) {
        super(isWhitePiece, new QueenMovementStrategy());
    }
}

// Bishop class
class Bishop extends Piece {
    public Bishop(boolean isWhitePiece) {
        super(isWhitePiece, new BishopMovementStrategy());
    }
}

// Knight class
class Knight extends Piece {
    public Knight(boolean isWhitePiece) {
        super(isWhitePiece, new KnightMovementStrategy());
    }
}

// Rook class
class Rook extends Piece {
    public Rook(boolean isWhitePiece) {
        super(isWhitePiece, new RookMovementStrategy());
    }
}

// Pawn class
class Pawn extends Piece {
    public Pawn(boolean isWhitePiece) {
        super(isWhitePiece, new PawnMovementStrategy());
    }
}

// MovementStrategy interface
interface MovementStrategy {
    boolean canMove(Board board, Cell startCell, Cell endCell);
}

// Example KingMovementStrategy
class KingMovementStrategy implements MovementStrategy {
    @Override
    public boolean canMove(Board board, Cell startCell, Cell endCell) {
        int rowDiff = Math.abs(startCell.getRow() - endCell.getRow());
        int colDiff = Math.abs(startCell.getCol() - endCell.getCol());
        return rowDiff <= 1 && colDiff <= 1;
    }
}

// Example movement strategies for other pieces
class QueenMovementStrategy implements MovementStrategy {
    @Override
    public boolean canMove(Board board, Cell startCell, Cell endCell) {
        // Logic for Queen's movement
        int rowDiff = Math.abs(startCell.getRow() - endCell.getRow());
        int colDiff = Math.abs(startCell.getCol() - endCell.getCol());
        return rowDiff == colDiff || startCell.getRow() == endCell.getRow() || startCell.getCol() == endCell.getCol();
    }
}

class BishopMovementStrategy implements MovementStrategy {
    @Override
    public boolean canMove(Board board, Cell startCell, Cell endCell) {
        // Logic for Bishop's movement
        int rowDiff = Math.abs(startCell.getRow() - endCell.getRow());
        int colDiff = Math.abs(startCell.getCol() - endCell.getCol());
        return rowDiff == colDiff;
    }
}

class KnightMovementStrategy implements MovementStrategy {
    @Override
    public boolean canMove(Board board, Cell startCell, Cell endCell) {
        // Logic for Knight's movement
        int rowDiff = Math.abs(startCell.getRow() - endCell.getRow());
        int colDiff = Math.abs(startCell.getCol() - endCell.getCol());
        return rowDiff * colDiff == 2; // L-shaped move
    }
}

class RookMovementStrategy implements MovementStrategy {
    @Override
    public boolean canMove(Board board, Cell startCell, Cell endCell) {
        // Logic for Rook's movement
        return startCell.getRow() == endCell.getRow() || startCell.getCol() == endCell.getCol();
    }
}

class PawnMovementStrategy implements MovementStrategy {
    @Override
    public boolean canMove(Board board, Cell startCell, Cell endCell) {
        // Logic for Pawn's movement
        int rowDiff = endCell.getRow() - startCell.getRow();
        int colDiff = Math.abs(startCell.getCol() - endCell.getCol());
        Piece piece = endCell.getPiece();

        if (startCell.getPiece().isWhite()) {
            return (rowDiff == -1 && colDiff == 0 && piece == null) || // Move forward
                   (rowDiff == -1 && colDiff == 1 && piece != null && !piece.isWhite()); // Capture diagonally
        } else {
            return (rowDiff == 1 && colDiff == 0 && piece == null) || // Move forward
                   (rowDiff == 1 && colDiff == 1 && piece != null && piece.isWhite()); // Capture diagonally
        }
    }
}

// Cell class
class Cell {
    private final int row, col;
    private Piece piece;

    public Cell(int row, int col, Piece piece) {
        this.row = row;
        this.col = col;
        this.piece = piece;
    }

    public int getRow() {
        return row;
    }

    public int getCol() {
        return col;
    }

    public Piece getPiece() {
        return piece;
    }

    public void setPiece(Piece piece) {
        this.piece = piece;
    }
}

// Move class
class Move {
    private final Cell startCell;
    private final Cell endCell;

    public Move(Cell startCell, Cell endCell) {
        this.startCell = startCell;
        this.endCell = endCell;
    }

    public boolean isValid() {
        return startCell.getPiece() != null && (endCell.getPiece() == null || startCell.getPiece().isWhite() != endCell.getPiece().isWhite());
    }

    public Cell getStartCell() {
        return startCell;
    }

    public Cell getEndCell() {
        return endCell;
    }
}

// Board class
class Board {
    private static Board instance;
    private final Cell[][] board;

    private Board(int size) {
        board = new Cell[size][size];
        initializeBoard(size);
    }

    public static Board getInstance(int size) {
        if (instance == null) {
            instance = new Board(size);
        }
        return instance;
    }

    private void initializeBoard(int size) {
        // Initialize board with pieces
        setPieceRow(0, true);
        setPawnRow(1, true);
        setPieceRow(size - 1, false);
        setPawnRow(size - 2, false);

        // Initialize empty cells
        for (int row = 2; row < size - 2; row++) {
            for (int col = 0; col < size; col++) {
                board[row][col] = new Cell(row, col, null);
            }
        }
    }

    private void setPieceRow(int row, boolean isWhite) {
        String[] pieceOrder = {"rook", "knight", "bishop", "queen", "king", "bishop", "knight", "rook"};
        for (int col = 0; col < pieceOrder.length; col++) {
            board[row][col] = new Cell(row, col, PieceFactory.createPiece(pieceOrder[col], isWhite));
        }
    }

    private void setPawnRow(int row, boolean isWhite) {
        for (int col = 0; col < board.length; col++) {
            board[row][col] = new Cell(row, col, PieceFactory.createPiece("pawn", isWhite));
        }
    }

    public void displayBoard() {
        for (Cell[] row : board) {
            for (Cell cell : row) {
                Piece piece = cell.getPiece();
                System.out.print((piece == null ? "-" : piece.getClass().getSimpleName().charAt(0)) + " ");
            }
            System.out.println();
        }
    }

    public Cell getCell(int row, int col) {
        if (row < 0 || row >= board.length || col < 0 || col >= board[row].length) {
            throw new IllegalArgumentException("Invalid cell position: (" + row + ", " + col + ")");
        }
        return board[row][col];
    }
}

// PieceFactory class
abstract class PieceFactory {
    public static Piece createPiece(String pieceType, boolean isWhitePiece) {
        switch (pieceType.toLowerCase()) {
            case "king":
                return new King(isWhitePiece);
            case "queen":
                return new Queen(isWhitePiece);
            case "bishop":
                return new Bishop(isWhitePiece);
            case "knight":
                return new Knight(isWhitePiece);
            case "rook":
                return new Rook(isWhitePiece);
            case "pawn":
                return new Pawn(isWhitePiece);
            default:
                throw new IllegalArgumentException("Unknown piece type: " + pieceType);
        }
    }
}

// Game class
class Game {
    private final Board board;
    private final Player player1;
    private final Player player2;
    private boolean isWhiteTurn;
    private final ArrayList<Move> gameLog;
    private Status status;

    public Game(Player player1, Player player2) {
        this.player1 = player1;
        this.player2 = player2;
        this.board = Board.getInstance(8);
        this.isWhiteTurn = true;
        this.status = Status.ACTIVE;
        this.gameLog = new ArrayList<>();
    }

    public void start() {
        Scanner scanner = new Scanner(System.in);
        while (status == Status.ACTIVE) {
            board.displayBoard();
            System.out.println((isWhiteTurn ? player1.getName() : player2.getName()) + "'s turn");
            System.out.print("Enter start row, start col, end row, end col: ");
            int startRow = scanner.nextInt();
            int startCol = scanner.nextInt();
            int endRow = scanner.nextInt();
            int endCol = scanner.nextInt();

            try {
                Cell startCell = board.getCell(startRow, startCol);
                Cell endCell = board.getCell(endRow, endCol);
                Move move = new Move(startCell, endCell);

                if (move.isValid()) {
                    makeMove(move);
                } else {
                    System.out.println("Invalid move. Try again.");
                }
            } catch (IllegalArgumentException e) {
                System.out.println(e.getMessage());
            }
        }
    }

    private void makeMove(Move move) {
        Piece sourcePiece = move.getStartCell().getPiece();
        Piece destinationPiece = move.getEndCell().getPiece();

        if (destinationPiece instanceof King) {
            status = isWhiteTurn ? Status.WHITE_WIN : Status.BLACK_WIN;
            System.out.println((isWhiteTurn ? player1.getName() : player2.getName()) + " wins!");
            return;
        }

        move.getEndCell().setPiece(sourcePiece);
        move.getStartCell().setPiece(null);
        gameLog.add(move);
        isWhiteTurn = !isWhiteTurn;
    }
}

// Main Chess class
class Chess {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter name for Player 1 (White): ");
        String player1Name = scanner.nextLine();
        System.out.print("Enter name for Player 2 (Black): ");
        String player2Name = scanner.nextLine();

        Player player1 = new Player(player1Name, true);
        Player player2 = new Player(player2Name, false);

        Game game = new Game(player1, player2);
        game.start();
    }
}