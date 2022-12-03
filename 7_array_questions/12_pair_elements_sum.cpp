#include <iostream>
#include <climits>
using namespace std;

void pairsum(int arr[], int n, int k)
{
    // set our low and high index
    int low = 0, high = n - 1;

    // if lower index is equal or less that high
    while (low <= high)
    {
        // if sum of elements is equal to key
        if (arr[low] + arr[high] == k)
        {
            // print the pair and break the loop
            cout
                << endl
                << endl
                << "Pair found: " << arr[low] << " and " << arr[high] << endl;
            break;
        }
        // If required sum smaller that key update lower index
        else if (arr[low] + arr[high] < k)
        {
            low++;
        }
        // If required sum greater than key update higher index
        else
        {
            high--;
        }
    }

    // If lower index goes above the higher index
    if (low > high)
    {
        // Print that no pair found
        cout
            << endl
            << endl
            << "No pair found" << endl;
    }

    return;
} // pairsum

int main()
{
    cout
        << "***** PARI SUM PROBLEM *****"
        << endl
        << endl;

    // Take size of array as input
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Take pari element sum
    int k;
    cout << "Enter the pair element sum: ";
    cin >> k;

    // Declare the array of size n + 1
    int arr[n + 1];
    arr[n] = -1;

    // Take input of array elements
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element for index " << i << " : ";
        cin >> arr[i];
    }

    // Print the array
    cout
        << endl
        << "The stored array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Insertion Sort Algorithm
    for (int i = 1; i < n; i++)
    {
        // Store the current element
        int current = arr[i];

        // Store the index of the previous element
        int j = i - 1;

        // If the previous element is greater than the current element
        while (arr[j] > current && j >= 0)
        {
            // Shift the previous element to the next position
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert the current element to its correct position
        arr[j + 1] = current;
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

    // Check if pair sum exists
    pairsum(arr, n, k);

    return 0;
} // main
