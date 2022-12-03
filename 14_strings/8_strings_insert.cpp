#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Title of the program
    cout
        << "***** STRING INSERTION *****"
        << endl
        << endl;

    // Declare variables
    string s1, s2;
    int insertIndex;

    // Get user input
    cout << "Enter a string: ";
    getline(cin, s1);
    cout << "Enter string to insert: ";
    getline(cin, s2);
    cout << "Enter index to insert: ";
    cin >> insertIndex;

    // Insert the key into string at given index
    s1.insert(insertIndex, s2);

    // Display result
    cout
        << endl
        << "String after insertion: " << s1
        << endl;

    return 0;
}
