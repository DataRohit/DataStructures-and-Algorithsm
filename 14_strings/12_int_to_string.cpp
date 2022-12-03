#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Title of the program
    cout
        << "***** INTEGER TO STRING *****"
        << endl
        << endl;

    // Variable declaration
    int n1;

    // User entry
    cout << "Enter an integer: ";
    cin >> n1;

    // Convert integer to string
    string s1 = to_string(n1);

    // Display result
    cout
        << endl
        << "Integer: " << n1
        << endl
        << "String: " << s1
        << endl;

    return 0;
}
