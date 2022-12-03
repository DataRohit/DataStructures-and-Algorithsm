#include <iostream>
using namespace std;

int getUnique(int arr[], int n)
{
    // Initialize xorsum to 0
    int xorsum = 0;

    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum ^ arr[i];
    }

    return xorsum;
}

int main()
{
    // Title for the program
    cout << "***** GET UNIQUE NUMBER *****" << endl
         << endl;

    // Declare the array
    int arr[] = {1, 2, 3, 4, 1, 2, 3};

    // Display the elements
    cout << "The stored array is: " << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << endl;

    // Print the result
    cout << "The unique number in the array is: " << getUnique(arr, 7);

    return 0;
}
