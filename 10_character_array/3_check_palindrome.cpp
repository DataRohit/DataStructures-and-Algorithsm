#include <iostream>
using namespace std;

int main()
{
    // Title for the program
    cout
        << "***** CHECK PALINDROMIC STRING *****"
        << endl
        << endl;

    // Take user input for the lenght of character array
    int n;
    cout << "Enter the length of the string: ";
    cin >> n;

    // Initializing a character array
    char arr[n + 1];

    // Take user input for the array
    cout
        << endl
        << "Enter the string: ";
    cin >> arr;

    // Check palindrome
    bool isPalindrome = true;

    // Iterate over the array
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr[n - i - 1])
        {
            isPalindrome = false;
            break;
        }
    }

    // Print the result
    if (isPalindrome)
        cout
            << endl
            << "The string is palindrome." << endl;
    else
        cout
            << endl
            << "The string is not palindrome." << endl;

    return 0;
} // main
