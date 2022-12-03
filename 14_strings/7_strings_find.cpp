#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Title of the program
    cout
        << "***** STRING SEARCHING *****"
        << endl
        << endl;

    // Declare variables
    string s1, key;

    // Ask user for input
    cout << "Enter a string: ";
    getline(cin, s1);
    cout << endl;

    cout << "Enter a key to search: ";
    getline(cin, key);
    cout << endl;

    // Find key
    int startIndex = s1.find(key);

    // Display result
    if (startIndex > 0)
    {
        cout << "Search element found at index " << startIndex << endl;
    }
    else
    {
        cout << "Search element not found" << endl;
    }

    return 0;
}
