#include <iostream>
using namespace std;

int main()
{
    cout
        << "***** ARMSTRONG NUMBER *****"
        << endl
        << endl;

    int n;
    cout << "Enter a number: ";
    cin >> n;

    int original_num = n;

    int sum = 0;

    while (n > 0)
    {
        int last_digit = n % 10;
        sum += last_digit * last_digit * last_digit;
        n = n / 10;
    }

    if (sum == original_num)
    {
        cout << original_num << " is an armstrong number";
    }
    else
    {
        cout << original_num << " is not an armstrong number";
    }

    return 0;
}
