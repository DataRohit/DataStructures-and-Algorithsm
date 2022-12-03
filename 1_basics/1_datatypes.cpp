// Preprocessor Directive - Used to include header files
#include <iostream>
using namespace std;

// Primitive Datatypes
int main()
{
    cout
        << "***** DATATYPES *****"
        << endl
        << endl;

    // Print size of integer
    int a;
    cout << "Size of int\t: " << sizeof(a) << "\n";

    // Print size of float
    float b;
    cout << "Size of float\t: " << sizeof(b) << "\n";

    // Print size of character
    char c;
    cout << "Size of char\t: " << sizeof(c) << "\n";

    // Print size of boolean
    bool d;
    cout << "Size of bool\t: " << sizeof(d) << "\n";

    // Print size of short int
    short si;
    cout << "Size of short int\t: " << sizeof(si) << "\n";

    // Print size of long int
    long li;
    cout << "Size of long int\t: " << sizeof(li) << "\n";

    return 0;
}
