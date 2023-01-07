#include <bits/stdc++.h>
using namespace std;

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

// Function to get the N'th Catalan Number
int catalan(int n)
{
    // Base Case
    if (n <= 1)
    {
        return 1;
    }

    // Var to store the result
    int res = 0;

    // Loop from 0 to n-1 and add to the result
    for (int i = 0; i <= n - 1; i++)
    {
        // Update the result
        res += catalan(i) * catalan(n - i - 1);
    }

    return res;
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** N'th CATALAN NUMBERS *****\n\n";
    printLine();

    // Print first 10 Catalan Numbers
    cout << "First 10 Catalan Numbers are: \n";
    for (int i = 0; i < 10; i++)
    {
        cout << catalan(i) << " ";
    }
    cout << "\n\n";
}