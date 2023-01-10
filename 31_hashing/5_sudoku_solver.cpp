#include <bits/stdc++.h>
using namespace std;

// Defining short forms
#define ll long long

#define pii pair<int, int>
#define mk make_pair
#define ff first
#define ss second

#define vi vector<int>
#define pb push_back
#define pf pop_front

#define imax INT_MAX
#define imin INT_MIN

#define mii map<int, int>
#define umii unordered_map<int, int>

#define f(i, s, e) for (int i = s; i < e; i++)
#define cf(i, s, e) for (int i = s; i <= e; i++)

#define rf(i, s, e) for (int i = e - 1; i >= s; i--)

// Function to print a seperator line
void printLine() { cout << "--------------------------------------------\n\n"; }

// Function to print the Sudoku Grid
void printArray(vector<vi> arr)
{
    for (auto i : arr)
    {
        for (auto j : i)
        {
            cout << j << "  ";
        }
        cout << "\n";
    }
}

// Function to check if the value is feasible at given position
bool isSafe(vector<vi> &sudoku, int row, int col, int num)
{
    // Check if we find the same num in the row
    cf(i, 0, 8) if (sudoku[row][i] == num) return false;

    // Check if we find the same num in the col
    cf(i, 0, 8) if (sudoku[i][col] == num) return false;

    // Calculate the start of the 3x3 grid for the given elemtn
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    // Check if we find the same num in the 3x3 matrix
    f(i, 0, 3)
        f(j, 0, 3) if (sudoku[startRow + i][startCol + j] == num) return false;

    // If all the above conditions are not satisfied
    // It is safe to insert the element
    return true;
}

// Function to solve the Sudoku Grid
bool solveSudoku(vector<vi> &sudoku, int row = 0, int col = 0)
{
    // Check if we try to access the 9th column of 8th row
    if (row == 8 && col == 9)
    {
        // Return true to avoid back tracking
        return true;
    }

    // We have rows remaining and try to access 9th column
    if (col == 9)
    {
        // Move to next row and reset the column
        row++;
        col = 0;
    }

    // Check if the current position contains a element
    if (sudoku[row][col] > 0)
    {
        // Move to the next column of the same row
        return solveSudoku(sudoku, row, col + 1);
    }

    // Loop over possible solutions for a position
    cf(i, 1, 9)
    {
        // Check if the ans is feasible
        if (isSafe(sudoku, row, col, i))
        {
            // If the answer if feasible add to the Sudoku Grid
            sudoku[row][col] = i;

            // Move to the next column and check for solution
            if (solveSudoku(sudoku, row, col + 1))
            {
                return true;
            }
        }

        // Backtrack if condition not satisfied
        sudoku[row][col] = 0;
    }

    // Return false if no possible solution was found
    return false;
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** SUDOKU SOLVER *****\n\n";
    printLine();

    // Initialize the sudoku grid
    // 0 means unassigned cells
    vector<vi> sudoku = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                         {5, 2, 0, 0, 0, 0, 0, 0, 0},
                         {0, 8, 7, 0, 0, 0, 0, 3, 1},
                         {0, 0, 3, 0, 1, 0, 0, 8, 0},
                         {9, 0, 0, 8, 6, 3, 0, 0, 5},
                         {0, 5, 0, 0, 9, 0, 6, 0, 0},
                         {1, 3, 0, 0, 0, 0, 2, 5, 0},
                         {0, 0, 0, 0, 0, 0, 0, 7, 4},
                         {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    // Print the initial array
    cout << "The Initial Sudoku Grid is:\n\n";
    printArray(sudoku);

    // Line break
    cout << "\n";

    // Check if solution exists
    if (solveSudoku(sudoku))
    {
        cout << "The Solved Sudoku Grid is:\n\n";
        printArray(sudoku);

        // Line break
        cout << "\n";
    }

    else
        cout << "No Solution Exists!\n\n";
}