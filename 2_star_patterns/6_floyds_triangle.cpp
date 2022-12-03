#include <iostream>
using namespace std;

int main()
{
    cout
        << "***** STAR PATTERN - FLOYDS TRIANGLE *****" << endl
        << endl;

    int rows;

    cout << "Enter value of rows\t: ";
    cin >> rows;

    int count = 1;

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << count << " ";

            count++;
        }
        cout << "\n";
    }

    return 0;
}
