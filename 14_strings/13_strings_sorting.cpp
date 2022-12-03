#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    // Title of the program
    cout
        << "***** STRING SORTING *****"
        << endl
        << endl;

    // Declare string variable
    string s;

    // Input string
    cout << "Enter a string: ";
    getline(cin, s);

    // Sort string
    sort(s.begin(), s.end());

    // Output sorted string
    cout << "Sorted string: " << s << endl;
}
