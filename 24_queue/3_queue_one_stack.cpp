#include <iostream>
#include <stack>
using namespace std;

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

// Class for queue
class queue
{
    // Two stacks for queue operations
    stack<int> s1;

    // Public functions for operations
public:
    // Function to add data to queue
    void enqueue(int data)
    {
        s1.push(data);

        // Print the message
        cout << "\nData Enqueued Successfully!\n\n";
    }

    // Function to remove data from queue
    int dequeue()
    {
        // Check if queue is empty
        if (s1.empty())
        {
            cout << "\nQUEUE UNDERFLOW!\n\n";

            return -1;
        }

        // Get the top of s1
        int top = s1.top();

        // Pop stack s1
        s1.pop();

        // If s1 is empty print the element
        if (s1.empty())
        {
            // Print the poped element
            cout << "\nDequeued Element is:" << top << "\n";

            // Print the message
            cout << "\nData Dequeued Successfully!\n\n";

            // Return the poped item
            return top;
        }

        // Recursively pop element
        int item = dequeue();

        // Add the element back to the stack
        s1.push(top);

        return item;
    }

    // Function to check if queue is empty
    void empty()
    {
        // Check if queue is empty
        if (s1.empty())
        {
            cout << "\nQUEUE IS EMPTY!\n\n";
        }
        else
        {
            cout << "\nQUEUE IS NOT EMPTY!\n\n";
        }
    }
};

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** QUEUE USING 2 STACKS *****\n\n";
    printLine();

    // Initialize queue object
    queue q;

    // Var to store the data
    int data;

    // Loop till user exits
    while (1)
    {
        // Declare all the operations
        cout << "1. Enqueue Operations\n";
        cout << "2. Dequeue Operations\n";
        cout << "3. Check Empty Operations\n";
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

            // Add data to queue
            q.enqueue(data);

            // Add line break
            printLine();

            break;

        case 2:
            // Pop the data from queue
            q.dequeue();

            // Add line break
            printLine();

            break;

        case 3:
            // Check if queue is emtpy
            q.empty();

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
}