#include <iostream>
using namespace std;

int main()
{
    cout
        << "***** FINDING SMALLEST +VE MISSING INTEGER *****"
        << endl
        << endl;

    // Take size of array as input
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

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

    // Get the largest number from the array
    int maxNo = arr[0];
    for (int i = 1; i < n; i++)
        maxNo = max(maxNo, arr[i]);

    // Declare our check array
    bool chekArr[maxNo + 1];

    // Initialize the check array
    for (int i = 0; i < maxNo + 1; i++)
        if (arr[i] > 0)
            chekArr[arr[i]] = true;

    // Traverse the check array
    for (int i = 1; i < maxNo + 1; i++)
    {
        // If the element is not present in the array
        if (chekArr[i] == false)
        {
            // Print the smallest +ve missing integer
            cout
                << endl
                << endl
                << "The smallest +ve missing integer is: " << i << endl;
            break;
        }
    }

    return 0;
} // main
