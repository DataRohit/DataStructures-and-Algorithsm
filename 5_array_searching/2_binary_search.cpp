#include <iostream>
using namespace std;

// Binary Search Algorithm / Code
// Time Complexity - O(log(n))
int binary_search(int arr[], int n, int search)
{
    // Initialize lb and up
    int lb = 0, up = n - 1;

    // Calculate mid using lb and up
    int mid = (lb + up) / 2;

    // Loop until lb is less than or equal to up
    while (up >= lb)
    {
        // If search element is found at mid
        // return the mid index
        if (arr[mid] == search)
            return mid;

        // If search element is greater than mid element
        // update lb to mid + 1
        else if (arr[mid] < search)
            lb = mid + 1;

        // If search element is less than mid element
        // update up to mid - 1
        else
            up = mid - 1;

        // Update mid using lb and up
        mid = (lb + up) / 2;
    }

    // If search element is not found return -1
    if (up <= lb)
        return -1;
}

int main()
{
    // Title of the program
    cout
        << "***** BINARY SEARCH - SORTED ARRAY *****" << endl
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

    // Call the binary search function and store the result
    int result = binary_search(arr, n, search);

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
