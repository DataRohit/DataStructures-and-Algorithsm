#include <iostream>
using namespace std;

int main()
{
    cout
        << "***** STAR PATTERN - NUMBER HALF PYRAMID *****" << endl
        << endl;

    int rows;

    cout << "Enter value of rows\t: ";
    cin >> rows;

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}
