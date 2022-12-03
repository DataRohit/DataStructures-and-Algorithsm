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

// Function to get first occurence
int firstOcc(int arr[], int n, int i, int key)
{
    // Base Case -> Array finished
    if (i == n)
    {
        // Element not found in array
        return -1;
    }

    // If array element is equal to key
    if (arr[i] == key)
    {
        // Return the index of the element
        return i;
    }
    else
    {
        // Move to next element using recursive call
        return firstOcc(arr, n, i + 1, key);
    }
}

// Function to get last occurence
int lastOcc(int arr[], int n, int i, int key)
{
    // Base Case -> Array finished
    if (i == n)
    {
        // Element not found in array
        return -1;
    }

    // First go up the stack without doing any thing
    int restArr = lastOcc(arr, n, i + 1, key);

    // Going up the stack
    if (restArr != -1)
    {
        return restArr;
    }

    // If Array element equals key
    if (arr[i] == key)
    {
        // Return the index
        return i;
    }
    else
    {
        // Array element not found
        return -1;
    }
}

int main()
{
    // Title of the program
    cout
        << "***** FIRST AND LAST OCCURENCE *****"
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

    // Input the key element to search
    int key;
    cout
        << endl
        << "Enter the element to find: ";
    cin >> key;

    // Result
    cout
        << endl
        << "First Occurence of " << key << " is at index: " << firstOcc(arr, n, 0, key)
        << endl;

    cout
        << endl
        << "Last Occurence of " << key << " is at index: " << lastOcc(arr, n, 0, key)
        << endl;

    return 0;
} // main
