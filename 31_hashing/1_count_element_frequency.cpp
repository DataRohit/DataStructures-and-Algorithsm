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
    cout << "***** HASING - COUNT FREQUENCY OF ELEMENTS *****\n\n";
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

    // Declare the map to store the frequency
    mii freq;

    // Update the value of frequency at index = array element
    f(i, 0, n)
    {
        // Updating the frequency
        freq[arr[i]]++;
    }

    // Loop over the map to get the frequency
    cout << "Frequency of Each Element is:\n";
    for (auto it : freq)
    {
        cout << it.ff << " -> " << it.ss << "\n";
    }

    // Line Break
    cout << "\n";
}