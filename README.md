# 🎮 Lucky One Game in C

A strategic two-player board game written in C, played on a 6x6 grid. Players compete to form a continuous line of 6 of their symbols horizontally, vertically, or diagonally.

---

## 📖 About The Game

**Lucky One** is a turn-based grid strategy game designed for two players:
* **Player 1:** Plays with symbol **`O`** (Starts at position `[1][1]`).
* **Player 2:** Plays with symbol **`X`** (Starts at position `[4][4]`).

Players take turns placing their symbols on the board. However, moves are constrained by adjacency rules, making every step highly tactical!

---

## 📜 Game Rules

1. **Adjacency Requirement:** You cannot place your mark anywhere on the board. A move is only valid if the target cell is empty **and** adjacent (horizontally, vertically, or diagonally) to at least one of your previously placed symbols.
2. **Winning Condition:** The first player to align **6 consecutive symbols** in a row, column, or diagonal wins the game.
3. **Draw Condition:** If all cells are filled and neither player has achieved 6-in-a-row, the game ends in a draw.

---

## 🛠️ Code Structure & Key Functions

| Function Name | Description |
| :--- | :--- |
| `initializeBoard()` | Fills the 6x6 grid with empty slot markers (`.`). |
| `firstPlacement()` | Sets initial starting positions for both players (`O` at `[1][1]` and `X` at `[4][4]`). |
| `displayBoard()` | Prints the formatted grid along with row/column indices to the terminal. |
| `hasAdjacentOwnSymbol()` | Checks whether a chosen cell touches an existing mark belonging to the current player. |
| `isValidMove()` | Validates if the selected cell is within bounds, empty, and meets adjacency rules. |
| `checkDirection()` & `checkWin()` | Scans all four orientations (horizontal, vertical, main diagonal, anti-diagonal) for a winning streak of 6 symbols. |
| `isBoardFull()` | Checks if any empty cells remain on the board to determine a draw. |

---

## 🚀 How to Run

### Prerequisites
* A C compiler (e.g., `gcc`, `clang`, or MSVC).

### Compilation & Execution

1. Clone or download this repository:
   ```bash
   git clone https://github.com/your-username/lucky-one-game.git
   cd lucky-one-game
   ```

2. Compile the code using GCC:
   ```bash
   gcc main.c -o lucky_one
   ```

3. Run the executable:
   * **Linux / macOS:**
     ```bash
     ./lucky_one
     ```
   * **Windows:**
     ```cmd
     lucky_one.exe
     ```

---

## 🎮 How to Play

1. On your turn, enter the **Row** index (0 to 5) when prompted.
2. Enter the **Column** index (0 to 5) when prompted.
3. If the move is valid, your mark will be placed, and the updated board will display.
4. If invalid, the game will ask you to enter coordinates again.
