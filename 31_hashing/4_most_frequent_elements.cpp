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
    cout << "***** TOP K MOST FREQUENT ELEMENTS *****\n\n";
    printLine();

    // Take user input for the size of array
    int n;
    cout << "Enter the Size of Array: ";
    cin >> n;

    // Line Break
    cout << "\n";

    // Take user input for number of top elements
    int k;
    cout << "Enter the Value for Top K Elements: ";
    cin >> k;

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

    // Map to store the frequency
    mii freq;

    // Loop to get the top k most frequent elements
    f(i, 0, n)
    {
        // Get present size of the map
        int presentSize = freq.size();

        // Check if violating the conditions
        if (freq[arr[i]] == 0 && presentSize == k)
        {
            // Not consider other elements
            break;
        }

        // Else update the frequency
        freq[arr[i]]++;
    }

    // Create a vector of pair
    vector<pair<int, int>> ans;

    // Traverse the map and store the elements in ans vector
    for (auto it : freq)
    {
        // If frequency is not 0
        if (it.ss != 0)
        {
            // Push the data to
            ans.pb({it.ss, it.ff});
        }
    }

    // Sort the answer vector
    sort(ans.begin(), ans.end(), greater<pii>());

    // Traverse the sorted array
    for (auto it : ans)
    {
        // Print the element and its frequency
        cout << it.ss << " -> " << it.ff << "\n";
    }

    // Line break
    cout << "\n";
}