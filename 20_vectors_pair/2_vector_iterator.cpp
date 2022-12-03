#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Title of the program
    cout
        << "***** VECTORS BASICS *****"
        << endl
        << endl;

    // Initialize and empty vector of integers
    vector<int> v1;

    // Add elements to the vector
    v1.push_back(10);

    // Add more elements to the vector
    v1.push_back(20);

    // Add more elements to the vector
    v1.push_back(30);

    // Print elements of vector using iterator
    cout << "Vector elements are: " << endl;

    // Using iterator
    vector<int>::iterator it;

    // Iterate over the vector
    for (it = v1.begin(); it != v1.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}
