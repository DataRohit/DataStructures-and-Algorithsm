#include <bits/stdc++.h>
using namespace std;

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

// Function to find the subarray
void computeNumberFromSubarray(vector<int> arr, int k)
{
    // Initialize the answer and sum
    pair<int, int> ans;
    int sum = 0;

    // Find the sum of first k elements
    for (int i = 0; i < k; i++)
    {
        // Update the sum
        sum += arr[i];
    }

    // Var to check if subarray found or not
    bool found = false;

    // Check if sum is required answer
    if (sum % 3 == 0)
    {
        // Update the answer
        ans = make_pair(0, k - 1);

        // Update the found var
        found = true;
    }

    // Loop to traverse remaining elements
    for (int j = k; j < arr.size(); j++)
    {
        // If alread the subarray found do not traverse
        if (found)
        {
            break;
        }

        // If subarray not found -> apply sliding window approach
        sum = sum + arr[j] - arr[j - k];

        // Check if sum is required answer
        if (sum % 3 == 0)
        {
            // Update the answer
            ans = make_pair(j - k + 1, j);

            // Update the found var
            found = true;
        }
    }

    // If answer not found
    if (!found)
    {
        // Update the answer for invalid
        ans = make_pair(-1, 0);
    }

    // Print the answer
    if (ans.first == -1)
    {
        cout << "No Such Subarray Exist!\n\n";
    }
    else
    {
        cout << "The Required Subarray is:\n";
        for (int i = ans.first; i <= ans.second; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n\n";
    }
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** CHALLENGE 3 *****\n\n";
    cout << "Number formed from subarray of size K\ndivisible by 3\n\nFor a given array and an integer K,\ncheck if any subarray of size K exists\nin the array such that elements in the\nsubarray form a number divisible by 3.\n\n";
    printLine();

    // Initialize the variables
    vector<int> arr = {84, 23, 45, 12, 56, 82};
    int k = 3;

    // Print the array
    cout << "The Stored Array is:\n";
    for (auto i : arr)
        cout << i << " ";

    cout << "\n\n";

    // Call the function
    computeNumberFromSubarray(arr, k);
}