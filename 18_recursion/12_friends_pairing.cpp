#include <iostream>
using namespace std;

int friendsPairing(int n)
{
    // Base Case
    if (n == 0 || n == 1 || n == 2)
    {
        return n;
    }

    // Recursive Case
    return friendsPairing(n - 1) + (n - 1) * friendsPairing(n - 2);
}

int main()
{
    // Title of the program
    cout
        << "***** FRIENDS PAIRING PROBLEM *****"
        << endl
        << endl;

    // Input
    int n;
    cout << "Enter the number of friends: ";
    cin >> n;

    // Output
    cout
        << endl
        << "Number of ways to pair the friends: " << friendsPairing(n)
        << endl;

    return 0;
}
