#include <iostream>
using namespace std;

void fibonacci(int n)
{
    int n1 = 0, n2 = 1, n3;

    cout << n1 << " " << n2 << " ";

    for (int i = 0; i < n - 2; i++)
    {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;

        cout << n3 << " ";
    }
}

int main()
{
    cout
        << "***** FUNCTIONS - FIBONACCI SERIES *****" << endl
        << endl;

    int n;

    cout << "Enter number of elements of fibonacci series: ";
    cin >> n;

    fibonacci(n);

    return 0;
}
