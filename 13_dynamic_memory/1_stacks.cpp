#include <iostream>
using namespace std;

// Declaring and initializing a function
int add(int num1, int num2)
{
    return num1 + num2;
}

// Main function
int main()
{
    // Title of the program
    cout
        << "***** STACKS *****"
        << endl
        << endl;

    int a = 2;
    int b = 3;

    int sum = add(a, b);
    cout << sum << endl;
}

/*
 * STACK STRUCTURE
 * 1. main() function is called
 * 2. main() function is pushed onto the stack with its local variables
 * 3. add() function is called
 * 4. add() function is pushed onto the stack with its local variables
 * 5. add() function is popped off the stack
 * 6. main() function is popped off the stack
 *
 * NOTE: Stack works on the principle of LIFO (Last In First Out)
 * As the last function to execute is add() if will be removed from the stack first followed by main()
 */
