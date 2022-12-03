#include <iostream>
using namespace std;

int main()
{
    cout
        << "***** FIRST REPEATING ELEMENT *****"
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

    // Find the first repeating element

    // Declare a variable to check if repeated element is found
    bool isRepeated = false;

    // Traverse the array
    for (int i = 0; i < n; i++)
    {
        // Traverser the array from i + 1 to n
        for (int j = i + 1; j < n; j++)
        {
            // Check if element repeats itself
            if (arr[i] == arr[j])
            {
                cout
                    << endl
                    << endl
                    << "The first repeating element is: " << arr[i] << "at index " << i << endl;
                isRepeated = true;
                break;
            }
        }
        if (isRepeated)
            break;
    }

    return 0;
} // main
