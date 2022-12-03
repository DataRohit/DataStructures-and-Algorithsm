#include <iostream>
using namespace std;

// Bubble Sorting

/*
 *  Repeatedly swap two adjacent elements if they are in wrong order
 *  Bring the largest element in the array to the end
 *
 *  Time Complexity - θ(n^2)
 */

int main()
{
    // Title of the program
    cout
        << "***** BUBBLE SORT *****" << endl
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

    // Iter variable to keep track of the number of passes
    int iter = 1;

    // Bubble Sort Algorithm
    while (iter < n)
    {
        // Iterate over the unsorted array
        for (int i = 0; i < n - iter; i++)
        {
            // Moving the largest element to the end
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }

        // Increment the iter variable
        iter++;
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
