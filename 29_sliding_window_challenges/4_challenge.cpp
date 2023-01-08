#include <bits/stdc++.h>
using namespace std;

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

// Function to check if a number is palindrome
bool isPalindrome(int num)
{
    // Initialize required variable
    int temp = num, number = 0;

    // Reverse the number
    while (temp > 0)
    {
        // Remove the first number from the left and add to the number var
        number = number * 10 + temp % 10;
        temp = temp / 10;
    }

    // Check if number equals reverse
    if (number == num)
    {
        return true;
    }
    return false;
}

// Function to check if subarray with palindromic concatenation exist
int findPalindromicSubarray(vector<int> arr, int k)
{
    // Initialize the required variable
    int num = 0;

    // Find the number for first k elements
    for (int i = 0; i < k; i++)
    {
        // Concatenate the k numbers
        num = num * 10 + arr[i];
    }

    // If the current num value is palindromic
    if (isPalindrome(num))
    {
        // Return the starting index of the considered array
        return 0;
    }

    // Loop for remaining elements
    for (int j = k; j < arr.size(); j++)
    {
        // Update the number
        num = (num % (int)pow(10, k - 1)) * 10 + arr[j];

        // If the current num value is palindromic
        if (isPalindrome(num))
        {
            // Return the starting index of the considered array
            return j - k + 1;
        }
    }

    // If no palindrome not exist
    return -1;
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** CHALLENGE 4 *****\n\n";
    cout << "Subarray of Size K with Palindromic Concatenation\n\nFor a given array and an integer K,\ncheck if any subarray of size K exists\nin the array such that concatenation\nof elements form a palindrome.\n\n";
    printLine();

    // Initialize the required variables
    vector<int> arr = {2, 3, 5, 1, 1, 5};
    int k = 4; // Size of the subarray

    // Print the array
    cout << "The Stored Array is:\n";
    for (auto i : arr)
        cout << i << " ";

    cout << "\n\n";

    // Get the palindromic subarray
    int ans = findPalindromicSubarray(arr, k);

    // Check and print the answer
    if (ans == -1)
    {
        cout << "Palindromic Subarray Doesn't Exist!\n\n";
    }
    else
    {
        cout << "Palindromic Subarray is:\n";
        for (int i = ans; i < ans + k; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n\n";
    }
}