#include <bits/stdc++.h>
using namespace std;

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

// Utility function
int findFeasible(vector<int> boards, int n, int limit)
{
    // Required variables
    int sum = 0, painters = 1;

    // Loop for each board
    for (int i = 0; i < n; i++)
    {
        // Update the boards sum
        sum += boards[i];

        // Check if sum exceed the limit
        if (sum > limit)
        {
            // Assign the board to new painter
            sum = boards[i];

            // Increase the painters
            painters++;
        }
    }

    // Return painters;
    return painters;
}

// Function to get minimum time to complete painting
int paintersPartition(vector<int> boards, int n, int m)
{
    // Calulate the max board length -> totalLength
    // Find the largest board size -> k
    int totalLegnth = 0, k = 0;

    // Loop for each board
    for (int i = 0; i < n; i++)
    {
        // Update the k with max values
        k = max(k, boards[i]);

        // Update the total sum
        totalLegnth += boards[i];
    }

    // Initialize the lower and upper bound
    int low = k, high = totalLegnth;

    // Binary Search Approach
    while (low < high)
    {
        // Find the mid
        int mid = (low + high) / 2;

        // Find feasibility
        int painters = findFeasible(boards, n, mid);

        // Check if required painters exceed available
        if (painters <= m)
        {
            // Update the high value to search in left half
            high = mid;
        }
        else
        {
            // Update the low value to search in right half
            low = mid + 1;
        }
    }

    // Return the final answer
    return low;
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** CHALLENGE 3 *****\n\n";
    cout << "Painter's Partition Problem\n\nn - length of n different boards\nm - painters available\n\nA painter paints 1 unit of board\nin 1 unit of time & each painter\nwill paint consecutive boards.\n\nFind the minimum time that will be\nrequired to paint all the boards.\n\n";
    printLine();

    // Declaring the variables
    vector<int> boards = {10, 20, 30, 40};
    int n = boards.size();
    int m = 2;

    // Print the array
    cout << "The Stored Array is:\n";
    for (auto i : boards)
        cout << i << " ";

    cout << "\n\n";

    // Print the result
    cout
        << "The Minimum Time Required to Paint the Boards is: "
        << paintersPartition(boards, n, m)
        << "\n\n";
}