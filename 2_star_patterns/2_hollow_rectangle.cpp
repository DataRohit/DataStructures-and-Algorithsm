#include <iostream>
using namespace std;

int main()
{
    cout
        << "***** STAR PATTERN - HOLLOW RECTANGLE *****" << endl
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
            if ((i == 0 || i == rows - 1) || (j == 0 || j == cols - 1))
                cout << "* ";
            else
                cout << "  ";
        }
        cout << "\n";
    }

    return 0;
}
