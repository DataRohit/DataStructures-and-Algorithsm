#include <iostream>
using namespace std;

int fibonacciNum(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return fibonacciNum(n - 1) + fibonacciNum(n - 2);
    }
}

int main()
{
    // Title of the program
    cout
        << "***** Nth FIBONACCI NUMBER *****"
        << endl
        << endl;

    // Input
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    // Output
    cout
        << endl
        << "The " << n << "th Fibonacci number is " << fibonacciNum(n)
        << endl;

    return 0;
}
