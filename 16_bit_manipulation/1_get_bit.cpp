#include <iostream>
using namespace std;

// Function to get the kth bit of a number
int getBit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}

int main()
{
    // Title of the program
    cout
        << "***** GET k'th BIT *****"
        << endl
        << endl;

    // Call the get bit function
    cout << "The k'th bit is: " << getBit(5, 2) << endl;

    return 0;
}
