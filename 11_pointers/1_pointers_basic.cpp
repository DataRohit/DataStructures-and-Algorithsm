#include <iostream>
using namespace std;

int main()
{
    // Title for the program
    cout
        << "***** POINTER BASICS *****"
        << endl
        << endl;

    // Declare a variable
    int a = 10;

    // Declare a pointer variable storing address of a
    int *p = &a;

    // Print value of a
    cout << "a\t= " << a << endl;

    // Print address of a
    cout << "&a\t= " << &a << endl;

    // Print value of p (address of a)
    cout << "p\t= " << p << endl;

    // Print value at address p (value of a)
    cout << "*p\t= " << *p << endl;

    // Print address of p
    cout << "&p\t= " << &p << endl;

    return 0;
}
