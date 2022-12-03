#include <iostream>
using namespace std;

int main()
{
    cout
        << "***** STAR PATTERN - STAR PATTERN *****"
        << endl
        << endl;

    int rows;

    cout << "Enter value of rows\t: ";
    cin >> rows;

    for (int i = 1; i <= rows; i++)
    {
        for (int j = rows; j >= i; j--)
        {
            cout << " ";
        }

        for (int k = 1; k <= i; k++)
        {
            cout << "* ";
        }

        cout << "\n";
    }

    for (int i = rows; i >= 1; i--)
    {
        for (int j = rows; j >= i; j--)
        {
            cout << " ";
        }

        for (int k = 1; k <= i; k++)
        {
            cout << "* ";
        }

        cout << "\n";
    }

    return 0;
} // main
