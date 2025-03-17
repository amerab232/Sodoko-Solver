# Sodoko-Solver
# Sudoku Solver

## Description
This C++ program solves a **9×9 Sudoku puzzle** using **backtracking** and finds the **first possible solution** based on user input.

## Features
- Allows users to input predefined numbers for specific cells in the Sudoku grid.
- Uses a **backtracking algorithm** to find a valid solution.
- Ensures that numbers follow Sudoku rules (no duplicates in rows, columns, or 3×3 sub-grids).
- Prints the completed Sudoku grid if a solution is found.

## Compilation and Execution
### **Compile the Code**
Use the following command to compile the program:
```sh
 g++ -Wall ex9c.cc -o ex9c
```

### **Run the Program**
```sh
 ./ex9c
```

## Input Format
The program expects users to provide values for specific cells:
```
row_index column_index value
```
- `row_index`: The row number (0-8).
- `column_index`: The column number (0-8).
- `value`: A number between **1-9**.

**To stop input, enter `-1`.**

### **Example Input**
```
0 0 5
1 1 3
4 4 7
-1
```
(The user stops input with `-1`.)

## Output Format
If a solution exists, the program prints the solved Sudoku grid.

### **Example Output**
```
5 1 9 7 4 8 6 3 2
7 3 2 6 9 5 4 8 1
8 6 4 2 3 1 9 5 7
1 9 5 8 6 7 2 4 3
3 7 6 4 2 9 5 1 8
4 2 8 5 1 3 7 9 6
9 5 7 1 8 6 3 2 4
6 4 3 9 7 2 1 8 5
2 8 1 3 5 4 9 7 6
```
(The output may vary based on the first valid solution found.)

## How It Works
1. **Initialize the Sudoku Grid**
   - The `final_solution` array (9×9) stores the Sudoku puzzle.
   - The `used` array (9×9) tracks placed numbers in each row.

2. **User Input**
   - Users enter numbers for predefined positions.

3. **Backtracking Algorithm (`solve_sudoku`)**
   - The program tries numbers **1 to 9** in empty cells.
   - It verifies:
     - The **row** does not contain the number (`check_row`).
     - The **column** does not contain the number (`check_col`).
     - The **3×3 sub-grid** does not contain the number (`check_square`).
   - If a number is valid, it moves to the next cell.
   - If no valid number is found, it **backtracks** and tries a different number.

4. **Prints the Solution**
   - If a solution is found, it prints the **completed Sudoku grid**.

## Author
- **Amer Abu Sair**

## License
This project is open-source and available for educational purposes.

