#include <iostream>
using namespace std;

// Selection Sorting

/*
 * Find the minimum element in unsorted array and swap it with the first element
 * Bring the smallest element in the array to the beginning
 *
 * Time Complexity - θ(n^2)
 */

int main()
{
    // Title of the program
    cout
        << "***** SELECTION SORT *****" << endl
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

    // Selection Sort Algorithm
    for (int i = 0; i < n - 1; i++)
    {
        // Checking each element with the rest of the elements after it
        for (int j = i + 1; j < n; j++)
        {
            // If the element is smaller than the current element, swap them
            // Moving the smallest element to the front
            if (arr[j] < arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
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
