#include <bits/stdc++.h>
using namespace std;

// Defining short forms
#define ll long long

#define pii pair<int, int>
#define mk make_pair
#define ff first
#define ss second

#define vi vector<int>
#define pb push_back
#define pf pop_front

#define imax INT_MAX
#define imin INT_MIN

#define mii map<int, int>
#define umii unordered_map<int, int>

#define f(i, s, e) for (int i = s; i < e; i++)
#define cf(i, s, e) for (int i = s; i <= e; i++)

#define rf(i, s, e) for (int i = e - 1; i >= s; i--)

// Function to print a seperator line
void printLine() { cout << "--------------------------------------------\n\n"; }

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** NUMBER OF SUBARRAY WITH SUM 0 *****\n\n";
    printLine();

    // Take user input for the size of array
    int n;
    cout << "Enter the Size of Array: ";
    cin >> n;

    // Line Break
    cout << "\n";

    // Declare the array
    vi arr(n);

    // Take user input for the array elements
    cout << "Enter value for array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Line break
    cout << "\n";

    // Declare the map to store the count
    mii cnt;

    // Var to store the prefix sum
    int prefSum = 0;

    // Loop over the array to get the prefix sum
    f(i, 0, n)
    {
        // Calculate the prefix sum
        prefSum += arr[i];

        // Update the frequency of prefix sum in map
        cnt[prefSum]++;
    }

    // Variable to store the ans
    int ans = 0;

    // Iterate over the map to get the ans
    for (auto it : cnt)
    {
        // Get the frequency of each prefix sum
        int c = it.ss;

        // Update the ans
        ans += (c * (c - 1)) / 2;

        // If prefix sum is 0
        if (it.ff == 0)
        {
            ans += it.ss;
        }
    }

    // Print the ans
    cout << "The No. of Required Subarray is: " << ans << "\n\n";
}