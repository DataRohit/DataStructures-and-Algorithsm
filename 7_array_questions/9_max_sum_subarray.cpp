#include <iostream>
#include <climits>
using namespace std;

int main()
{
    cout
        << "***** MAXIMUM SUM OF SUBARRAY ELEMENTS *****"
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

    // Array to store cummulative sum
    int currsum[n + 1];

    // Initialize the first element of currsum as 0
    currsum[0] = 0;

    // Calculate the cummulative sum
    for (int i = 1; i <= n; i++)
    {
        currsum[i] = currsum[i - 1] + arr[i - 1];
    }

    // Initialize maximum sum to INT_MIN
    int maxSum = INT_MIN;

    // Loop to calculate the maximum sum
    for (int i = 0; i <= n; i++)
    {
        int sum = 0;
        for (int j = 0; j < i; j++)
        {
            sum = currsum[i] - currsum[j];
            maxSum = max(maxSum, sum);
        }
    }

    // Print the maximum sum
    cout
        << endl
        << endl
        << "The maximum sum of subarray elements is: " << maxSum << endl;

    return 0;
} // main
