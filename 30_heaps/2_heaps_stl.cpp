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
    cout << "***** HEAPS STL *****\n\n";
    printLine();

    // Initialize a maxheap
    priority_queue<int, vector<int>> pq;

    // Max Heap Operations
    cout << "MAXHEAP\n\n";

    // Operations on the maxheap
    pq.push(2);
    pq.push(3);
    pq.push(1);

    // Print the top element
    cout << "Top of Maxheap: " << pq.top() << "\n\n";

    // Pop the elements
    pq.pop();

    // Print the top element
    cout << "Top of Maxheap after poping: " << pq.top() << "\n\n";

    // Print a seperator line
    printLine();

    // Initialize a minheap
    priority_queue<int, vector<int>, greater<int>> pqm;

    // Min Heap Operations
    cout << "MINHEAP\n\n";

    // Operations on the minheap
    pqm.push(2);
    pqm.push(3);
    pqm.push(1);

    // Print the top element
    cout << "Top of Minheap: " << pqm.top() << "\n\n";

    // Pop the elements
    pqm.pop();

    // Print the top element
    cout << "Top of Minheap after poping: " << pqm.top() << "\n\n";
}