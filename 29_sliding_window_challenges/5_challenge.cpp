#include <bits/stdc++.h>
using namespace std;

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

// Function to check if the number is perfect number
bool isPerfectNumber(int num)
{
    // Var to store the sum of divisors
    int sum = 1;

    // Loop over numbers to check for divisors
    for (int i = 2; i < sqrt(num); i++)
    {
        // Check if divisor
        if (num % i == 0)
        {
            // Update the sum
            if (i == num / i)
            {
                sum += i;
            }
            else
            {
                sum += i + num / i;
            }
        }
    }

    // Check if sum is equal to the number
    if (sum == num && num != 1)
    {
        return true;
    }
    return false;
}

// Function to get the maximium sum
int maxSum(vector<int> arr, int k)
{
    // Check if the size of array is less then size of window
    if (arr.size() < k)
    {
        cout << "Invalid Values!\n\n";
        return -1;
    }

    // Initialize the results var
    int res = 0;

    // Traverse the first k elements
    for (int i = 0; i < k; i++)
    {
        // Update the result
        res += arr[i];
    }

    // Initalize temp variable
    int sum = res;

    // Traverse to remaining elements
    for (int i = k; i < arr.size(); i++)
    {
        // Update the sum and result
        sum += arr[i] - arr[i - k];
        res = max(sum, res);
    }

    // Return the result
    return res;
}

// Function to check for perfect number subarrray
int maxPerfects(vector<int> arr, int k)
{
    // Traverse array to check if number is perfect
    for (int i = 0; i < arr.size(); i++)
    {
        if (isPerfectNumber(arr[i]))
        {
            // Change to 1 if number is perfect number
            arr[i] = 1;
        }
        else
        {
            // Change to 0 if number is not a perfect number
            arr[i] = 0;
        }
    }

    return maxSum(arr, k);
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** CHALLENGE 5 *****\n\n";
    cout << "Maximum Perfect Numbers in Length K\n\nFor a given array and an integer K,\nfind the maximum perfect numbers\nin a subarray of size K.\n\n";
    printLine();

    // Initialize the required variables
    vector<int> arr = {28, 2, 3, 6, 496, 99, 8128, 24};
    int k = 4; // Size of the subarray

    // Print the array
    cout << "The Stored Array is:\n";
    for (auto i : arr)
        cout << i << " ";

    cout << "\n\n";

    // Get the palindromic subarray
    int ans = maxPerfects(arr, k);

    // Check and print the answer
    if (ans == -1)
    {
        cout << "Perfect Numbers Doesn't Exist!\n\n";
    }
    else
    {
        cout << "The Count Perfect Numbers is: " << ans << "\n\n";
    }
}