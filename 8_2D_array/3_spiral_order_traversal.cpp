#include <iostream>
using namespace std;

int main()
{
    // Title for the program
    cout
        << "***** SPIRAL ORDER TRAVERSAL *****"
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

    // Display the array in spiral order
    int row_start = 0, row_end = rows - 1;
    int column_start = 0, column_end = columns - 1;

    cout
        << endl
        << "The Array Elements in Spiral Order is: " << endl;
    while (row_start <= row_end && column_start <= column_end)
    {
        // Print the first row
        for (int i = column_start; i <= column_end; i++)
        {
            cout << array[row_start][i] << "\t";
        }
        row_start++;

        // Print the last column
        for (int i = row_start; i <= row_end; i++)
        {
            cout << array[i][column_end] << "\t";
        }
        column_end--;

        // Print the last row
        for (int i = column_end; i >= column_start; i--)
        {
            cout << array[row_end][i] << "\t";
        }
        row_end--;

        // Print the first column
        for (int i = row_end; i >= row_start; i--)
        {
            cout << array[i][column_start] << "\t";
        }
        column_start++;
    }

    return 0;
} // main
