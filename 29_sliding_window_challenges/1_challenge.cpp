#include <bits/stdc++.h>
using namespace std;

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

// Function to get the max sub array sum
int maxSubarraySum(vector<int> arr, int n, int k, int x)
{
    // Variable to keep track of sum and the answer
    int sum = 0, ans = 0;

    // Find sum of first k elements
    for (int i = 0; i < k; i++)
    {
        // Update the sum
        sum += arr[i];
    }

    // Check if sum is feasible
    if (sum < x)
    {
        // Update the answer
        ans = sum;
    }

    // Traverse the elements after k'th index
    for (int i = k; i < n; i++)
    {
        // Add the next element and minus the first element
        sum = sum - arr[i - k] + arr[i];

        // Check if sum is feasible
        if (sum < x)
        {
            // Update the answer
            ans = max(sum, ans);
        }
    }

    // Return the final answer
    return ans;
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** CHALLENGE 1 *****\n\n";
    cout << "Max Sum Subarray\n\nFor a given array and integers K & X,\nfind the maximium sum subarray of size K\nand having sum less than X.\n\n";
    printLine();

    // Initialize the variables
    vector<int> arr = {7, 5, 4, 6, 8, 9};
    int n = arr.size();
    int k = 3;
    int x = 20;

    // Print the array
    cout << "The Stored Array is:\n";
    for (auto i : arr)
        cout << i << " ";

    cout << "\n\n";

    // Print the varialbes
    cout << "Size of Window is: " << k << "\n";
    cout << "Max Allowed Sum is: " << x << "\n\n";

    // Get the max sum
    int maxSum = maxSubarraySum(arr, n, k, x);

    // Print the answer
    cout << "The Max Subarray Sum (<x) is: " << maxSum << "\n\n";
}