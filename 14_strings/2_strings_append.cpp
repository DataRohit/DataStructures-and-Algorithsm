#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Title of the program
    cout
        << "***** STRING APPENDING *****"
        << endl
        << endl;

    /* ADD TWO STRINGS - START */
    string s1 = "Hello";
    string s2 = "World";

    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout
        << "s1 + s2 = " << s1 + " " + s2
        << endl
        << endl;
    /* ADD TWO STRINGS - END */

    /* APPEDNING STRING - START */
    s1 = "Hello";
    s2 = "World";

    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;

    s1.append(" " + s2);

    cout
        << "s1.append(' ' + s2)"
        << endl
        << "s1 = " << s1
        << endl;
    /* APPEDNING STRING - END */

    return 0;
} // main
