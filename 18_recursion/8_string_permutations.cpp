#include <iostream>
using namespace std;

// Function to print all the permutations of str
void permutation(string s, string ans)
{
    // If string is empty print the answer and return
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    // Loop over the string
    for (int i = 0; i < s.length(); i++)
    {
        // Get the character at ith index
        char ch = s[i];

        // Get the left substring + right substring
        string ros = s.substr(0, i) + s.substr(i + 1);

        // Recursively call the function
        permutation(ros, ans + ch);
    }
}

int main()
{
    // Title of the program
    cout
        << "***** ALL POSSIBLE STRING PERMUTATIONS *****"
        << endl
        << endl;

    // Input string
    string s;
    cout << "Enter a string: ";
    cin >> s;

    // Print the permutations
    cout
        << endl
        << "All possible permutations are: "
        << endl;

    // Call the functions
    permutation(s, "");

    return 0;
}
