/* *File: ex9c.cc
Find the first solution for a soduko game
 ========================================
 Writen by:Amer abu sair , id =325535193, login = amerab
This program Find the first solution for a soduko game
Compile: g++ -Wall ex9c.cc –oex9c
Run: ./ex9c
Input: the row then the col and then the value 
acctully you will input the value in the index that you want
Output: the solution of the soduko as per the values that you did input in the
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int N = 3; 

void set_empty(int final_solution[][N * N]);

void get_input_from_user(int final_solution[][N * N]);

void print_solution(int final_solution[][N * N]);

bool solve_sudoku(int final_solution[][N * N], bool used[][N * N],
                  int row_index, int column_index);

bool check_col(int final_solution[][N * N], int row, int col, int num);

bool check_row(int final_solution[][N * N], int row, int col, int num);

bool check_square(int final_solution[][N * N],
                  int row_start, int col_start, int num);

int main()
{
    int final_solution[N * N][N * N]; 
    bool used[N * N][N * N] = {false}; 
    set_empty(final_solution); 
    get_input_from_user(final_solution); 
    if (solve_sudoku(final_solution, used, 0, 0)) 
    {
        print_solution(final_solution); 
    }
    return 0;
}

bool solve_sudoku(int final_solution[][N * N], bool used[][N * N],
                  int row_index, int column_index)
{
    if (row_index == N * N)
    {
        return true; 
    }

    if (column_index == N * N)
    {
        return solve_sudoku(final_solution, used, row_index + 1, 0); 
    }

    if (final_solution[row_index][column_index] != 0)
    {
        return solve_sudoku(final_solution, used, row_index, column_index + 1); 
    }

    for (int num = 1; num <= N * N; num++)
    {
        if (!used[row_index][num - 1] &&
            check_row(final_solution, row_index, column_index, num) &&
            check_col(final_solution, row_index, column_index, num) &&
            check_square(final_solution, row_index - row_index % 3,
                        column_index - column_index % 3, num))
        {
            final_solution[row_index][column_index] = num;
            used[row_index][num - 1] = true; 
            if (solve_sudoku(final_solution, used, row_index, column_index + 1))
            {
                return true; 
            }
            final_solution[row_index][column_index] = 0; 
            used[row_index][num - 1] = false;
        }
    }
    return false;
}

void set_empty(int final_solution[][N * N])
{
    for (int row_index = 0; row_index < N * N; row_index++)
    {
        for (int column_index = 0; column_index < N * N; column_index++)
        {
            final_solution[row_index][column_index] = 0;
        }
    }
}

void get_input_from_user(int final_solution[][N * N])
{
    int row_index, column_index, value;
    cin >> row_index;
    if (row_index == -1)
    {
        return; 
    }
    cin >> column_index >> value;
    while (row_index >= 0 && column_index >= 0 && 
           value > 0 && value <= N * N && row_index < N * N &&
           column_index < N * N)
    {
        final_solution[row_index][column_index] = value; 
        cin >> row_index;
        if (row_index == -1)
        {
            break; 
        }
        cin >> column_index;
        cin >> value;
    }
}

void print_solution(int final_solution[][N * N])
{
    for (int row_index = 0; row_index < N * N; row_index++)
    {
        for (int column_index = 0; column_index < N * N; column_index++)
        {
            cout << final_solution[row_index][column_index] << " ";
        }
        cout << endl;
    }
}

bool check_col(int final_solution[][N * N],
               int row, int col, int num)
{
    for (int row_index = 0; row_index < N * N; row_index++)
    {
        if (row_index != row && final_solution[row_index][col] == num)
        {
            return false;
        }
    }
    return true;
}

bool check_row(int final_solution[][N * N],
               int row, int col, int num)
{
    for (int col_index = 0; col_index < N * N; col_index++)
    {
        if (col_index != col && final_solution[row][col_index] == num)
        {
            return false;
        }
    }
    return true;
}

bool check_square(int final_solution[][N * N],
                  int row_start, int col_start, int num)
{
    for (int row_index = 0; row_index < N; row_index++)
    {
        for (int col_index = 0; col_index < N; col_index++)
        {
            if (final_solution[row_start + row_index][col_start + col_index] == num)
            {
                return false;
            }
        }
    }
    return true;
}
