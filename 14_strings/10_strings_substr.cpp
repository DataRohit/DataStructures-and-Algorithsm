#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Title of the program
    cout
        << "***** STRING - SUB STRING *****"
        << endl
        << endl;

    // Declare variables
    string s1;

    // Take user input
    cout << "Enter a string: ";
    getline(cin, s1);
    cout << endl;

    // Declare variables
    int start, end;

    // Take user input
    cout << "Enter start index: ";
    cin >> start;
    cout << "Enter end index: ";
    cin >> end;

    // Display result
    cout
        << endl
        << "Sub string: " << s1.substr(start, end)
        << endl;

    return 0;
}
