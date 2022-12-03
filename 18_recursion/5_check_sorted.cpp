#include <iostream>
using namespace std;

// Function to initialize and take input from user
int *array_input(int n)
{
    // Initialize the array
    static int arr[20];

    // Ask user to enter the elements of array
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value of element " << i << ": ";
        cin >> arr[i];
    }

    return arr;
}

// Function to display the array
void display_array(int arr[], int n)
{
    // Display the array
    cout
        << endl
        << "The array is: "
        << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return;
}

// Function to check if the array is sorted or not
bool checkSorted(int arr[], int n)
{
    // If only 1 element left in array -> Array is Sorted
    if (n == 1)
    {
        return true;
    }

    bool restArray = checkSorted(arr + 1, n - 1);
    // arr + 1 -> Move to next element
    // n - 1 -> Decrease the size of array

    return ((arr[0] < arr[1]) && restArray);
}

int main()
{
    // Title of the program
    cout
        << "***** CHECK SORTED ARRAY *****"
        << endl
        << endl;

    // Take user input for size of array
    int n;
    cout << "Enter the size of array (<=20): ";
    cin >> n;
    cout << endl;

    // Initialize the array
    int *arr;
    arr = array_input(n);

    // Display the array
    display_array(arr, n);

    // Check if the array is sorted or not
    bool isSorted = checkSorted(arr, n);

    // Display the result
    if (isSorted)
    {
        cout
            << endl
            << "The array is sorted."
            << endl;
    }
    else
    {
        cout
            << endl
            << "The array is not sorted."
            << endl;
    }

    return 0;
} // main
