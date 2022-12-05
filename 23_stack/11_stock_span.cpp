#include <bits/stdc++.h>
using namespace std;

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

vector<int> stockSpan(vector<int> prices)
{
    // Initialize our answer vector
    vector<int> ansArr;

    // Initialize our stack with pair type
    stack<pair<int, int>> st;

    // Iterate our prices
    for (auto price : prices)
    {
        // Initialize our days
        int days = 1;

        /*
         * Loop if stack is not empty and
         * If top of stack is less than or equal to current price
         * Add a days of previous price to current price
         */
        while (!st.empty() && st.top().first <= price)
        {
            // Update days
            days += st.top().second;

            // Pop the old price
            st.pop();
        }

        // Push our new data to stack
        st.push({price, days});

        // Add the days to ansArr
        ansArr.push_back(days);
    }

    // Return the answer
    return ansArr;
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** STOCK SPAN *****\n\n";
    printLine();

    // Initialize our array with elements
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    // Print our stock
    cout << "The Stock Prices for our stock are:\n";

    // Print the array elements
    for (auto i : prices)
    {
        cout << i << " ";
    }

    // Get our answers as vector
    vector<int> ansArr = stockSpan(prices);

    // Print our answer vector
    cout << "\n\nStock span days are:\n";
    for (auto i : ansArr)
    {
        cout << i << " ";
    }

    // Add a line break
    cout << "\n\n";
}