#include <iostream>
using namespace std;

int tilingWays(int n)
{
    // Base Case
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }

    // Recursive Case
    return tilingWays(n - 1) + tilingWays(n - 2);
}

int main()
{
    // Title of the program
    cout
        << "***** TILING PROBLEM *****"
        << endl
        << endl;

    // Input
    int n;
    cout << "Enter the number of tiles columns: ";
    cin >> n;

    // Output
    cout
        << endl
        << "Number of ways to tile the floor: " << tilingWays(n)
        << endl;

    return 0;
}
