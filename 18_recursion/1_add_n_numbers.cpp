#include <iostream>
using namespace std;

// Recursive function to return sum of n numbers
int getSum(int n)
{
    // Base case
    if (n == 0)
    {
        return 0;
    }

    // Recursive case
    return n + getSum(n - 1);
}

int main()
{
    // Title of the program
    cout
        << "***** GET SUM OF N NUMBERS *****"
        << endl
        << endl;

    // Enter the value for n
    int n;
    cout << "Enter value for n: ";
    cin >> n;

    // Print the result
    cout
        << endl
        << "The sum of first " << n << " numbers is: "
        << getSum(n)
        << endl;

    return 0;
}
