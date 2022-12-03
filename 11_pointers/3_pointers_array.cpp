#include <iostream>
using namespace std;

int main()
{
    // Title for the program
    cout
        << "***** ACCESSING ARRAY ELEMENTS USING POINTER *****"
        << endl
        << endl;

    // Initializing array
    int arr[5] = {10, 20, 30, 40, 50};

    // Declaring pointer variable
    int *ptr = arr;

    // Printing array elements using pointer
    cout << "Array elements using pointer: " << endl;
    for (int i = 0; i < 5; i++)
    {
        // Printing array element
        cout << *ptr << "\t";

        // Incrementing pointer
        ptr++;
    }

    return 0;
}
