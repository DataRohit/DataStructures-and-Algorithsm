#include <bits/stdc++.h>
using namespace std;

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

// Function to print the set
void printMultiSet(multiset<int> ms)
{
    for (auto i : ms)
        cout << i << " ";
    cout << "\n\n";
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** MULTI SET *****\n\n";
    printLine();

    // Initialize a multiset of integers
    multiset<int> ms;

    // Insert elements to multiset
    ms.insert(1);
    ms.insert(2);
    ms.insert(2);
    ms.insert(2);
    ms.insert(2);
    ms.insert(3);
    ms.insert(3);
    ms.insert(3);

    // Print the multiset elements
    cout << "Multi Set Elements are:\n";
    printMultiSet(ms);

    // Print the size of multiset
    cout << "Size of Multi Set is: " << ms.size() << "\n\n";

    // Remove all occurences of 2
    ms.erase(2);

    // Print the multiset elements
    cout << "Multi Set Elements are:\n";
    printMultiSet(ms);

    // Remove single occurence of 3
    ms.erase(ms.find(3));

    // Print the multiset elements
    cout << "Multi Set Elements are:\n";
    printMultiSet(ms);
}