#include <iostream>
using namespace std;

int main()
{
    cout
        << "***** FIND SUBARRAY *****"
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

    // Declare a variable to check if subarray found
    bool found = false;

    // Traverse the array
    for (int i = 0; i < n; i++)
    {
        // Declare a variable to store sum
        // Initialize the sum to the first element
        int sum = arr[i];

        // Traverse the array from i + 1 to n
        for (int j = i + 1; j < n; j++)
        {
            // Add the element to the sum
            sum += arr[j];

            // Check if sum is 12
            if (sum == 12)
            {
                // Change the flag
                found = true;

                // Print the subarray
                cout
                    << endl
                    << endl
                    << "The subarray with sum 12 is: " << endl;
                for (int k = i; k <= j; k++)
                {
                    cout << arr[k] << " ";
                }
                cout << endl;
            }
            // If sum is greater than 12, break the loop and jump to next element
            else if (sum > 12)

                break;
        }

        if (found)
            break;
    }

    return 0;
} // main
