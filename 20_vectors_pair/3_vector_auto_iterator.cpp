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

    // Traverse the vector using auto
    for (auto element : v1)
    {
        cout << element << " ";
    }

    return 0;
}
