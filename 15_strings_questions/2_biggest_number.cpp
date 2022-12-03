#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    // Title of the program
    cout
        << "***** FORM BIGGEST NUMBER *****"
        << endl
        << endl;

    // Declare string variable
    string s;

    // Input string
    cout << "Enter a numeric string: ";
    getline(cin, s);

    /*
     *  // Sort string - ascending order
     *  sort(s.begin(), s.end());
     *
     *  // Reverse the sorted string - descending order
     *  reverse(s.begin(), s.end());
     */

    // Sort string - descending order
    sort(s.begin(), s.end(), greater<int>());

    // Output the biggest number
    cout
        << "Biggest number: " << s
        << endl;
}
