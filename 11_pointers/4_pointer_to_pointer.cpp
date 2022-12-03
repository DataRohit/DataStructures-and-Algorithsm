#include <iostream>
using namespace std;

int main()
{
    // Title for the program
    cout
        << "***** POINTER TO POINTER *****"
        << endl
        << endl;

    // Declare a variable
    int a = 10;

    // Declare a pointer variable storing address of a
    int *p = &a;

    // Print value of *p and p
    cout << "Value of *p\t: " << *p << endl;
    cout
        << "Value of p\t: "
        << p
        << endl
        << endl;

    // Declare a pointer to pointer variable storing address of p
    int **q = &p;

    // Print value of **q, *q and q
    cout << "Value of **q\t: " << **q << endl;
    cout << "Value of *q\t: " << *q << endl;
    cout << "Value of q\t: " << q << endl;

    return 0;
}
