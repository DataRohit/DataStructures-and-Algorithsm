#include <iostream>
using namespace std;

int
main()
{
    cout
        << "***** LENGTH OF LONGEST ARITHMETIC SUBARRAY *****"
        << endl
        << endl;

    // Take size of array as input
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Declare the array of size n
    int arr[n];

    // Take input of array elements
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter element for index " << i << " : ";
        cin >> arr[i];
    }

    // Print the array
    cout
        << endl
        << "The stored array is: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // Declare variables
    int ans  = 2;
    int pd   = arr[1] - arr[0];
    int j    = 2;
    int curr = 2;

    // Calculate the length of longest arithmetic subarray
    while (j < n) {
        // If new element is in arithmetic progression
        if (pd == arr[j] - arr[j - 1]) {
            // Increment the length of current arithmetic subarray
            curr++;
        } else   {
            // Update the value for difference between two consecutive elements
            pd = arr[j] - arr[j - 1];

            // Reset the length of current arithmetic subarray
            curr = 2;
        }

        // Update the length of longest arithmetic subarray
        ans = max(ans, curr);

        j++;
    }

    cout
        << endl
        << endl
        << "The length of longest arithmetic subarray is: " << ans << endl;

    return 0;
} // main
