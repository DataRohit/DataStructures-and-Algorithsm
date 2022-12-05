#include <bits/stdc++.h>
using namespace std;

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

// Function to calculate the store rain water
int rainWater(vector<int> arr)
{
    // Initializing our stack
    stack<int> st;

    // Answer to store the stored water units
    int ans = 0;

    // Get the size of our array
    int n = arr.size();

    // Loop to traverse the array
    for (int i = 0; i < n; i++)
    {
        /*
         * If stack is not empty and
         * Top of stack is less than current element
         * Container for storing water formed
         */
        while (!st.empty() && arr[st.top()] < arr[i])
        {
            // Store the top of stack
            int cur = st.top();

            // Pop the stack
            st.pop();

            /*
             * If now our stack is empty then
             * There is no support on left to hold the water
             */
            if (st.empty())
            {
                // Then break
                break;
            }

            // If stack is not empty then get the length of container
            int diff = i - st.top() - 1;

            /*
             * Calculating the height of container
             *
             * arr[st.top()] -> left wall
             * arr[i] -> right wall
             */
            ans += (min(arr[st.top()], arr[i]) - arr[cur]) * diff;
        }

        // Push the wall to the stack
        st.push(i);
    }

    // Return the answer
    return ans;
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** TRAPPING RAINWATER *****\n\n";
    printLine();

    // Initialize our array with elements
    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    // Print our bar heights
    cout << "The heights of bars are:\n";

    // Print the array elements
    for (auto i : arr)
    {
        cout << i << " ";
    }

    // Get the answer
    cout
        << "\n\nThe area for trapping water is:\n"
        << rainWater(arr)
        << " units\n\n";
}