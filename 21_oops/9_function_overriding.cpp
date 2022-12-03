#include <iostream>
using namespace std;

/*
 *  Virtual function lets us redefine
 *  the inherited member function from the base class
 *  in the derived class to achive polymorphism.
 */

// Base Class
class Base
{
public:
    virtual void
    print()
    {
        cout << "Base Class's Print Function." << endl;
    }

    void
    display()
    {
        cout << "Base Class's Display Function." << endl;
    }
};

// Derived Class
class Derived : public Base
{
public:
    void
    print()
    {
        cout << "Derived Class's Print Function." << endl;
    }

    void
    display()
    {
        cout << "Derived Class's Display Function." << endl;
    }
};

int main()
{
    // Title of the program
    cout
        << "***** OOPS - POLYMORPHISM - FUNCTION OVERRIDING *****"
        << endl
        << endl;

    // Create a Base Class Object
    Base *basePtr;

    // Create a Derived Class Object
    Derived derivedObj;

    // Assign the address of derivedObj to basePtr
    basePtr = &derivedObj;

    // Call the print() function using basePtr
    basePtr->print();

    // Call the display() function using basePtr
    basePtr->display();

    return 0;
}
