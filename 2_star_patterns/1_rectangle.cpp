#include <iostream>
using namespace std;

int main()
{
    cout
        << "***** STAR PATTERN - RECTANGLE *****" << endl
        << endl;

    int rows, cols;

    cout << "Enter value of rows\t: ";
    cin >> rows;

    cout << "Enter value of columns\t: ";
    cin >> cols;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "* ";
        }
        cout << "\n";
    }

    return 0;
}
