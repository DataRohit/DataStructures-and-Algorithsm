#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Title of the program
    cout
        << "***** STRING ERASE *****"
        << endl
        << endl;

    // Declare variables
    string s1;

    // Ask user for input
    cout << "Enter a string: ";
    getline(cin, s1);
    cout << endl;

    // Erase variables
    int startIndex, numChar;
    cout << "Enter start index: ";
    cin >> startIndex;
    cout << "Enter number of characters to erase: ";
    cin >> numChar;

    // Erase characters
    s1.erase(startIndex, numChar);

    // Display result
    cout
        << endl
        << "Result: " << s1
        << endl;

    return 0;
} // main
