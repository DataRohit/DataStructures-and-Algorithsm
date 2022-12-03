#include <iostream>
using namespace std;

bool isSafe(int **arr, int x, int y, int n)
{
    /*
     *  Check if the column is safe
     *  Check for queen in the column
     */
    for (int row = 0; row < x; row++)
    {
        // If there is a queen in the column
        if (arr[row][y] == 1)
        {
            /*
             *  Return false
             *  Position is not safe
             */
            return false;
        }
    }

    // Set initial positions for the diagonals
    int row = x;
    int col = y;

    /*
     *  Check for queen in the upper left diagonal
     */
    while (row >= 0 && col >= 0)
    {
        // If there is a queen in the diagonal
        if (arr[row][col] == 1)
        {
            // Position not safe
            return false;
        }

        // check upper left diagonal
        row--;
        col--;
    }

    // Set initial positions for the diagonals
    row = x;
    col = y;

    /*
     *  Check for queen in the upper right diagonal
     */
    while (row >= 0 && col < n)
    {
        // If there is a queen in the diagonal
        if (arr[row][col] == 1)
        {
            // Position not safe
            return false;
        }

        // check upper right diagonal
        row--;
        col++;
    }

    // Position is safe
    return true;
} // isSafe

int nQueen(int **arr, int x, int n)
{
    // All queens are placed
    if (x >= n)
    {
        return true;
    }

    // Place the queen in the column
    for (int col = 0; col < n; col++)
    {
        // Check if the position is safe
        if (isSafe(arr, x, col, n))
        {
            /*
             *  If position is safe
             *  Place the queen
             */
            arr[x][col] = 1;

            /*
             *  Incrmement the row
             *  And check for the next queen
             */
            if (nQueen(arr, x + 1, n))
            {
                return true;
            }

            /*
             *  If the position is not safe
             *  Remove the queen
             */
            arr[x][col] = 0; // Backtrack
        }
    }

    return false;
}

int main()
{
    // Title of the program
    cout
        << "***** N-QUEEN PROBLEM *****"
        << endl
        << endl;

    // Get the number of queens
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    // Initialize the array of size n x n
    int **arr = new int *[n];

    // Allocate the memory for the 2D array
    for (int i = 0; i < n; i++)
    {
        // Allocate the memory for each element
        arr[i] = new int[n];

        // Initialize the array with 0
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    // Check if the solution exists
    if (nQueen(arr, 0, n))
    {
        // Print the solution array
        cout
            << endl
            << "Solution: "
            << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout
            << endl
            << "No solution exists"
            << endl;
    }

    return 0;
} // main
