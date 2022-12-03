#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 1)
    {
        return 1; // base case - 1! = 1
    }
    else
    {
        return n * factorial(n - 1); // recursive case
    }
}

int main()
{
    // Title of the program
    cout
        << "*****FACTORIAL OF NUMBER *****"
        << endl
        << endl;

    int n;

    // Input
    cout << "Enter the number: ";
    cin >> n;

    // Output
    cout
        << endl
        << n << "!"
        << " = " << factorial(n)
        << endl;

    return 0;
}
