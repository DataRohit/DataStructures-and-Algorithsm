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
    cout << "***** SLIDING WINDOW PROBLEM *****\n\n";
    printLine();

    // n for size of array
    int n;
    cout << "Enter Number of Elements: ";
    cin >> n;

    // k for size of window
    int k;
    cout << "\nEnter Size of Window: ";
    cin >> k;

    // Initialize our array to store elements
    vector<int> arr(n);

    // Accept input for array elements
    cout << "\nEnter the value for array elements:\n";

    for (auto &i : arr)
        cin >> i;

    // Initialize our deque
    deque<int> dq;

    // Initialize answer array
    vector<int> ans;

    // Loop over the window
    for (int i = 0; i < k; i++)
    {
        // Make sure our deque is in non-increasing order
        while (!dq.empty() && arr[dq.back()] < arr[i])
        {
            // If the current element greater than the last element of deque
            // Pop the deque
            dq.pop_back();
        }

        // Push i to deque
        dq.push_back(i);
    }

    // Push the answer to answer vector
    ans.push_back(arr[dq.front()]);

    // Loop over the remaining elements
    for (int i = k; i < n; i++)
    {
        // Excluding the first i - k elements because they are traversed above
        if (dq.front() == i - k)
        {
            // Remove from deque
            dq.pop_front();
        }

        // Traverse for next k elements
        while (!dq.empty() && arr[dq.back()] < arr[i])
        {
            // If the current element greater than the last element of deque
            // Pop the deque
            dq.pop_back();
        }

        // Push i to deque
        dq.push_back(i);

        // Push maximum element to answer array
        ans.push_back(arr[dq.front()]);
    }

    // Print our answer array
    cout << "\nThe Solution Array is:\n";
    for (auto i : ans)
    {
        cout << i << " ";
    }

    // Add line break
    cout << "\n\n";
}