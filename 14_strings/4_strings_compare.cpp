#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Title of the program
    cout
        << "***** STRING COMPARE *****"
        << endl
        << endl;

    // Declare variables
    string s1, s2;

    // Get input from user
    cout << "Enter first string: ";
    getline(cin, s1);

    cout << "Enter second string: ";
    getline(cin, s2);

    // Compare the strings
    int result = s1.compare(s2);

    // Display the result
    cout
        << endl
        << "Result: " << result
        << endl;
    if (result == 0)
    {
        cout << "Both strings are equal." << endl;
    }
    else if (result < 0)
    {
        cout << "First string is less than second string." << endl;
    }
    else
    {
        cout << "First string is greater than second string." << endl;
    }

    return 0;
} // main
