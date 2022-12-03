#include <iostream>
using namespace std;

int main()
{
    cout
        << "***** PRINT ALL POSSIBLE SUBARRAYS *****"
        << endl
        << endl;

    // Take size of array as input
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Declare the array of size n + 1
    int arr[n + 1];
    arr[n] = -1;

    // Take input of array elements
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element for index " << i << " : ";
        cin >> arr[i];
    }

    // Print the array
    cout
        << endl
        << "The stored array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Print all possible subarrays
    cout
        << endl
        << endl
        << "The possible subarrays are: " << endl;

    // Starting point of subarray
    for (int i = 0; i < n; i++)
    {
        // Ending point of subarray
        for (int j = i; j < n; j++)
        {
            // Elemenst of subarray
            for (int k = i; k <= j; k++)
            {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }

    return 0;
} // main
