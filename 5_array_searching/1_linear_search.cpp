#include <iostream>
using namespace std;

// Linear Search Algorithm / Code
// Time Complexity - O(n)
int linear_search(int arr[], int n, int search)
{
    // i variable is used to traverse the array
    int i;

    // Traverse the array
    for (i = 0; i < n; i++)
    {
        // If the element is found, return the index
        if (arr[i] == search)
            return i;
    };

    // If the element is not found, return -1
    if (i == n)
        return -1;
}

int main()
{
    // Title of the program
    cout
        << "***** LINEAR SEARCH *****" << endl
        << endl;

    // Take input for size of array
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Declare array
    int arr[n];

    // Take input for array elements
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element for index " << i << " : ";
        cin >> arr[i];
    }

    // Display the stored array
    cout
        << endl
        << "The stored array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Take input for element to be searched
    int search;
    cout
        << endl
        << endl
        << "Enter the element to be searched: ";
    cin >> search;

    // Call the linear search function and store the result
    int result = linear_search(arr, n, search);

    // Display the result
    if (result == -1)
    {
        cout << "Element not found";
    }
    else
    {
        cout << "Element found at index " << result;
    }

    return 0;
} // main
