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
    cout << "***** SMALLEST SUBSEQUENCE WITH SUM K *****\n\n";
    printLine();

    // Take user input for size of array
    int n;
    cout << "Enter the Size of Array: ";
    cin >> n;

    // Line break
    cout << "\n";

    // Take user input for the required sum
    int k;
    cout << "Enter the Value for the Sum: ";
    cin >> k;

    // Line break
    cout << "\n";

    // Declare the vector
    vi arr(n);

    // Take user input for the array elements
    cout << "Enter Array Elements:\n";
    f(i, 0, n)
    {
        cin >> arr[i];
    }

    // Line break
    cout << "\n";

    // Declare a maxheap
    priority_queue<int, vi> pq;

    // Push array elements to the maxheap
    f(i, 0, n)
    {
        pq.push(arr[i]);
    }

    // Initialize required vars
    int sum = 0;
    int cnt = 0;

    // Loop till maxheap not empty
    while (!pq.empty())
    {
        // Add the top element to sum
        sum += pq.top();

        // Pop the top element
        pq.pop();

        // Increase the count of subsequence
        cnt++;

        // Check if the sum is equal or more than k
        if (sum >= k)
        {
            // Stop traversing other elements
            break;
        }
    }

    // Print the result
    if (sum < k)
    {
        cout << "No Subsequence Detected!\n\n";
    }
    else
    {
        cout << "Lenght of Smallest Required Subsequence is: " << cnt << "\n\n";
    }
}