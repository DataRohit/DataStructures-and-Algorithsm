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
    cout << "***** FINDING REDUNDANT PARENTHESES *****\n\n";
    printLine();

    // Answer variable
    bool ans = false;

    // Declare the string for expression input
    string s;

    // Get user input for the expression
    cout << "Enter the expression:\n";
    getline(cin, s);

    // Stack for storing the brackets and operators
    stack<char> st;

    // Iterate our string
    for (int i = 0; i < s.size(); i++)
    {
        // Check if the character is operator
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            // Push the operator to stack
            st.push(s[i]);
        }

        // Check if the character is opening bracket
        else if (s[i] == '(')
        {
            // Push it to stack
            st.push(s[i]);
        }

        // Check if the character is closing bracket
        else if (s[i] == ')')
        {
            // If no operators before the closing
            if (st.top() == '(')
            {
                // Redundant paranetheses detected
                ans = true;
            }

            // If we have operators before the closing bracket
            while (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')
            {
                // Pop the stack till we encounter opening bracket
                st.pop();
            }

            // Pop the opening bracket
            st.pop();
        }
    }

    // Print the answer with message
    if (ans)
    {
        cout << "\nRedundant Parentheses Detected!\n\n";
    }
    else
    {
        cout << "\nNo Redundant Parentheses Detected!\n\n";
    }
}