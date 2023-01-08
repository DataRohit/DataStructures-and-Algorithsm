#include <bits/stdc++.h>
using namespace std;

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

// Function to check feasibility of the mid value
bool isFeasible(vector<int> arr, int mid, int n, int k)
{
    // Initialize the array
    int pos = arr[0], elements = 1;

    // Loop to find possible solutions
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - pos >= mid)
        {
            // Update the position
            pos = arr[i];

            // Update the elements
            elements++;

            // Check feasibility
            if (elements == k)
            {
                return true;
            }
        }
    }

    return false;
}

// Function to calculate largest minimum distance
int largestMinDistance(vector<int> arr, int n, int k)
{
    // Sort the array
    sort(arr.begin(), arr.end());

    // Initialize required variables
    int result = -1;
    int left = 1, right = arr.back();

    // Binary Search Approach
    while (left < right)
    {
        // Calculate the mid value
        int mid = (left + right) / 2;

        // Check feasibility of the mid values using utility function
        if (isFeasible(arr, mid, n, k))
        {
            // If feasible then update the result
            result = max(result, mid);

            // Update the lower bound to search in right half
            left = mid + 1;
        }
        else
        {
            // Update the upper bound to search in left half
            right = mid;
        }
    }

    // Return the result
    return result;
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** CHALLENGE 1 *****\n\n";
    cout << "Given is an array with n elements that\nrepresent n positions along a straight line.\nFind K elements such that the minimum distance\nbetween any 2 elements is the maximum possible.\n\n";
    printLine();

    // Declaring the variables
    vector<int> arr = {1, 2, 8, 4, 9};
    int n = arr.size();
    int k = 3;

    // Print the array
    cout << "The Stored Array is:\n";
    for (auto i : arr)
        cout << i << " ";

    cout << "\n\n";

    // Print the result
    cout
        << "The Largest Minimum Distance in given array is: "
        << largestMinDistance(arr, n, k)
        << "\n\n";
}