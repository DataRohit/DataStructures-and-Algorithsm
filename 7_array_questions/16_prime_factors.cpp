#include <iostream>
using namespace std;

void primeFactor(int n)
{
    int prime[n + 1] = {0};

    // Add index as array values
    for (int i = 2; i <= n; i++)
    {
        prime[i] = i;
    }

    // Mark all the multiples of 2 as 2
    for (int i = 4; i <= n; i += 2)
    {
        prime[i] = 2;
    }

    for (int i = 3; i * i <= n; i++)
    {
        // If the number is not marked
        if (prime[i] == i)
        {
            // Check for multiples and mark them with smallest factor
            for (int j = i * i; j <= n; j += i)
            {
                if (prime[j] = i)
                {
                    prime[j] = i;
                }
            }
        }
    }

    // Variable to store the prime factor
    int factor;

    // Find and print the factors
    cout << "The prime factors for " << n << " are:" << endl;
    while (n != 1)
    {
        factor = prime[n];
        cout << factor << " ";
        n /= factor;
    }
} // primeFactor

int main()
{
    // Title of the program
    cout
        << "***** PRIME FACTORS *****" << endl
        << endl;

    // Declare variables
    int n;

    // Take user input
    cout << "Enter a number: ";
    cin >> n;
    cout << endl;

    // Call the primeFactors function
    primeFactor(n);

    return 0;
}
