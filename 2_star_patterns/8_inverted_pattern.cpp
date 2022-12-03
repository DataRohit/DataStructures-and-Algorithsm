#include <iostream>
using namespace std;

int main()
{
    cout
        << "***** STAR PATTERN - INVERTED PATTERN *****" << endl
        << endl;

    int rows;

    cout << "Enter value of rows\t: ";
    cin >> rows;

    for (int i = rows; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}
