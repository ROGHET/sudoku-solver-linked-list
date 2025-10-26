# 🧮 Sudoku Solver using Linked List (C Project)

A simple yet efficient **Sudoku Solver** implemented in **C** that uses a **linked list** to manage empty cells dynamically.  
This project was created as part of a **Data Structures Mini Project** to demonstrate recursion, backtracking, and linked list manipulation.

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

---

## 📷 Example Output

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


## Menu Options 

1) Play manually
2) Auto-solve
3) Show initial puzzle
4) Exit


✨ Author

Harshit Rawat, Kaushiki CHoubey
Data Structures Mini Project — Sudoku Solver using Linked List
📧 harshit.rawat@somaiya.edu, kaushiki.c@somaiya.edu
