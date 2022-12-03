#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

// Function to reverse the string
void reveserSentence(string s)
{
    // Initialize our stack
    stack<string> st;

    // Loop over our input string
    for (int i = 0; i < s.length(); i++)
    {
        // Var to store word in sentence
        string word;

        // If space encountered word ended
        while (s[i] != ' ' && i < s.length())
        {
            // Add the each character to word var
            word += s[i];

            // Update the index
            i++;
        }

        // Push the word onto the stack
        st.push(word);
    }

    // Print the reversed sentence
    cout << "\nThe reversed sentences is:\n";

    // Loop through stack to print each word
    while (!st.empty())
    {
        // Print the word at to top of stack
        cout << st.top() << " ";

        // Pop the top word from stack
        st.pop();
    }

    // Add a line break
    cout << "\n";
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** STACK STRING REVERSING *****\n\n";
    printLine();

    // Declare a string variable
    string str;

    // Take user input for string
    cout << "Enter a string:\n";
    getline(cin, str);

    // Call the reverseSentece function
    reveserSentence(str);
}
