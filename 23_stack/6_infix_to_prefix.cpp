#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

// Function to give the precedence of the operator
int getPrecedence(char op)
{
    // Highest precedence of ^
    if (op == '^')
    {
        return 3;
    }

    // Second highest precedence of * and /
    else if (op == '*' || op == '/')
    {
        return 2;
    }

    // Lowest precedence of + and -
    else if (op == '+' || op == '-')
    {
        return 1;
    }

    // Else return -1
    else
    {
        return -1;
    }
}

// Function to convert infix to prefix
string toPrefix(string exp)
{
    // Reverse our expression
    reverse(exp.begin(), exp.end());

    // Initalize our stack
    stack<char> st;

    // Var to store the result
    string res;

    // Loop over each character of the prefix expression
    for (int i = 0; i < exp.length(); i++)
    {
        // If space encountered jump to next iteration
        if (exp[i] == ' ')
            continue;

        // Check if our element is an operand
        if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'A'))
        {
            // Add the operand to the result string
            res += exp[i];
        }

        // Check if an closing bracket ')' found
        else if (exp[i] == ')')
        {
            // Push the closing bracket to stack
            st.push(exp[i]);
        }

        // Check if an opening bracket '(' found
        else if (exp[i] == '(')
        {
            /*
             * Check if the stack is empty or not
             * Check if the top of stack is closing bracket
             */
            while (!st.empty() && st.top() != ')')
            {
                // Add the operator at top of stack to the result
                res += st.top();

                // Pop the stack
                st.pop();
            }

            /*
             * Check if the stack is empty or not
             * And Pop the closing bracket
             */
            if (!st.empty())
            {
                // Pop the stack
                st.pop();
            }
        }

        /*
         * Check if the stack is empty or not
         * Check if precedence of top operator greater than precedence of current operator
         */
        else
        {
            while (!st.empty() && getPrecedence(st.top()) > getPrecedence(exp[i]))
            {
                /*
                 * Add the top to the result
                 * If top has greater precedence add it to result
                 * Pop the stack
                 */
                res += st.top();

                st.pop();
            }

            // Add the current operator to stack
            st.push(exp[i]);
        }
    }

    // Check for remaining elements in stack
    while (!st.empty())
    {
        // Add the remaining elements to the result
        res += st.top();

        // Pop the stack
        st.pop();
    }

    // Reverse the result string for final answer
    reverse(res.begin(), res.end());

    // Return the result
    return res;
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** INFIX TO PREFIX EXPRESSION *****\n\n";
    printLine();

    // String to store the infix expression
    string exp;
    cout << "Enter the Infix Expression: ";
    getline(cin, exp);

    // Print the prefix expression
    cout << "\nPrefix Expression is: " << toPrefix(exp) << endl;
}