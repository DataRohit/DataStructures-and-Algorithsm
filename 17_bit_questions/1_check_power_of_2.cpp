#include <iostream>
using namespace std;

/*
 * NOTE:
 *  When we perform (n & (n - 1)), the last set bit of n gets unset.
 *  That is the last 1 in binary representation of n gets set to 0.
 */

// Custom function to check if a number is power of 2
bool isPowerOfTwo(int n)
{
    // return true if n is power of 2
    return (n && !(n & (n - 1)));
}

int main()
{
    // Title of the program
    cout
        << "***** CHECK POWER OF 2 *****"
        << endl
        << endl;

    // Declare variable
    int n;

    // Input number from user
    cout << "Enter a number: ";
    cin >> n;
    cout << endl;

    // Print the result
    if (isPowerOfTwo(n))
        cout << n << " is a power of 2";
    else
        cout << n << " is not a power of 2";

    return 0;
}
