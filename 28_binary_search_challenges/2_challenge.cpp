#include <bits/stdc++.h>
using namespace std;

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

// Function to check feasibility
bool isPossible(vector<int> arr, int n, int m, int min)
{
    // Initialize variables
    int studentsRequired = 1, sum = 0;

    // Loop of pages array
    for (int i = 0; i < n; i++)
    {
        // If individual pages greater than the minimum value
        if (arr[i] > min)
        {
            // Return false
            return false;
        }

        // If total pages greater than the minimum
        if (sum + arr[i] > min)
        {
            // Update the number of students to reduce minimum pages
            studentsRequired++;

            // Update teh sum
            sum = arr[i];

            // If asking for more students than available
            if (studentsRequired > m)
            {
                // Return false
                return false;
            }
        }

        else
        {
            // More pages can be allocated
            sum += arr[i];
        }
    }

    // Finally return true
    return true;
}

// Function to find minimum number of pages
int allocateMinimumPages(vector<int> arr, int n, int m)
{
    // Initializing the sum of pages
    int sum = 0;

    // If books less than number of students
    if (n < m)
    {
        // No feasible solution exist
        return -1;
    }

    // Finding the sum of pages
    for (auto i : arr)
        sum += i;

    // Limits of binary search
    int start = 0, end = sum, ans = INT_MAX;

    // Binary Search Loop
    while (start <= end)
    {
        // Calculate the end
        int mid = (start + end) / 2;

        // Check feasible
        if (isPossible(arr, n, m, mid))
        {
            // If answer exist return the minimum
            ans = min(ans, mid);

            // Update the end to search in left half
            end = mid - 1;
        }
        // Update left to search in right half
        else
        {
            start = mid + 1;
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
    cout << "***** CHALLENGE 2 *****\n\n";
    cout << "n - Number of pages in differnet books [ascending order]\nm - number of students\n\nAll the books have to be divided\namong m students, consecutively.\n\nAllocate the pages in such a way\nthat maximum pages allocated to\na student is minimum.\n\n";
    printLine();

    // Declaring the variables
    vector<int> arr = {12, 34, 67, 90};
    int n = arr.size();
    int m = 2;

    // Print the array
    cout << "The Stored Array is:\n";
    for (auto i : arr)
        cout << i << " ";

    cout << "\n\n";

    // Print the result
    cout
        << "The Minimum No. of Pages that can be allocated are: "
        << allocateMinimumPages(arr, n, m)
        << "\n\n";
}