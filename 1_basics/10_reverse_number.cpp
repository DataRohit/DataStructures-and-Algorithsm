#include <iostream>
using namespace std;

int main()
{
    cout
        << "***** REVERSE A NUMBER *****"
        << endl
        << endl;

    int n;
    cout << "Enter a number: ";
    cin >> n;

    int rev = 0;

    while (n > 0)
    {
        rev = (rev * 10) + (n % 10);
        n = n / 10;
    }

    cout << "Reversed number is: " << rev << endl;

    return 0;
}
