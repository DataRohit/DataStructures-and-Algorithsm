#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Title of the program
    cout
        << "***** STRING CLEAR FUNCTION *****"
        << endl
        << endl;

    // Declare a string variable
    string str;

    // Take user input for string
    cout << "Enter a string: ";
    getline(cin, str);

    // Print the string
    cout
        << endl
        << "String before clearing: " << str
        << endl;

    // Clear the string
    str.clear();

    // Print the string
    cout
        << endl
        << "String after clearing: " << str
        << endl;

    return 0;
}
