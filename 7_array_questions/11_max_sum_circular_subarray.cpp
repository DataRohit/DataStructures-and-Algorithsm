#include <iostream>
#include <climits>
using namespace std;

int kadane(int arr[], int n)
{
    // Initialize maximum sum to 0
    int currSum = 0;

    // Initialize maximum sum to INT_MIN
    int maxSum = INT_MIN;

    // Calculate the current sum
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];

        // If current sum is less than 0 then set to 0
        if (currSum < 0)
            currSum = 0;

        // Update the maximum sum
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

int main()
{
    cout
        << "***** MAXIMUM SUM OF CIRCULAR SUBARRAY ELEMENTS *****"
        << endl
        << endl;

    // Take size of array as input
    int n = INT_MIN;
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

    // total sum to 0
    int totalSum = 0;

    // Calculate the non wrap sum for original array
    int nonWrapSum = kadane(arr, n);

    // Calculate total sum
    for (int i = 0; i < n; i++)
    {
        // Update the total sum
        totalSum += arr[i];

        // Invert the size of array elements
        arr[i] = -arr[i];
    }

    // Calculate the wrap sum
    int wrapSum = totalSum + kadane(arr, n);

    // Print the maximum sum
    cout
        << endl
        << endl
        << "The maximum sum of cyclic subarray elements is: " << max(nonWrapSum, wrapSum) << endl;

    return 0;
} // main
