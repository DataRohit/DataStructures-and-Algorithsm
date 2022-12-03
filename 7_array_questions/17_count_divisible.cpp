#include <iostream>
using namespace std;

// Function to count the number of integers divisible by a and b in the range of position [1, n]
int divisible(int n, int a, int b)
{
    // Count of number divisible by a
    int c1 = n / a;

    // Count of number divisible by b
    int c2 = n / b;

    // Count of number divisible by both a and b
    int c3 = n / (a * b);

    // Calculate the result
    return c1 + c2 - c3;
}

int main()
{
    // Title of the program
    cout
        << "***** COUNT NUMBERS DIVISIBLE *****"
        << endl
        << endl;

    // Input the max value for position [1, n]
    int n;
    cout << "Enter value for n: ";
    cin >> n;

    // Input the value of a
    int a;
    cout << "Enter value for a: ";
    cin >> a;

    // Input the value of b
    int b;
    cout << "Enter value for b: ";
    cin >> b;

    int countDivisible = divisible(n, a, b);

    // Print the result
    cout
        << endl
        << "The number of integers divisible by "
        << a << " or " << b
        << " in the range of position [1, " << n << "] is: "
        << countDivisible
        << endl;

    return 0;
} // main
