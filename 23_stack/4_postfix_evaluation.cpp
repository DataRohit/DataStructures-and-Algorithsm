#include <iostream>
#include <stack>
#include <string>
#include <math.h>
using namespace std;

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

// Function to evaluate the postfix equation
int postfixEvaluation(string str)
{
    // Initialize the stack
    stack<int> st;

    // Traverse through the string
    for (int i = 0; i < str.length(); i++)
    {
        // Check if empty space in string
        if (str[i] == ' ')
        {
            // Continue to next iteration
            continue;
        }

        // If element is operand
        if (str[i] >= '0' && str[i] <= '9')
        {
            // Convert the operand to int and push to stack
            st.push(str[i] - '0');
        }
        // If operator is detected
        else
        {
            // Get the top to operands from stack
            int op2 = st.top();
            st.pop();

            int op1 = st.top();
            st.pop();

            // Switch case to perform operation
            switch (str[i])
            {
            // Addition operation
            case '+':
                st.push(op1 + op2);
                break;

            // Subtraction operation
            case '-':
                st.push(op1 - op2);
                break;

            // Multiplication operation
            case '*':
                st.push(op1 * op2);
                break;

            // Division operation
            case '/':
                st.push(op1 / op2);
                break;

            // Power operation
            case '^':
                st.push(pow(op1, op2));
                break;

            // Default case
            default:
                break;
            }
        }
    }

    // Return the final answer
    return st.top();
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** POSTFIX STATEMENT EVALUATION *****\n\n";
    printLine();

    // Declare a string variable
    string str;

    // Take user input for string
    cout << "Enter Postfix String: ";
    getline(cin, str);

    // Get the answer
    int ans = postfixEvaluation(str);

    // Print the answer
    cout << "\nAnswer: " << ans << "\n";
}