#include <bits/stdc++.h>
using namespace std;

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

// Function to print the unordered set
void printUnorderedSet(unordered_set<int> us)
{
    for (auto i : us)
        cout << i << " ";
    cout << "\n\n";
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** UNORDERED SET *****\n\n";
    printLine();

    // Initialize a unordered_set of integers
    unordered_set<int> us;

    // Insert elements to unordered_set
    us.insert(1);
    us.insert(2);
    us.insert(2);
    us.insert(2);
    us.insert(2);
    us.insert(3);
    us.insert(3);
    us.insert(3);

    // Print the unordered_set elements
    cout << "Unordered Set Elements are:\n";
    printUnorderedSet(us);

    // Print the size of unordered_set
    cout << "Size of Unordered Set is: " << us.size() << "\n\n";

    // Remove all occurences of 2
    us.erase(2);

    // Print the unordered_set elements
    cout << "Unordered Set Elements are:\n";
    printUnorderedSet(us);
}