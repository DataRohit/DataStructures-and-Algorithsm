#include <iostream>
using namespace std;

// Descening order
void desc(int n)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        // Print while going up the stack
        cout << n << " ";
        desc(n - 1);
    }
}

// Ascending order
void asc(int n)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        // Print while going down the stack
        asc(n - 1);
        cout << n << " ";
    }
}

int main()
{
    // Title of the program
    cout
        << "***** GET N NUMBERS *****"
        << endl
        << endl;

    // Get the number
    int n;
    cout << "Enter the number: ";
    cin >> n;

    // Descending Order
    cout
        << endl
        << "Descending Order: "
        << endl;
    desc(n);

    // Ascending Order
    cout
        << endl
        << endl
        << "Ascending Order: "
        << endl;
    asc(n);

    return 0;
}
