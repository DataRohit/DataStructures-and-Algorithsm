#include <iostream>
using namespace std;

int main()
{
    // Title for the program
    cout
        << "***** MATRIX MULTIPLICATION *****"
        << endl
        << endl;

    // Variables
    int r1, c1, r2, c2;
    bool flag = true;

    while (flag)
    {
        // Take user input for the number of rows and columns for 1st matrix
        cout << "Enter the number of rows for 1st matrix: ";
        cin >> r1;
        cout << "Enter the number of columns for 1st matrix: ";
        cin >> c1;

        // Take user input for the number of rows and columns for 2nd matrix
        cout
            << endl
            << "Enter the number of rows for 2nd matrix: ";
        cin >> r2;
        cout << "Enter the number of columns for 2nd matrix: ";
        cin >> c2;

        // Check if the number of columns of 1st matrix is equal to the number of rows of 2nd matrix
        if (c1 != r2)
        {
            cout
                << endl
                << "Matrix multiplication is not possible" << endl;
            cout
                << "Please enter the correct number of rows and columns" << endl
                << endl;
        }
        else
        {
            flag = false;
        }
    }

    // Declare 2D arrays
    int array1[r1][c1], array2[r2][c2], array3[r1][c2];

    // Take user input for the elements of the 1st array
    cout
        << endl
        << "Enter 1st Array Elements:" << endl;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cin >> array1[i][j];
        }
    }

    // Take user input for the elements of the 2nd array
    cout
        << endl
        << "Enter 2nd Array Elements:" << endl;
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cin >> array2[i][j];
        }
    }

    // Calculate the multiplication of the 2 arrays
    for (int i = 0; i < r1; i++)
    { // Loop over rows of first matrix
        for (int j = 0; j < c2; j++)
        { // Loop over cols of second matrix
            array3[i][j] = 0;
            for (int k = 0; k < c1; k++)
            { // Loop over cols of first matrix
                array3[i][j] += array1[i][k] * array2[k][j];
            }
        }
    }

    // Display the product matrix
    cout
        << endl
        << "The Product Matrix is:" << endl;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cout << array3[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
} // main
