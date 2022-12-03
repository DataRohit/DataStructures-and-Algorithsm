#include <iostream>
using namespace std;

int main()
{
    cout
        << "***** STAR PATTERN - INVERTED HALF PYRAMID *****" << endl
        << endl;

    int rows;

    cout << "Enter value of rows\t: ";
    cin >> rows;

    for (int i = rows; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "* ";
        }
        cout << "\n";
    }

    return 0;
}
