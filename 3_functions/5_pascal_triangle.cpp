#include <iostream>
using namespace std;

int get_factorial(int n)
{
    int factorial = 1;

    for (int i = 1; i <= n; i++)
    {
        factorial *= i;
    }

    return factorial;
}

int get_ncr(int n, int r)
{
    int ncr = get_factorial(n) / (get_factorial(n - r) * get_factorial(r));

    return ncr;
}

int main()
{
    cout
        << "***** FUNCTIONS - PASCAL'S TRIANGLE *****" << endl
        << endl;

    int n, r;

    cout << "Enter value for n: ";
    cin >> n;

    cout << "Enter value for r: ";
    cin >> r;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << get_ncr(i, j) << " ";
        }

        cout << endl;
    }

    return 0;
}
