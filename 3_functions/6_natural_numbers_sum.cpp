#include <iostream>
using namespace std;

int get_sum(int n)
{
    int sum = (n * (n + 1)) / 2;

    return sum;
}

int main()
{
    cout
        << "***** FUNCTIONS - SUM OF NATURAL NOS *****" << endl
        << endl;

    int n;

    cout << "Enter the value for n: ";
    cin >> n;

    cout << "Sum of first " << n << " natural numbers is " << get_sum(n) << endl;

    return 0;
}
