#include <bits/stdc++.h>
using namespace std;

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

// Funtion to calculate the area of max rectangle
int getMaxArea(vector<int> arr)
{
    // Initialize our stack
    stack<int> st;

    // Get the size of arr
    int n = arr.size();

    // Answer var to store the max area
    int ans = 0;

    // i for looping
    int i = 0;

    // Add the last bar as 0 to the array
    arr.push_back(0);

    // Traversing
    while (i < n)
    {
        /*
         * Loop if stack is not empty and
         * Top of stack is greater than current element
         */
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            // Get the top of the stack
            int t = st.top();

            // Get the height of the bar
            int h = arr[t];

            // Pop the stack
            st.pop();

            // If stack is empty the height is smallest
            if (st.empty())
            {
                // Save the max of answer and current bar
                ans = max(ans, h * i);
            }
            else
            {
                // Length of previous rectangle
                int len = i - st.top() - 1;

                // Save the max of answer and previous rectangle
                ans = max(ans, h * len);
            }
        }

        // Push the i'th element to the stack
        st.push(i);

        // Increment the iterator
        i++;
    }

    // Return the answer
    return ans;
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** LARGEST RECTANGLE IN HISTOGRAM *****\n\n";
    printLine();

    // n for size of array
    int n;
    cout << "Enter Number of Elements: ";
    cin >> n;

    // Initialize our array to store elements
    vector<int> arr(n);

    // Accept input for array elements
    cout << "\nEnter the value for array elements:\n";

    for (auto &i : arr)
        cin >> i;

    // Get the answer
    cout
        << "\nThe area of largest rectangle that can be fited is:\n"
        << getMaxArea(arr)
        << " units\n\n";
}