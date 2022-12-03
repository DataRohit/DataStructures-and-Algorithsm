#include <iostream>
using namespace std;

// Merge Sorting

/*
 *  Split the array into two halves
 *  Sort the two halves
 *  Merge the two halves
 *
 *  Time Complexity - θ(n log(n))
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

// Function for merging two subarrays
void merge(int arr[], int l, int mid, int r)
{
    // Size of left and right subarrays
    int size_arr_1 = mid - l + 1;
    int size_arr_2 = r - mid;

    // Create temporary arrays
    int temp_arr_1[size_arr_1];
    int temp_arr_2[size_arr_2];

    // Copy data to temp left subarray
    for (int i = 0; i < size_arr_1; i++)
    {
        temp_arr_1[i] = arr[l + i];
    }

    // Copy data to temp right subarray
    for (int i = 0; i < size_arr_2; i++)
    {
        temp_arr_2[i] = arr[mid + 1 + i];
    }

    // Initialize the pointers
    int i = 0;
    int j = 0;
    int k = l;

    // Merge the temp arrays
    while (i < size_arr_1 && j < size_arr_2)
    {
        /*
         *  If element from first subarry is less than
         *  element from second subarray
         */
        if (temp_arr_1[i] <= temp_arr_2[j])
        {
            /*
             *  Add element from first subarray to the original array
             */
            arr[k] = temp_arr_1[i];
            i++;
        }
        else
        {
            /*
             *  Add element from second subarray to the original array
             */
            arr[k] = temp_arr_2[j];
            j++;
        }

        /*
         *  Increment the pointer for the original array
         *  for inserting the element at next position
         */
        k++;
    }

    /*
     *  If there are elements left in the left subarray
     *  then add them to the original array
     */
    while (i < size_arr_1)
    {
        arr[k] = temp_arr_1[i];
        i++;
        k++;
    }

    /*
     *  If there are elements right in the right subarray
     *  then add them to the original array
     */
    while (j < size_arr_2)
    {
        arr[k] = temp_arr_2[j];
        j++;
        k++;
    }
} // merge

// Function for merge sort algorithm
void mergeSort(int arr[], int l, int r)
{
    // If l < r, then there are at least two elements
    if (l < r)
    {
        // Calculate the mid index
        int mid = (l + r) / 2;

        // Sort the first and second halves
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        /*
         *  Merging the sorted halves
         *  1. l to mid
         *  2. mid + 1 to r
         */
        merge(arr, l, mid, r);
    }
}

int main()
{
    // Title of the program
    cout
        << "***** MERGE SORT *****"
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

    // Call the merge sort function
    mergeSort(arr, 0, n - 1);

    // Display the sorted array
    cout
        << endl
        << endl
        << "The Sorted Array is: " << endl;
    printArray(arr, n);

    return 0;
} // main
