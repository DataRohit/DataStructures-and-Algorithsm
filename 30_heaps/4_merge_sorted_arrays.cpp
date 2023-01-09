#include <bits/stdc++.h>
using namespace std;

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** MERGE K SORTED ARRAYS *****\n\n";
    printLine();

    // Taker user input for number of arrays
    int k;
    cout << "Enter Number of Arrays: ";
    cin >> k;

    // Line Break
    cout << "\n";
    printLine();

    // Declare a 2D vector
    vector<vector<int>> arr(k);

    // Traverse the 2D vector to take input of array size and elements
    for (int i = 0; i < k; i++)
    {
        // Take user input for size of array
        int size;
        cout << "Enter Size of Array " << i + 1 << ": ";
        cin >> size;

        // Initialize the array
        arr[i] = vector<int>(size);

        // Take input for array elements
        cout << "\nEnter the Array Elements:\n";
        for (int j = 0; j < size; j++)
        {
            cin >> arr[i][j];
        }

        // Line Break
        cout << "\n";
        printLine();
    }

    // Initialize the vector to store index
    vector<int> idx(k, 0);

    // Declare minheap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Push first element of each array to index vector
    for (int i = 0; i < k; i++)
    {
        // {first element, array number}
        pq.push({arr[i][0], i});
    }

    // Declare the answer vector
    vector<int> ans;

    // Loop till our minheap is not empty
    while (!pq.empty())
    {
        // Get the top minimum element from the minheap
        pair<int, int> x = pq.top();

        // Pop the top element
        pq.pop();

        // Push the answer to ans array
        ans.push_back(x.first);

        // Check if index less than size of array
        if (idx[x.second] + 1 < arr[x.second].size())
        {
            // Add the element from the array and add its index to index array
            pq.push({arr[x.second][idx[x.second] + 1], x.second});
        }

        // Update the index to access the next element
        idx[x.second]++;
    }

    // Print the sorted array
    cout << "The Sorted Merged Array is:\n";
    for (auto i : ans)
        cout << i << " ";

    // Line break
    cout << "\n\n";
    printLine();
}