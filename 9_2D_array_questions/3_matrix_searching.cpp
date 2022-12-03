#include <iostream>
using namespace std;

int main()
{
    // Title for the program
    cout
        << "***** MARTIX ELEMENT SEARCHING *****"
        << endl
        << "***** GIVEN: ELEMENTS IN ROWS AND COLUMNS ARE SORTED *****"
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

    // Take user input for key element to search
    int key;
    cout
        << endl
        << "Enter the key element to search: ";
    cin >> key;

    // Initialize the start position
    int key_row = 0, key_column = columns - 1;

    // Search for the key element
    while (key_row >= 0 && key_row < rows && key_column >= 0 && key_column < columns)
    {
        // If element is found
        if (key == array[key_row][key_column])
        {
            cout << "Element found at position: " << key_row << ", " << key_column << endl;
            break;
        }
        // If key smaller than array element move left
        else if (key < array[key_row][key_column])
            key_column--;

        // If key greater than array element move down
        else
            key_row++;
    }

    // If element not found
    if (key_row < 0 || key_row >= rows || key_column < 0 || key_column >= columns)
        cout << "Element not found" << endl;

    return 0;
} // main
