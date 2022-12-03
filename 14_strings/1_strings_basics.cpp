#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Title of the program
    cout
        << "***** STRING INPUT / OUTPUT *****"
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
        << "You entered: " << str
        << endl;

    return 0;
}
