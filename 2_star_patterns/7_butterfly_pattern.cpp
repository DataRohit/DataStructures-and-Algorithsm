#include <iostream>
using namespace std;

int main()
{
    cout
        << "***** STAR PATTERN - BUTTERFLY PATTERN *****" << endl
        << endl;

    int rows;

    cout << "Enter value of rows\t: ";
    cin >> rows;

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }

        int space = (2 * rows) - (2 * i);
        for (int j = 1; j <= space; j++)
        {
            cout << "  ";
        }

        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }

        cout << "\n";
    }

    for (int i = rows; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }

        int space = (2 * rows) - (2 * i);
        for (int j = 1; j <= space; j++)
        {
            cout << "  ";
        }

        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }

        cout << "\n";
    }

    return 0;
} // main
