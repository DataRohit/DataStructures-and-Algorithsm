#include <iostream>
using namespace std;

// Wave Sorting

/*
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

// Function for Wave Sorting
void waveSort(int arr[], int n)
{
    // Iterate over all even elements
    for (int i = 1; i < n; i += 2)
    {
        // If current even element is greater than previous
        if (arr[i] > arr[i - 1])
        {
            // Swap previous and current
            swap(&arr[i], &arr[i - 1]);
        }

        // If current even element is greater than next
        if (arr[i] > arr[i + 1] && i <= n - 2)
        {
            // Swap next and current
            swap(&arr[i], &arr[i + 1]);
        }
    }
}

int main()
{
    // Title of the program
    cout
        << "***** WAVE SORT *****"
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
    waveSort(arr, n);

    // Display the sorted array
    cout
        << endl
        << endl
        << "The Sorted Array is: " << endl;
    printArray(arr, n);

    return 0;
} // main
