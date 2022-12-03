#include <iostream>
using namespace std;

// Function Overloading
class FunctionOverloading
{
public:
    // Function without parameters
    void
    func()
    {
        cout
            << "Function without arguments."
            << endl;
    }

    // Function with same name but different parameters
    void
    func(int a)
    {
        cout
            << "Function with int argument."
            << endl;
    }

    // Function with same name but different parameters
    void
    func(double b)
    {
        cout
            << "Function with double argument."
            << endl;
    }
};

int main()
{
    // Title of the program
    cout
        << "***** OOPS - POLYMORPHISM - FUNCTION OVERLOADING *****"
        << endl
        << endl;

    // Create object of class FunctionOverloading
    FunctionOverloading obj;

    // Call function without parameters
    obj.func();

    // Call function with int parameter
    obj.func(10);

    // Call function with double parameter
    obj.func(10.5);

    return 0;
}
