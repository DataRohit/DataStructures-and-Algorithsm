#include <iostream>
using namespace std;

int isPrime(int num)
{
    for (int j = 2; j < num; j++)
    {
        if (num % j == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cout
        << "***** FUNCTIONS - PRIME NOS IN RANGE *****" << endl
        << endl;

    int n1, n2;

    cout << "Enter number 1: ";
    cin >> n1;

    cout << "Enter number 2: ";
    cin >> n2;

    for (int i = n1; i < n2; i++)
    {
        if (isPrime(i))
        {
            cout
                << "\n"
                << i << " is a prime number";
        }
    }

    return 0;
}
