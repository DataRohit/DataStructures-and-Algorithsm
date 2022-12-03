#include <iostream>
using namespace std;

int main()
{
    cout
        << "***** WHILE LOOP *****"
        << endl
        << endl;

    int n = 0;

    // While loop is entry control loop and checks for condition at the beginning of the loop
    // Loop will continue till the specifiece condition is true
    while (n >= 0)
    {
        cout << "Enter a positive number: ";
        cin >> n;
    }

    // If negative number entered by user print the message
    if (n < 0)
        cout << "\nNegative number entered exiting while loop!";

    return 0;
}
