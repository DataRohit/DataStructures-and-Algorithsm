#include <iostream>
using namespace std;

// Insertion Sorting

/*
 *  Insert an element from unsorted to its correct position in sorted array
 *
 *  Time Complexity - θ(n^2)
 */

int main()
{
    // Title of the program
    cout
        << "***** INSERTION SORT *****" << endl
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
        << "The Stored Array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Insertion Sort Algorithm
    for (int i = 1; i < n; i++)
    {
        // Store the current element
        int current = arr[i];

        // Store the index of the previous element
        int j = i - 1;

        // If the previous element is greater than the current element
        while (arr[j] > current && j >= 0)
        {
            // Shift the previous element to the next position
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert the current element to its correct position
        arr[j + 1] = current;
    }

    // Display the sorted array
    cout
        << endl
        << endl
        << "The Sorted Array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
} // main
