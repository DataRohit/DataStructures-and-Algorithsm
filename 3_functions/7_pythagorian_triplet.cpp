#include <iostream>
using namespace std;

bool pythagorian_triplet(int n1, int n2, int n3)
{
    int a = max(n1, max(n2, n3));

    int b, c;

    if (a == n1)
        b = n2, c = n3;
    else if (a == n2)
        b = n1, c = n3;
    else
        b = n1, c = n2;

    if (a * a == b * b + c * c)
        return true;
    else
        return false;
}

int main()
{
    cout
        << "***** FUNCTIONS - PYTHAGORIAN TRIPLET *****" << endl
        << endl;

    int n1, n2, n3;

    cout << "Enter the value for n1: ";
    cin >> n1;

    cout << "Enter the value for n2: ";
    cin >> n2;

    cout << "Enter the value for n3: ";
    cin >> n3;

    if (pythagorian_triplet(n1, n2, n3))
    {
        cout << "The numbers " << n1 << ", " << n2 << " and " << n3 << " form a pythagorian triplet" << endl;
    }
    else
    {
        cout << "The numbers " << n1 << ", " << n2 << " and " << n3 << " do not form a pythagorian triplet" << endl;
    }

    return 0;
}
