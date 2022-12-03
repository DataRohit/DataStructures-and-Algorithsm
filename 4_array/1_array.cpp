#include <iostream>
using namespace std;

int main()
{
    cout
        << "***** ARRAY - INITIALIZE, INPUT AND OUTPUT *****" << endl
        << endl;

    int n;

    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value of element " << i << ": ";
        cin >> arr[i];
    }

    cout
        << endl
        << "The array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
