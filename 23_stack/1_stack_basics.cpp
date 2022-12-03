#include <iostream>
using namespace std;

// Parameterized Identifier for length of array
#define n 100

// Class to represent the stack
class stack
{
    int *arr; // Array to store stack elements
    int top;  // Top to store the top index of stack

public:
    // Constructors
    stack()
    {
        arr = new int[n]; // Allocate memory for our array
        top = -1;         // Assign default top value for stack
    }

    // Push operation
    void
    push(int x)
    {
        // Check if stack is full
        if (top == n - 1)
        {
            cout << "\nSTACK OVERFLOW!\n\n";

            return;
        }

        // Increment the top index
        top++;

        // Add the data to new top index
        arr[top] = x;

        // Print the message
        cout << "\nData Pushed Successfully!\n\n";
    }

    // Push operation
    void
    pop()
    {
        // Check if stack is empty
        if (top == -1)
        {
            cout << "\nSTACK UNDERFLOW!\n\n";

            return;
        }

        // Decrement the top index
        top--;

        // Print the message
        cout << "\nData Poped Successfully!\n\n";
    }

    // Get the top value from stack
    void
    peek()
    {
        // Check if stack is empty
        if (top == -1)
        {
            cout << "\nSTACK UNDERFLOW!\n\n";

            return;
        }

        cout << "\nThe top most element in the Stack is: " << arr[top] << "\n\n";
    }

    // Check if the stack is empty
    bool
    isEmpty()
    {
        // If top is -1 stack is empty
        if (top == -1)
        {
            cout << "\nSTACK IS EMPTY!\n\n";
        }
        else
        {
            cout << "\nSTACK IS NOT EMPTY!\n\n";
        }
    }

    // Display the stack
    void
    display()
    {
        // If top is -1 stack is empty
        if (top == -1)
        {
            cout << "\nSTACK UNDERFLOW!\n\n";

            return;
        }

        // Print the message
        cout << "\nThe elements in STACK are:\n";

        // Loop in reverse order to get the stack elements
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << "\n";
        }

        // Add line break
        cout << endl;
    }
};

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

int main()
{
    // Title of the program
    printLine();
    cout << "***** STACK ARRAY IMPLEMENTATION *****\n\n";
    printLine();

    // Initialize stack object
    stack st;

    // Var to store the data
    int data;

    // Loop till user exits
    while (1)
    {
        // Declare all the operations
        cout << "1. Push Operation\n";
        cout << "2. Pop Operation\n";
        cout << "3. Peek Operation\n";
        cout << "4. Check Empty Stack\n";
        cout << "5. Display Stack\n";
        cout << "0. Exit\n";

        // Get the choice from user
        int choice;
        cout << "\nEnter your choice: ";
        cin >> choice;

        // Switch case for different operations
        switch (choice)
        {
        case 1:
            // Get the data from user
            cout << "\nEnter the data: ";
            cin >> data;

            // Add data to stack
            st.push(data);

            // Add line break
            printLine();

            break;

        case 2:
            // Pop the data from stack
            st.pop();

            // Add line break
            printLine();

            break;

        case 3:
            // Display the top element
            st.peek();

            // Add line break
            printLine();

            break;

        case 4:
            // Check if stack is emtpy
            st.isEmpty();

            // Add line break
            printLine();

            break;

        case 5:
            // Display the elements of stack
            st.display();

            // Add line break
            printLine();

            break;

        case 0:
            // Print the message
            cout << "\nExiting the program...\n";

            // Exit the program
            exit(0);

        default:
            // Print the message
            cout << "\nInvalid choice!\n\n";

            // Add line break
            printLine();
        }
    }
} // main
