#include <bits/stdc++.h>
using namespace std;

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** 3 SUM PROBLEM *****\n\n";
    printLine();

    // n for size of array
    int n;
    cout << "Enter Number of Elements: ";
    cin >> n;

    // target for the target
    int target;
    cout << "\nEnter Value of Target: ";
    cin >> target;

    // Initialize our array to store elements
    vector<int> arr(n);

    // Accept input for array elements
    cout << "\nEnter the value for array elements:\n";
    for (auto &i : arr)
        cin >> i;

    // Var to store if triplet found
    bool found = false;

    // Sort our arrray
    sort(arr.begin(), arr.end());

    // Iterate over our array
    for (int i = 0; i < n; i++)
    {
        // Get the index of low element and high element
        int low = i + 1;
        int high = n - 1;

        // Loop till low < high
        while (low < high)
        {
            // Calculate the sum
            int currSum = arr[i] + arr[low] + arr[high];

            // Check if current sum == target
            if (currSum == target)
            {
                // Set found to true
                found = true;
            }

            // If current sum < target
            if (currSum < target)
            {
                // Increase the low pointer
                low++;
            }

            // If current sum > target
            else
            {
                // Decrease the high pointer
                high--;
            }
        }
    }

    // Print the answer with message
    if (found)
    {
        cout << "\nTriplet Detected!\n\n";
    }
    else
    {
        cout << "\nNo Triplet Detected!\n\n";
    }
}