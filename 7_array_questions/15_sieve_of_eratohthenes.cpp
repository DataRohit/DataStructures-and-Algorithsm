#include <iostream>
using namespace std;

void primeSieve(int n)
{
    int prime[n + 1] = {0};

    for (int i = 2; i <= n; i++)
    {
        // If a number is prime
        if (prime[i] == 0)
        {
            // Marking multiples of prime numbers
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = 1;
            }
        }
    }

    // Printing the prime numbers
    cout << "Prime Numbers from 2 to " << n << " are: " << endl;
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            cout << i << " ";
        }
    }
}

int main()
{
    // Title of the program
    cout
        << "***** SIEVE OF ERATOHTHENES - GET ALL PRIME NUMBERS *****"
        << endl
        << endl;

    // Declare variables
    int n;

    // Take user input
    cout << "Enter the number of whole numbers: ";
    cin >> n;
    cout << endl;

    // Call the primeSieve functino
    primeSieve(n);

    return 0;
}
