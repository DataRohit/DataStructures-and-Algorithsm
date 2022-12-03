#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Title of the program
    cout
        << "***** STRING LENGTH *****"
        << endl
        << endl;

    // Declare variables
    string s1;

    // Take user input
    cout << "Enter a string: ";
    getline(cin, s1);
    cout << endl;

    // Display the size / length of array
    cout << "Length of string: " << s1.length() << endl;
    cout << "Size of string: " << s1.size() << endl;

    return 0;
}
