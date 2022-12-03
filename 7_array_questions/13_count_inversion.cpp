#include <iostream>
using namespace std;

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
int merge(int arr[], int l, int mid, int r)
{
    // Count inversions
    int invCount = 0;

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
            invCount += size_arr_1 - i;
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

    // Return count of inversions
    return invCount;
} // merge

// Function for counting the number of inversions
int mergeSort(int arr[], int l, int r)
{
    // Counting inversions
    int invCount = 0;

    // If l < r, then there are at least two elements
    if (l < r)
    {
        // Calculate the mid index
        int mid = (l + r) / 2;

        // Sort the first and second halves
        invCount += mergeSort(arr, l, mid);
        invCount += mergeSort(arr, mid + 1, r);

        /*
         *  Merging the sorted halves
         *  1. l to mid
         *  2. mid + 1 to r
         */
        invCount += merge(arr, l, mid, r);
    }

    // Return the number of inversions
    return invCount;
}

int main()
{
    // Title of the program
    cout
        << "***** COUNT INVERSION *****"
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

    // Count Inversion
    cout
        << endl
        << endl
        << "Total Inversions: ";
    cout << mergeSort(arr, 0, n - 1);
    ;

    return 0;
} // main
