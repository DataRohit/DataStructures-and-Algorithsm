#include <bits/stdc++.h>
using namespace std;

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

// Function to find peak elements
int findPeakElement(vector<int> arr, int low, int high, int n)
{
    // Find the mid index
    int mid = low + (high - low) / 2;

    // Check if mid value is peak value
    if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid]))
    {
        // Return the mid index value
        return mid;
    }

    // Conditions to find mid in left half
    else if (mid > 0 && arr[mid - 1] > arr[mid])
    {
        return findPeakElement(arr, low, mid - 1, n);
    }

    // Find peak in remaining right half
    else
    {
        return findPeakElement(arr, mid + 1, high, n);
    }
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** CHALLENGE 5 *****\n\n";
    cout << "Find the Peak Element\n\nFor a given array, find the peak element in the array.\n\nPeak element is one which is greater than both,\nleft and right neighbours of itself.\n\n";
    printLine();

    // Initialize the variables
    vector<int> arr = {0, 6, 8, 5, 7, 9};
    int n = arr.size();

    // Print the array
    cout << "The Stored Array is:\n";
    for (auto i : arr)
        cout << i << " ";

    cout << "\n\n";

    // Get the index of peak element
    int peakIdx = findPeakElement(arr, 0, n - 1, n);

    // Print the answer
    cout << "The Value of Peak Element is\t\t: " << arr[peakIdx] << "\n";
    cout << "The Value of Peak Element Index is\t: " << peakIdx << "\n\n";
}