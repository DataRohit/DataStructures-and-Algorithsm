#include <iostream>
using namespace std;

/*
 *  Class A -> Parent Class
 *  Class B -> Parent Class
 *
 *  Class C -> Child Class
 *
 *  Multiple Inheritance
 *
 *  Public and Protected Members of Parent Class will be inherited to Child Class
 *  Private Members of Parent Class will not be inherited to Child Class
 */

// Parent class
class A
{
public:
    void
    Afunc()
    {
        cout << "Func A" << endl;
    }
};

// Parent class
class B
{
public:
    void
    Bfunc()
    {
        cout << "Func B" << endl;
    }
};

// Child class
class C : public A, public B
{
public:
    void
    Cfunc()
    {
        cout << "Func C" << endl;
    }
};

int main()
{
    // Title of the program
    cout
        << "***** OOPS - MULTIPLE INHERITANCE *****"
        << endl
        << endl;

    // Creating object of child class
    C obj;

    // Calling function inherited from class A
    obj.Afunc();

    // Calling function inherited from class B
    obj.Bfunc();

    // Calling function of child class
    obj.Cfunc();

    return 0;
}
