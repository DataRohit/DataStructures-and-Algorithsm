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
    cout << "***** LONGEST NO REPEAT SUBSTRING *****\n\n";
    printLine();

    // Take user input for the string
    string str;
    cout << "Enter the String: ";
    getline(cin, str);

    // Vector to store the string items
    vector<int> dict(256, -1);

    // Initialize vars
    int maxLen = 0; // Lenght of longest required substring
    int start = -1; // The start pointer for the string

    // Iterate over string
    for (int i = 0; i < str.size(); i++)
    {
        // Old position greater than start
        if (dict[str[i]] > start)
        {
            // Update the start
            start = dict[str[i]];
        }

        // Update our vector
        dict[str[i]] = i;

        // Update our maxlen
        maxLen = max(maxLen, i - start);
    }

    cout
        << "\nThe lenght of longest substring without repeating elements is:\n"
        << maxLen << "\n\n";
}