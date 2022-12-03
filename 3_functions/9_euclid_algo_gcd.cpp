#include <iostream>
using namespace std;

// Function to calculate the greatest common divisor of two numbers
int getGCD(int a, int b)
{
    // while b is not 0, keep calculating the remainder
    while (b != 0)
    {
        int remainder = a % b;
        a = b;
        b = remainder;
    }

    return a;
}

int main()
{
    // Title of the program
    cout
        << "***** EUCLIDS ALGORITHM FOR FINDING GCD *****"
        << endl
        << endl;

    // Enter the value for the first element
    int a;
    cout << "Enter value for a: ";
    cin >> a;

    // Enter the value for the second element
    int b;
    cout << "Enter value for b: ";
    cin >> b;

    // Print the result
    cout
        << endl
        << "The greatest common divisor of " << a << " and " << b << " is: "
        << getGCD(a, b)
        << endl;

    return 0;
}
