#include <iostream>
using namespace std;

// Quick Sorting

/*
 *  1. Pick a pivot element
 *  2. Partition the array into two parts
 *  3. Sort the two parts separately
 *
 *  Best Time Complexity - θ(n log(n))
 *  Worst Time Complexity - θ(n^2)
 */

// Function for printing the array
void printArray(int arr[], int n)
{
    // Iterate and print every element
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// Function for swapping the values
void swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

// Function for partitioning the array
int partition(int arr[], int l, int r)
{
    // Initialize pivot element
    int pivot = arr[r];

    // Initialize index of smaller element
    int i = l - 1;

    // Iterate and swap
    for (int j = l; j < r; j++)
    {
        // If current element is smaller than or equal to pivot
        if (arr[j] < pivot)
        {
            // Increment index of smaller element
            i++;

            // Swap the elements
            swap(&arr[j], &arr[i]);
        }
    }

    // Put the pivot element in its correct position
    swap(&arr[i + 1], &arr[r]);

    // Return the index of pivot element
    return i + 1;
}

// Function for quick sorting logic
void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        /*
         *  1. Find the pivot element
         *  2. Put the pivot element in its correct position
         *  3. Return the pivot element index
         */
        int pi = partition(arr, l, r);

        // Recursively sort the elements before pivot element
        quickSort(arr, l, pi - 1);

        // Recursively sort the elements after pivot element
        quickSort(arr, pi + 1, r);
    }
}

int main()
{
    // Title of the program
    cout
        << "***** QUICK SORT *****"
        << endl
        << endl;

    // Take input for size of array
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Declare array
    int arr[n];

    // Take input for array elements
    cout
        << endl
        << "Enter the array elements: "
        << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Display the stored array
    cout
        << endl
        << "The Stored Array is: " << endl;
    printArray(arr, n);

    // Call the quick sort function
    quickSort(arr, 0, n - 1);

    // Display the sorted array
    cout
        << endl
        << endl
        << "The Sorted Array is: " << endl;
    printArray(arr, n);

    return 0;
} // main
