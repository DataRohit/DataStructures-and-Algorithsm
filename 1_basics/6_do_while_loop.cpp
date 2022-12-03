#include <iostream>
using namespace std;

int main()
{
    cout
        << "***** DO-WHILE LOOP *****"
        << endl
        << endl;

    int n = 0;

    // do-while is exit controlled loop where the condition is checked at the end of the loop
    // do-while loop will execute at least once
    do
    {
        // Print the number
        cout << "Number: " << n << "\n\n";

        // Accept the number from user
        cout << "Enter a positive number: ";
        cin >> n;
    } while (n >= 0);

    if (n < 0)
        cout << "\nNegative number entered exiting while loop!";

    return 0;
}
