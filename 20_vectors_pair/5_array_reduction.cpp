#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 *  1. Sort the array in ascending order
 *  2. Sort the array using the value
 */
bool myCompare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first < p2.first;
}

int main()
{
    // Title of the program
    cout
        << "***** ARRAY REDUCTION USING PAIRS *****"
        << endl
        << endl;

    // Initializing an array with elements
    int arr[] = {10, 16, 7, 14, 5, 3, 2, 9};

    // Print the array
    cout << "The array before reduction is: " << endl;
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        cout << arr[i] << " ";
    }

    // Initializing a vector of pairs
    vector<pair<int, int>> v;

    // Traverse the array
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        /*
         *  1. Make a pair of element and its index
         *  2. Push it back to the vector
         */
        v.push_back(make_pair(arr[i], i));
    }

    // Sort our vector
    sort(v.begin(), v.end(), myCompare);

    // Traverse the vector
    for (int i = 0; i < v.size(); i++)
    {
        // Update the array
        arr[v[i].second] = i;
    }

    // Print the array
    cout
        << endl
        << endl
        << "The array after reduction is: "
        << endl;
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
} // main
