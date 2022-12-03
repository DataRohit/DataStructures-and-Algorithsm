#include <iostream>
using namespace std;

// Function to find the number of paths possible
int countPath(int s, int e)
{
    // If start == end only one path
    if (s == e)
    {
        return 1;
    }

    // If start > end no path
    if (s > e)
    {
        return 0;
    }

    // counter to count the number of possible paths
    int count = 0;

    // Loop to traverse through the dice
    for (int i = 1; i <= 6; i++)
    {
        count += countPath(s + i, e);
    }

    // Return the count
    return count;
}

int main()
{
    // Title of the program
    cout
        << "***** COUT ALL POSSIBLE PATHS *****"
        << endl
        << endl;

    // Variable to store the start and end point
    int s;
    cout << "Enter the start point: ";
    cin >> s;

    int e;
    cout << "Enter the end point: ";
    cin >> e;

    // Function call to count the number of paths
    cout
        << endl
        << "Number of paths possible: " << countPath(s, e)
        << endl;

    return 0;
}
