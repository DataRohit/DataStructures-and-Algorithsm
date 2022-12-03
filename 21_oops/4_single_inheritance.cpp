#include <iostream>
using namespace std;

/*
 *  Class A -> Parent Class
 *  Class B -> Child Class
 *
 *  Single Inheritance
 *
 *  Public and Protected Members of Parent Class will be inherited to Child Class
 *  Private Members of Parent Class will not be inherited to Child Class
 */

// Parent class
class A
{
public:
    void
    func()
    {
        cout << "Inherited" << endl;
    }
};

// Child class
class B : public A
{
};

int main()
{
    // Title of the program
    cout
        << "***** OOPS - SINGLE INHERITANCE *****"
        << endl
        << endl;

    // Creating object of child class
    B obj;

    // Calling the func function from child class
    obj.func();

    return 0;
}
