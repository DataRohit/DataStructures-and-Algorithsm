#include <iostream>
using namespace std;

// Create a class for handling complex numbers
class Complex
{
private:
    int real, imag; // Private data members

public:
    Complex(int r = 0, int i = 0) // Constructor
    {
        real = r;
        imag = i;
    }

    // Overload the + operator
    Complex
    operator+(Complex const &obj)
    {
        // Complex number to store the result
        Complex res;

        // Add the imaginary part
        res.imag = imag + obj.imag;

        // Add the real parts
        res.real = real + obj.real;

        // Return the results
        return res;
    }

    // Display the complex number
    void
    display()
    {
        cout << "Addeded Complex Number: " << real << " + " << imag << "i" << endl;
    }
};

int main()
{
    // Title of the program
    cout
        << "***** OOPS - POLYMORPHISM - OPERATOR OVERLOADING *****"
        << endl
        << endl;

    // Initialize the complex numbers
    Complex c1(10, 5), c2(2, 4);

    // Add two complex numbers
    Complex c3 = c1 + c2;

    // Display the results
    c3.display();

    return 0;
}
