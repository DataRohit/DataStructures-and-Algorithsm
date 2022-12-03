#include <iostream>
using namespace std;

int main()
{
    cout << "***** MAX VALUE OF ARRAY *****";

    // Take size of array as input
    int n;
    cout
        << endl
        << endl
        << "Enter the size of the array: ";
    cin >> n;

    // Declare the array of size n
    int arr[n];

    // Take input of array elements
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element for index " << i << " : ";
        cin >> arr[i];
    }

    // Set the initial maximum value to the first element of the array
    int maxNo = arr[0];

    // Traverse through the array and update the maximum value
    cout
        << endl
        << "The stored array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
        maxNo = max(maxNo, arr[i]);
    }

    // Print the maximum value
    cout
        << endl
        << endl
        << "Maximum value in array: " << maxNo;

    return 0;
} // main
