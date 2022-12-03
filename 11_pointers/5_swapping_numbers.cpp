#include <iostream>
using namespace std;

// Function to swap the numbers
void swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

int main()
{
    // Title for the program
    cout
        << "***** SWAPPING NUMBERS USING POINTER *****"
        << endl
        << endl;

    // Declaring variables
    int a = 5;
    int b = 10;

    // Values before swapping
    cout << "Before swapping: " << endl;
    cout << "a = " << a << endl;
    cout
        << "b = " << b
        << endl
        << endl;

    // Swapping numbers using pointer
    swap(&a, &b);

    // Values after swapping
    cout << "After swapping: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}
