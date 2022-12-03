#include <iostream>
using namespace std;

int main()
{
    cout
        << "***** CONDITIONAL STATEMENTS *****"
        << endl
        << endl;

    int age;

    cout << "Enter your age\t: ";
    cin >> age;

    if (age >= 21)
    {
        cout << "You are eligible to vote and contest elections";
    }
    else if (age >= 18 && age < 21)
    {
        cout << "You are eligible to vote";
    }
    else
    {
        cout << "You are not eligible to vote";
    }

    return 0;
}
