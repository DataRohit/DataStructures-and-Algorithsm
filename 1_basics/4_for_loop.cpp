#include <iostream>
using namespace std;

// Sum of n natural numbers
int main()
{
    cout
        << "***** FOR LOOP *****"
        << endl
        << endl;

    int n;
    cout << "Enter value for n: ";
    cin >> n;

    int sum = 0;

    // For loop is entry controlled loop and checks for condition at the beginning of the loop
    // It accepts 3 arguments - initialization, condition and increment/decrement
    // The increment/decrement takes place at the end of the every iteration
    for (int i = 0; i <= n; i++)
    {
        sum += i;
    }

    // Print the sum of n natural numbers
    cout << "Sum of n natural number is: " << sum << endl;

    return 0;
}
