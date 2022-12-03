#include <iostream>
using namespace std;

int main()
{
    cout
        << "***** ARRAY - MAX AND MIN ELEMENT *****" << endl
        << endl;

    int n;

    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value of index " << i << ": ";
        cin >> arr[i];
    }

    cout << "\nThe array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    int minNo = arr[0], maxNo = arr[0];
    for (int i = 0; i < n; i++)
    {
        minNo = min(minNo, arr[i]);
        maxNo = max(maxNo, arr[i]);
    }

    cout
        << endl
        << endl
        << "The minimum value of array is: " << minNo << endl
        << "The maximum value of array is: " << maxNo << endl;

    return 0;
} // main
