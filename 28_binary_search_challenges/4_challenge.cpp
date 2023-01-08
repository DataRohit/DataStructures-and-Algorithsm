#include <bits/stdc++.h>
using namespace std;

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

// Function find the index of key element
int searchInRotatedArray(vector<int> arr, int key, int left, int right)
{
    // Check for invalid range
    if (left > right)
    {
        return -1;
    }

    // Find the mid
    int mid = (left + right) / 2;

    // Check if mid value is the key
    if (arr[mid] == key)
    {
        return mid;
    }

    // Check the conidered left array first
    if (arr[left] <= arr[mid])
    {
        // Condition to search in left half
        if (key >= arr[left] && key <= arr[mid])
        {
            return searchInRotatedArray(arr, key, left, mid - 1);
        }

        // Else search element in right half
        return searchInRotatedArray(arr, key, mid + 1, right);
    }

    // Check the considered right array first
    if (key >= arr[mid] && key <= arr[right])
    {
        // Search in right half
        return searchInRotatedArray(arr, key, mid + 1, right);
    }

    // Search in left half
    return searchInRotatedArray(arr, key, left, mid - 1);
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** CHALLENGE 4 *****\n\n";
    cout << "Search element in Sorted & Rotated array\n\nWe are given an ascending sorted array\nthat has been rotated from pivot point\n(unknown to us) and and element X.\n\nSearch for X in the array with complexity\nless thatn that of linear search.\n\n";
    printLine();

    // Initialize the variables
    vector<int> arr = {6, 7, 8, 1, 2, 3, 4, 5};
    int n = arr.size();
    int key = 2;

    // Print the array
    cout << "The Stored Array is:\n";
    for (auto i : arr)
        cout << i << " ";

    cout << "\n\n";

    // Get the answer
    int idx = searchInRotatedArray(arr, key, 0, n - 1);

    // Check the answer
    if (idx == -1)
    {
        cout << "Key Element " << key << " Not Present!\n\n";
    }
    else
    {
        cout << "Key Element Found at Index: " << idx << "\n\n";
    }
}