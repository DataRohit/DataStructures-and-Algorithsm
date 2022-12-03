#include <iostream>
using namespace std;

int main()
{
    cout
        << "***** STAR PATTERN - PALINDROMIC PATTERN *****"
        << endl
        << endl;

    int rows;

    cout << "Enter value of rows\t: ";
    cin >> rows;

    for (int i = 1; i <= rows; i++)
    {
        for (int j = rows; j >= i; j--)
        {
            cout << "  ";
        }

        for (int k = i; k >= 1; k--)
        {
            cout << k << " ";
        }

        for (int k = 2; k <= i; k++)
        {
            cout << k << " ";
        }

        cout << "\n";
    }

    return 0;
}
