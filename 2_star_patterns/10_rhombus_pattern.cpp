#include <iostream>
using namespace std;

int main()
{
    cout
        << "***** STAR PATTERN - RHOMBUS *****"
        << endl
        << endl;

    int rows;

    cout << "Enter value of rows\t: ";
    cin >> rows;

    for (int i = rows; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << " ";
        }

        for (int k = 1; k <= rows; k++)
        {
            cout << "* ";
        }

        cout << "\n";
    }

    return 0;
}
