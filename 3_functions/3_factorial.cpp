#include <iostream>
using namespace std;

void getFactorial(int n)
{
    int factorial = 1;

    for (int i = 1; i <= n; i++)
    {
        factorial *= i;
    }

    cout << "Factorial of " << n << " is " << factorial << endl;
}

int main()
{
    cout
        << "***** FUNCTIONS - FACTORIAL *****" << endl
        << endl;

    int n;

    cout << "Enter number to calculate factorial: ";
    cin >> n;

    getFactorial(n);

    return 0;
}
