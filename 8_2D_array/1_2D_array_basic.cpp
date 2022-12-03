#include <iostream>
using namespace std;

int main()
{
    // Title for the program
    cout
        << "***** INPUT / OUTPUT 2D-ARRAY *****"
        << endl
        << endl;

    // Take user input for the number of rows and columns
    int rows, columns;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> columns;
    cout << endl;

    // Declare a 2D array
    int array[rows][columns];

    // Take user input for the elements of the array
    cout << "Enter Array Elements:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cin >> array[i][j];
        }
    }

    // Display the stored array
    cout
        << endl
        << "The Stored Array is: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
} // main
