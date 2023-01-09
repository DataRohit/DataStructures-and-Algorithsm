#include <bits/stdc++.h>
using namespace std;

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

// Function to heapify the tree
void heapify(vector<int> &arr, int n, int i)
{
    // Var to store the max index
    int maxIdx = i;

    // Calculate the index of left and right child
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    // Check if left child greater than the parent
    if (l < n && arr[l] > arr[maxIdx])
        maxIdx = l;

    // Check if right child greater than the parent
    if (r < n && arr[r] > arr[maxIdx])
        maxIdx = r;

    // If parent is not the max element
    if (maxIdx != i)
    {
        // Swap with current max
        swap(arr[i], arr[maxIdx]);

        // Heapify the tree
        heapify(arr, n, maxIdx);
    }
}

// Heapsort function
void heapsort(vector<int> &arr)
{
    // Get the size of arr
    int n = arr.size();

    // For first non-leaf node
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        // Heapify the tree
        heapify(arr, n, i);
    }

    // For all the leaf elements
    for (int i = n - 1; i > 0; i--)
    {
        // Swap the leaf element with the top of tree
        swap(arr[0], arr[i]);

        // Heapify the tree
        heapify(arr, i, 0);
    }
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** HEAP SORT *****\n\n";
    printLine();

    // Taker user input for the size of array
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    // Line break
    cout << "\n";

    // Initialize the vector
    vector<int> arr(n);

    // Accept user input for the array elements
    cout << "Enter value for array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Call heap sort function to sort the array
    heapsort(arr);

    // Line break
    cout << "\n";

    // Accept user input for the array elements
    cout << "The Sorted Array is:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    // Line break
    cout << "\n\n";
}