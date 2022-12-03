#include <iostream>
using namespace std;

int countMazePaths(int n, int i, int j)
{
    // If we reach the bottom right corner of the maze
    if (i == n - 1 && j == n - 1)
    {
        return 1;
    }

    // If we are outside the maze -> Maze finished
    if (i >= n || j >= n)
    {
        return 0;
    }

    // Horizontal move + Vertical move
    return countMazePaths(n, i + 1, j) + countMazePaths(n, i, j + 1);
}

int main()
{
    // Title of the program
    cout
        << "***** COUT ALL POSSIBLE PATHS IN MAZE *****"
        << endl
        << endl;

    // Input
    int n;
    cout << "Enter the size of the maze: ";
    cin >> n;

    // Output
    cout
        << endl
        << "Total number of paths: " << countMazePaths(n, 0, 0)
        << endl;

    return 0;
}
