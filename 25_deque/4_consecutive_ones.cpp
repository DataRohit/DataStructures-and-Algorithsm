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
    cout << "***** MAX CONSECUTIVE ONES BY SWAPPING K 0's *****\n\n";
    printLine();

    // n for size of array
    int n;
    cout << "Enter Number of Elements: ";
    cin >> n;

    // k for the changing 0 to 1
    int k;
    cout << "\nEnter Value of K: ";
    cin >> k;

    // Initialize our array to store elements
    vector<int> arr(n);

    // Accept input for array elements
    cout << "\nEnter the value for array elements:\n";
    for (auto &i : arr)
        cin >> i;

    // Initialize vars
    int zerocount = 0, i = 0, ans = 0;

    // Loop over the array
    for (int j = 0; j < n; j++)
    {
        // Check if array element is 0
        if (arr[j] == 0)
        {
            // Update the zerocount
            zerocount++;
        }

        // If number of zeros in window > k
        while (zerocount > k)
        {
            // If the first element is 0
            if (arr[i] == 0)
            {
                // Decrement the zerocount
                zerocount--;
            }

            // Remove the first element from the window
            i++;
        }

        // zerocount <= k
        ans = max(ans, j - i + 1);
    }

    cout
        << "\nThe Max Number of Consecutive 1's are: "
        << ans << "\n\n";
}