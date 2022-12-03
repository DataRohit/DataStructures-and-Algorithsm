#include <iostream>
using namespace std;

// Custom function to change the bit at position pos
int updateBit(int n, int pos, int value)
{
    // Create a mask to clear the bit at position pos
    int mask = ~(1 << pos);

    // Clear the bit at position pos
    n = n & mask;

    // Create a mask to set the bit at position pos
    return (n | (value << pos));
}

int main()
{
    // Title of the program
    cout
        << "***** UPDATE / CHANGE BIT *****"
        << endl
        << endl;

    // Call the updateBit function
    cout << "The updated bit: " << updateBit(5, 1, 1) << endl;

    return 0;
}
