#include <iostream>
using namespace std;

int main()
{
    cout
        << "***** RECORD BREAKING DAY *****"
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

    // Record breaking day

    // If only 1 element in array
    if (n == 1)
    {
        // It will be the only record breaking day
        cout
            << endl
            << endl
            << "Total record breaking days: " << 1 << endl;
    }
    else
    {
        // Initialize the count of record breaking days to 0
        int ans = 0;

        // Initialize the max value to -1
        int mx = -1;

        // Traverse throught the array
        for (int i = 0; i < n; i++)
        {
            // 1. Current element greater than max of previous elements
            // 2. Current element greater than next element
            if (arr[i] > mx && arr[i] > arr[i + 1])
            {
                // Increment the count of record breaking days
                ans++;
            }

            // Update the cout for max value
            mx = max(mx, arr[i]);
        }

        // Print the count of record breaking days
        cout
            << endl
            << endl
            << "Total record breaking days: " << ans << endl;
    }

    return 0;
} // main
