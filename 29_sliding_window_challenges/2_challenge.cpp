#include <bits/stdc++.h>
using namespace std;

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

// Function to find the length of smallest sub array
int smallestSubarrayWithSum(vector<int> arr, int n, int x)
{
    // Initialized required vars
    int sum = 0, minLenght = n + 1;

    // Start and end pointer for sliding window
    int start = 0, end = 0;

    // Loop to traverse the array
    while (end < n)
    {
        // Loop over window to calculate and check sum
        while (sum <= x && end < n)
        {
            // Update the sum and update the end pointer
            sum += arr[end++];
        }

        // Loop to update the start pointer
        while (sum > x && start < n)
        {
            // If current subarray size less than minLenght
            if (end - start < minLenght)
            {
                // Update the minLenght
                minLenght = end - start;
            }

            // Update the sum and start pointer
            sum -= arr[start++];
        }
    }

    // Return the min lenght
    return minLenght;
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** CHALLENGE 2 *****\n\n";
    cout << "Smallest Subarry with Sum > X\nFor a given array and an integer X,\nfind the minimum subarray size\nfor which sum > X.\n\n";
    printLine();

    // Initialize the variables
    vector<int> arr = {1, 4, 45, 6, 10, 19};
    int n = arr.size();
    int x = 51;

    // Print the array
    cout << "The Stored Array is:\n";
    for (auto i : arr)
        cout << i << " ";

    cout << "\n\n";

    // Print variable
    cout << "Min Allowed Sum is: " << x << "\n\n";

    // Get the min lenght
    int minLength = smallestSubarrayWithSum(arr, n, x);

    // Print the answer
    if (minLength == n + 1)
    {
        cout << "No Such Subarray Exist!\n\n";
    }
    else
    {
        cout << "Minimum Subarray Size with Sum > " << x << ": " << minLength << "\n\n";
    }
}