#include <iostream>
using namespace std;

bool isSafe(int **arr, int x, int y, int n)
{
    /*
     *  1. x < n -> x is within the bounds of the array
     *  2. y < n -> y is within the bounds of the array
     *  3. arr[x][y] == 1 -> the cell is not blocked
     */
    if (x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }
    return false;
}

bool ratinMaze(int **arr, int x, int y, int n, int **solArr)
{
    // Base Case -> If destination is reached
    if (x == n - 1 && y == n - 1)
    {
        // Include the final destination in the solution array
        solArr[x][y] = 1;

        return true;
    }

    // Check if we can move to the next cell
    if (isSafe(arr, x, y, n))
    {
        // Include the cell in the solution array
        solArr[x][y] = 1;

        // Move in horizontal direction -> right
        if (ratinMaze(arr, x + 1, y, n, solArr))
        {
            return true;
        }

        // Move in vertical direction -> down
        if (ratinMaze(arr, x, y + 1, n, solArr))
        {
            return true;
        }

        // Exclude the cell from the solution array
        solArr[x][y] = 0; // Backtracking

        return false;
    }
    return false;
}

int main()
{
    // Title of the program
    cout
        << "***** BACKTRACKING - RAT IN A MAZE *****"
        << endl
        << endl;

    // Enter the size of maze
    int n;
    cout << "Enter the size of the maze: ";
    cin >> n;

    // Create a 2D array of size n x n for the maze
    int **arr = new int *[n];

    // Allocate memory for each row of the array
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    // Take input for the maze
    cout
        << endl
        << "Enter the maze: "
        << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Create a 2D array of size n x n for the solution
    int **solArr = new int *[n];

    // Allocate memory for each row of the array
    for (int i = 0; i < n; i++)
    {
        solArr[i] = new int[n];

        // Initialize the solution array with 0
        for (int j = 0; j < n; j++)
        {
            solArr[i][j] = 0;
        }
    }

    // Find the path from source to destination
    if (ratinMaze(arr, 0, 0, n, solArr))
    {
        // print the sol array if the path found
        cout
            << endl
            << "The path from source to destination is: "
            << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solArr[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
} // main

/*
 * Sample Input Maze:
 * 1 0 1 0 1
 * 1 1 1 1 1
 * 0 1 0 1 0
 * 1 0 0 1 1
 * 1 1 1 0 1
 */
