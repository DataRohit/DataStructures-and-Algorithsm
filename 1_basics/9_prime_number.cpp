#include <iostream>
using namespace std;

int main()
{
    cout
        << "***** PRIME OR COMPOSITE *****"
        << endl
        << endl;

    int n;
    cout << "Enter a number: ";
    cin >> n;

    int factors = 0;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            cout << n << " is a composite number" << endl;
            factors++;
            break;
        }
    }
    if (factors == 0)
    {
        cout << n << " is a prime number" << endl;
    }

    return 0;
}
