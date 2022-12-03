#include <iostream>
using namespace std;

/*
 *  Class A -> Parent Class for B and C
 *  Class B -> Parent Class for B (Child Class of A)
 *
 *  Class C -> Child Class
 *
 *  Multi Level Inheritance
 */

class A
{
public:
    void
    Afunc()
    {
        cout << "Func A" << endl;
    }
};

class B : public A
{
public:
    void
    Bfunc()
    {
        cout << "Func B" << endl;
    }
};

class C : public B
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
        << "***** OOPS - MULTI LEVEL INHERITANCE *****"
        << endl
        << endl;

    // Creating object of child class
    C obj;

    // Calling function inherited from class A
    obj.Afunc();

    // Calling function inherited from class B
    obj.Bfunc();

    // Calling the function of child class
    obj.Cfunc();

    return 0;
}
