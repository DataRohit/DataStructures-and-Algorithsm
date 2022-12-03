#include <iostream>
using namespace std;

// Function to clear the kth bit of a number
int clearBit(int n, int pos)
{
    int mask = ~(1 << pos);

    return (n & mask);
}

int main()
{
    // Title of the program
    cout
        << "***** CLEAR BIT *****"
        << endl
        << endl;

    // Call the clear bit function
    cout << "The k'th bit is: " << clearBit(5, 2) << endl;

    return 0;
}
