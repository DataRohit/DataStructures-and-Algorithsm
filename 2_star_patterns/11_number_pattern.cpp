#include <iostream>
using namespace std;

int main()
{
    cout
        << "***** STAR PATTERN - NUMBER PATTERN *****"
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
            cout << k << " ";
        }

        cout << "\n";
    }

    return 0;
}
