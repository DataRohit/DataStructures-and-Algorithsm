#include <iostream>
using namespace std;

// DNF Sorting

/*
 *  1. Check value of arr[mid]
 *  2. If 0, swap with arr[low] and increment both low and mid
 *  3. If 1, increment mid
 *  4. If 2, swap with arr[high] and decrement high
 *
 *  Time Complexity - O(n)
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

// Function for swapping
void swap(int *a, int *b)
{
    // Swap the values using pointer
    int temp = *a;

    *a = *b;
    *b = temp;
}

// Function for DNF Sorting
void dnfSort(int arr[], int n)
{
    // Initialize required variables
    int low = 0;
    int mid = 0;
    int high = n - 1;

    // Iterate till all the elements are sorted
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(&arr[low], &arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(&arr[mid], &arr[high]);
            high--;
        }
    }
}

int main()
{
    // Title of the program
    cout
        << "***** DNF - DUTCH NATIONAL FLAG SORT *****"
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

    // Sort the array using DNF Sorting
    dnfSort(arr, n);

    // Display the sorted array
    cout
        << endl
        << endl
        << "The Sorted Array is: " << endl;
    printArray(arr, n);

    return 0;
} // main
