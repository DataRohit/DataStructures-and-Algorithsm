#include <iostream>
#include <algorithm>
using namespace std;

// function to print the array
void printarray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// function to swap the variables
void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

// permutation function
void permutation(int *arr, int start, int end)
{
    /*
     *  if start and end are same
     *  no element in the array
     *  print the array and exit
     */
    if (start == end)
    {
        printarray(arr, end + 1);
        return;
    }

    // If array has elements then
    for (int i = start; i <= end; i++)
    {
        // check if both the elements are same
        if (arr[i] == arr[start] && i != start)
        {
            /*
             *  if yes continue
             *  skip the iterations
             */
            continue;
        }

        // swapping numbers
        swap((arr + i), (arr + start));

        /*
         *  fixing one first digit
         *  and calling permutation on
         *  the rest of the digits
         */
        permutation(arr, start + 1, end);

        // backtracking and swapping the numbers again.
        swap((arr + i), (arr + start));
    }
}

int main()
{
    // Title of the program
    cout
        << "***** ALL POSSIBLE PERMUTATIONS *****"
        << endl
        << endl;

    // taking input to the array
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    // declaring the array
    int arr[size];

    // taking input to the array
    cout
        << endl
        << "Enter array elements: "
        << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // sorting the array
    sort(arr, arr + size);

    // calling permutation function
    cout
        << endl
        << "All possible permutations are: "
        << endl;
    permutation(arr, 0, size - 1);

    return 0;
} // main
