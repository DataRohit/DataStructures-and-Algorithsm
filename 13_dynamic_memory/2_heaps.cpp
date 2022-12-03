#include <iostream>
using namespace std;

// Main function
int main()
{
    // Title of the program
    cout
        << "***** HEAPS *****"
        << endl
        << endl;

    // Initialize variable in stack
    int a = 10;

    // p is stored in stack but the value it points to is stored in heap
    int *p = new int();

    // Assigning value to p in heap
    *p = 10;

    // De-allocating the memory
    delete (p);

    // p is still in stack but the value it points to is no longer in heap
    // such pointer is called a dangling pointer

    // Assigning array value to p in heap
    p = new int[5];

    // Deleting the array pointed by p
    delete[] p;

    // Clear the value at p to avoid memory leak
    p = NULL;
}

/*
 * HEAPS
 *
 * 1. Initialize variable a = 10 in stack
 * 2. Initialize pointer p in stack pointing to a value in heap
 * 3. Assign value 10 to address store in p (in heap)
 * 4. Delete the value stored in p (in heap)
 * 5. p is still in stack but the value it points to is no longer in heap
 * 6. Initialize array of 5 values in heap and assign its start address to p
 * 7. Delete the array pointed by p
 * 8. Clear the value at p to avoid memory leak
 *
 */
