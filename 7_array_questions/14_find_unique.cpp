#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // Title of the program
    cout
        << "***** UNIQUE VALUES *****"
        << endl
        << endl;

    // Initialize a array
    int n = 10;
    int arr[n] = {2, 4, 1, 2, 3, 4, 5, 6, 2, 4};

    // Array before sorting
    cout << "Array Before Sorting: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    // Sort the array
    sort(arr, arr + n);

    // Array after sorting
    cout
        << endl
        << endl
        << "Array After Sorting: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    // Find unique elements
    cout
        << endl
        << endl
        << "Unique elements in array are: ";
    for (int i = 0; i < n; i++)
    {
        if ((arr[i - 1] != arr[i]) && (arr[i] != arr[i + 1]))
        {
            cout << arr[i] << ", ";
        }
    }

    return 0;
} // main
