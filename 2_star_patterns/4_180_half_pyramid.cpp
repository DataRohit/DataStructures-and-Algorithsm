#include <iostream>
using namespace std;

int main()
{
    cout
        << "***** STAR PATTERN - 180DEG HALF PYRAMID *****" << endl
        << endl;

    int rows;

    cout << "Enter value of rows\t: ";
    cin >> rows;

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= rows; j++)
        {
            if (j <= rows - i)
            {
                cout << "  ";
            }
            else
            {
                cout << "* ";
            }
        }
        cout << "\n";
    }

    return 0;
}
