#include <iostream>
using namespace std;

int main()
{
    // Title of the program
    cout
        << "***** PAIR BASICS  *****"
        << endl
        << endl;

    // Initializing the (int, char) pair
    pair<int, char> p1;

    // Adding data to pair
    p1.first = 10;
    p1.second = 'A';

    // Print the pair
    cout << "Pair elements are: " << endl;
    cout << p1.first << " " << p1.second << endl;

    return 0;
}
