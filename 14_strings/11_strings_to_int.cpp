#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Title of the program
    cout
        << "***** STRING TO INTEGER *****"
        << endl
        << endl;

    // Declare variables
    string s1;

    // Take user input
    cout << "Enter a string with all numbers: ";
    getline(cin, s1);
    cout << endl;

    // Convert string to integer
    int n1 = stoi(s1);

    // Display result
    cout
        << "String: " << s1
        << endl
        << "Integer: " << n1
        << endl;

    return 0;
}
