#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Title of the program
    cout
        << "***** STRING EMPTY *****"
        << endl
        << endl;

    // Declare variables
    string s1;

    // Ask user for input
    cout << "Enter a string: ";
    getline(cin, s1);
    cout << endl;

    // Check if string is empty
    if (s1.empty())
    {
        cout << "String is empty" << endl;
    }
    else
    {
        cout << "String is not empty" << endl;
    }

    return 0;
}
