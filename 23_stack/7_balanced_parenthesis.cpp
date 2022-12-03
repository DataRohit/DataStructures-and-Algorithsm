#include <iostream>
#include <stack>
using namespace std;

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

// Function to check if the praenthesis are balanced
bool isValid(string str)
{
    // Store the size of string for looping
    int len = str.size();

    // Declare a character stack
    stack<char> st;

    // Declare a answer variable
    bool ans = true;

    // Traverse or string
    for (int i = 0; i < len; i++)
    {
        // Check for opening bracket
        if (str[i] == '{' || str[i] == '[' || str[i] == '(')
        {
            // Push to stack
            st.push(str[i]);
        }

        // Check for closing parenthesis
        else if (str[i] == ')')
        {
            // If top is opening parenthesis
            if (!st.empty() && st.top() == '(')
            {
                // String is valid so pop the stack
                st.pop();
            }
            else
            {
                // String is invalid
                ans = false;
                break;
            }
        }

        // Check for closing square bracket
        else if (str[i] == ']')
        {
            // If top is opening square bracket
            if (!st.empty() && st.top() == '[')
            {
                // String is valid so pop the stack
                st.pop();
            }
            else
            {
                // String is invalid
                ans = false;
                break;
            }
        }

        // Check for closing curly bracket
        else if (str[i] == '}')
        {
            // If top is opening curly bracket
            if (!st.empty() && st.top() == '{')
            {
                // String is valid so pop the stack
                st.pop();
            }
            else
            {
                // String is invalid
                ans = false;
                break;
            }
        }
    }

    // Check if elements remain in stack
    if (!st.empty())
    {
        return false;
    }

    // Else return true
    return true;
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** BALANCED PARENTHESIS *****\n\n";
    printLine();

    // Declare and initialize our input string
    string str = "{[()]}";

    // Print the string
    cout << "The Input String is: " << str;

    // Check if the string is valid and print message
    if (isValid(str))
    {
        cout << "\n\nValid String!\n\n";
    }
    else
    {
        cout << "\n\nInvalid String!\n\n";
    }
}