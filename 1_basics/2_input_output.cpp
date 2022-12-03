#include <iostream>
using namespace std;

int main()
{
    cout
        << "***** INPUT AND OUTPUT *****"
        << endl
        << endl;

    int amount1;
    // Output to console/terminal
    cout << "Enter amount 1\t: ";

    // Input from console/terminal and store to variable
    cin >> amount1;

    int amount2;
    // Output to console/terminal
    cout << "Enter amount 2\t: ";

    // Input from console/terminal and store to variable
    cin >> amount2;

    // Calculating the sum of two amounts
    int sum = amount1 + amount2;

    // Output the sum to the console/terminal
    cout << "The total amount is : " << sum;

    return 0;
}
