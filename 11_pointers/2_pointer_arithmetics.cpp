#include <iostream>
using namespace std;

// NOTE: The supported arithmetic operators are -> ++, --, +, -

int main()
{
    // Title for the program
    cout
        << "***** POINTER ARITHMETIC *****"
        << endl;

    // Declare a variable
    int a = 10;

    // Declare a pointer variable storing address of a
    int *p = &a;

    // Print value of p (address of a)
    cout
        << endl
        << p
        << endl;

    // Increment the pointer value
    p++;

    // Print value of p (address of a)
    cout
        << endl
        << p
        << endl;

    return 0;
}
