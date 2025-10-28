# 🧮 Sudoku Solver using Linked List (C Project)

A simple yet efficient **Sudoku Solver** implemented in **C** that uses a **linked list** to manage empty cells dynamically.  
This project was created as part of a **Data Structures Mini Project** to demonstrate recursion, backtracking, and linked list manipulation.
**Sudoku game and solver** written in **C**, demonstrating:
- Recursive backtracking algorithm for solving
- Linked list management of empty cells
- Interactive play mode with validation
- Console-based UI for easy testing

---

## 🚀 Features
- Solve any valid 9x9 Sudoku puzzle automatically.
- Play manually and fill the Sudoku board interactively.
- Dynamic tracking of empty cells using a linked list.
- Well-structured modular code (with safe memory handling and backtracking).
- Console-based interface for ease of testing.

---

## 🧠 How It Works
1. The initial Sudoku board is stored in a 9x9 2D array.
2. A **linked list** (`Node`) stores coordinates of all empty cells.
3. The `solve_with_list()` function uses **recursive backtracking**:
   - It iterates through each empty cell.
   - Tries valid numbers (1–9) using the `is_safe()` function.
   - Backtracks when a placement violates Sudoku rules.
4. Once solved, the board is displayed neatly with borders.
5. **Play Mode**  
Manually fill the Sudoku grid with input validation.  
- Enter moves interactively (row, column, number).  
- Type `s` to show the board.  
- Type `q` to quit play mode.
6.**Auto-Solve Mode**  
Automatically solves the given Sudoku puzzle using recursion and backtracking,  
optimized with a linked list of empty cells.
7.**Show Initial Puzzle**  
Displays the starting Sudoku puzzle at any time.
8.**Clean Exit**  
Gracefully frees memory and exits the program.

---

### Key Functions
- `is_safe()` – Checks if a number can be placed at a given cell.  
- `solve_with_list()` – Recursive solver using the empty cell linked list.  
- `build_empty_list()` – Builds a linked list of all empty (zero) cells.  
- `play_mode()` – Interactive mode for manual Sudoku solving


## Menu Options 

1) Play manually
2) Auto-solve
3) Show initial puzzle
4) Exit

---
   
## 🧑‍💻 Example Interaction

```text
Simple Sudoku (C) with linked list of empty cells  
Choose:  
1) Play manually  
2) Auto-solve  
3) Show initial puzzle  
4) Exit  

Enter 1-4: 2  
Solving...  
Solved puzzle:

+-------+-------+-------+
| 5 3 4 | 6 7 8 | 9 1 2 |
| 6 7 2 | 1 9 5 | 3 4 8 |
| 1 9 8 | 3 4 2 | 5 6 7 |
+-------+-------+-------+
| 8 5 9 | 7 6 1 | 4 2 3 |
| 4 2 6 | 8 5 3 | 7 9 1 |
| 7 1 3 | 9 2 4 | 8 5 6 |
+-------+-------+-------+
| 9 6 1 | 5 3 7 | 2 8 4 |
| 2 8 7 | 4 1 9 | 6 3 5 |
| 3 4 5 | 2 8 6 | 1 7 9 |
+-------+-------+-------+
```
---

🧾 License

This project is released under the MIT License: feel free to use, modify, and share.

---

⭐ Contributing

Pull requests are welcome!
If you find bugs or have ideas for improvements (like difficulty levels or GUI mode), feel free to open an issue or PR.

---

✨ Author

Harshit Rawat, Kaushiki CHoubey
Data Structures Mini Project: Sudoku Solver using Linked List
📧 harshitrawat3125@gmail.com, kaushiki.c@somaiya.edu
💼 github.com/ROGHET, github.com/Kaushiki2005
