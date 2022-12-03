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

    // Iterate over the vector to print elements
    cout << "Vector elements are: " << endl;
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }

    return 0;
}
