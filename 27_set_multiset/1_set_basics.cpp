#include <bits/stdc++.h>
using namespace std;

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

// Function to print the set
void printSet(set<int> s)
{
    for (auto i : s)
        cout << i << " ";
    cout << "\n\n";
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** SET *****\n\n";
    printLine();

    // Initialize a set of integers
    set<int> s;

    // Insert elements to set
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);

    // Print the set elements
    cout << "Set Elements are:\n";
    printSet(s);

    // Print the size of set
    cout << "Size of Set is: " << s.size() << "\n\n";

    // Remove element from the set
    s.erase(2);

    // Print the set elements
    cout << "Set Elements are:\n";
    printSet(s);
}