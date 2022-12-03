#include <iostream>
using namespace std;

int main()
{
    cout
        << "***** STAR PATTERN - 0-1 PATTERN TRIANGLE *****" << endl
        << endl;

    int rows;

    cout << "Enter value of rows\t: ";
    cin >> rows;

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if ((i + j) % 2 == 0)
                cout << 1 << " ";

            else
                cout << 0 << " ";
        }
        cout << "\n";
    }

    return 0;
}
