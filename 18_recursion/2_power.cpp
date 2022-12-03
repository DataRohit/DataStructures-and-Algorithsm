#include <iostream>
using namespace std;

int power(int n, int p)
{
    if (p == 0)
    {
        return 1; // base case - n^0 = 1
    }
    else
    {
        int prevPower = power(n, p - 1); // Will return n^(p-1)

        return n * prevPower; // n * n^(p-1)
    }
}

int main()
{
    // Title of the program
    cout
        << "***** POWER OF NUMBER *****"
        << endl
        << endl;

    int n, p;

    // Input
    cout << "Enter the number: ";
    cin >> n;

    cout << "Enter the power: ";
    cin >> p;

    // Output
    cout
        << endl
        << n << "^" << p << " = " << power(n, p)
        << endl;

    return 0;
}
