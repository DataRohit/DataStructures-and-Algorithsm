#include <iostream>
using namespace std;

// Count Sorting

/*
 *  1. Find the count of every distinct element in the array
 *  2. Calculate the position of every element in the sorted array
 *
 *  Best Time Complexity - Ω(n + k)
 *  Worst Time Complexity - O(n + k)
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

void countSort(int arr[], int n)
{
    // Initialize the largest element by the first element
    int k = arr[0];

    // Find the largest element of the array
    for (int i = 0; i < n; i++)
    {
        // Update largest element
        k = max(k, arr[i]);
    }

    // Initialize the count array with 0
    int count[k + 1] = {0};

    // Store the count of each element
    for (int i = 0; i < n; i++)
    {
        // Increment the count of the element
        count[arr[i]]++;
    }

    // Store the cumulative count of each array
    for (int i = 1; i <= k; i++)
    {
        // Update the count array
        count[i] += count[i - 1];
    }

    // Initialize the output array
    int output[n];

    /*
     *  1. Find the correct index for element
     *  2. Place the element in the output array
     */

    // Iterate over the array
    for (int i = n - 1; i >= 0; i--)
    {
        // Find the correct index of the element

        /*
         *  1. Get the value from array at index i
         *  2. Get the count of the value from count array
         *  3. Decrement the count by 1
         *  4. Place the element in outpur array at the index
         */
        output[--count[arr[i]]] = arr[i];
    }

    // Copy the sorted elements into original array
    for (int i = 0; i < n; i++)
    {
        // Update the array
        arr[i] = output[i];
    }
} // countSort

int main()
{
    // Title of the program
    cout
        << "***** COUNT SORT *****"
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

    // Sort the array
    countSort(arr, n);

    // Display the sorted array
    cout
        << endl
        << endl
        << "The Sorted Array is: " << endl;
    printArray(arr, n);
} // main
