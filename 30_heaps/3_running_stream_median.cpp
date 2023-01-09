#include <bits/stdc++.h>
using namespace std;

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

// Globally declare minheap and maxheap
priority_queue<int, vector<int>, greater<int>> pqmin;
priority_queue<int, vector<int>> pqmax;

// Function to insert element in the heap
void insert(int x)
{
    // Both the heaps are of same size
    if (pqmin.size() == pqmax.size())
    {
        // If the heaps are empty
        if (pqmax.size() == 0)
        {
            // Add element to maxheap
            pqmax.push(x);
            return;
        }

        // If element less than top of pqmax
        if (x < pqmax.top())
        {
            // Push to maxheap
            pqmax.push(x);
        }
        else
        {
            // Else push to minheap
            pqmin.push(x);
        }
    }

    // If the size of heap are not equal
    else
    {
        // CASE 1: If size of pqmax > size of pqmin
        if (pqmax.size() > pqmin.size())
        {
            // If element greater than top of pqmax
            if (x >= pqmax.top())
            {
                // Add the element to pqmin
                pqmin.push(x);
            }
            else
            {
                // Store the top of maxheap
                int temp = pqmax.top();

                // Remove the top of maxheap
                pqmax.pop();

                // Push the poped element to minheap
                pqmin.push(temp);

                // Add the current element to maxheap
                pqmax.push(x);
            }
        }
        else
        {
            // If element less than top of pqmin
            if (x <= pqmin.top())
            {
                // Add the element to pqmax
                pqmax.push(x);
            }
            else
            {
                // Store the top of minheap
                int temp = pqmin.top();

                // Remove the top of minheap
                pqmin.pop();

                // Push the poped element to maxheap
                pqmax.push(temp);

                // Add the current element to minheap
                pqmin.push(x);
            }
        }
    }
}

// Function to find the median value
double findMedian()
{
    if (pqmin.size() == pqmax.size())
        return (pqmin.top() + pqmax.top()) / 2.0;
    else if (pqmin.size() > pqmax.size())
        return pqmin.top();
    else
        return pqmax.top();
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** MEDIAN OF RUNNING STREAM *****\n\n";
    printLine();

    // Print the operations
    cout << "0. Exit\n\n";
    cout << "1. Insert\n";

    // Var to keep the loop running
    bool run = true;

    // Declare the reqired vars
    int op, num;

    // Run the loop till user manually exits
    while (run)
    {
        // Taker user input
        cout << "Enter Operation: ";
        cin >> op;

        // User switch case to check for operation
        switch (op)
        {
        case 1:
            // Taker user input for element
            cout << "\nEnter value of element: ";
            cin >> num;

            // Add element to the heap
            insert(num);

            // Print the median
            cout << "\nMedian is: " << findMedian() << "\n\n";

            break;

        case 0:
            // Update the run value
            run = false;

            // Print the message
            cout << "\nExiting!\n\n";

            break;

        default:
            // Message for invalid input
            cout << "\nInvalid Input!\n\n";
        }

        // Print line seperator
        printLine();
    }
}