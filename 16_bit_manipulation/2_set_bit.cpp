#include <iostream>
using namespace std;

// Function to set the kth bit of a number
int setBit(int n, int pos)
{
    return (n | (1 << pos));
}

int main()
{
    // Title of the program
    cout
        << "***** SET k'th BIT *****"
        << endl
        << endl;

    // Call the set bit function
    cout << "The k'th bit is: " << setBit(5, 1) << endl;

    return 0;
}
