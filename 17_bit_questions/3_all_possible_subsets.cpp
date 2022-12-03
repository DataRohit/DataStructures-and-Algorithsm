#include <iostream>
using namespace std;

// Custom function to get all subsets
void getSubsets(int arr[], int n)
{
    cout << "All possible sub-arrays are: " << endl;
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    // Title for the program
    cout << "***** ALL POSSIBLE SUBSETS *****" << endl
         << endl;

    // Declare the array with 4 elements
    int arr[4] = {1, 2, 3, 4};

    // Display the elements
    cout << "The stored array is: " << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << endl;

    getSubsets(arr, 4);

    return 0;
}
