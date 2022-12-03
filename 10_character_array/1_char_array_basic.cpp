#include <iostream>
using namespace std;

int main()
{
    // Title for the program
    cout
        << "***** CHARACTER ARRAY BASIC *****"
        << endl
        << endl;

    // Initializing a character array of given len
    char name[10];

    // Take user input for the array
    cout << "Enter your name: ";
    cin >> name;

    // Print the array
    cout
        << endl
        << "Your name is " << name << endl;

    return 0;
}
