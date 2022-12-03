#include <iostream>
using namespace std;

int getFactorial(int n)
{
    int factorial = 1;

    for (int i = 1; i <= n; i++)
    {
        factorial *= i;
    }

    return factorial;
}

int main()
{
    cout
        << "***** FUNCTIONS - COMBINATIONS (nCr) *****" << endl
        << endl;

    int n, r;

    cout << "Enter value for n: ";
    cin >> n;

    cout << "Enter value for r: ";
    cin >> r;

    int ncr = getFactorial(n) / (getFactorial(n - r) * getFactorial(r));

    cout << "nCr = " << ncr << endl;

    return 0;
}
