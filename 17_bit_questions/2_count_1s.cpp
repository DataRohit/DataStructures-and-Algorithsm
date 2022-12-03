#include <iostream>
using namespace std;

int countSetBits(int n)
{
    // Set initial count to 0
    int count = 0;

    // Loop until n becomes 0
    while (n > 0)
    {
        // Invert the last set bit for every iteration
        n = n & (n - 1);

        // Increment count by 1
        count++;
    }

    return count;
}

int main()
{
    // Title of the program
    cout
        << "***** COUNT 1'S IN BINARY REPRESENTATION *****"
        << endl
        << endl;

    // Declare variable
    int n;

    // Input number from user
    cout << "Enter a number: ";
    cin >> n;
    cout << endl;

    // Print the result
    cout << "Number of 1's in binary representation of " << n << " is " << countSetBits(n);

    return 0;
}
