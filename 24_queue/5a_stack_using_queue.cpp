#include <iostream>
#include <queue>
using namespace std;

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

// Class for stack
class stack
{
    int N;             // N for size
    queue<int> q1, q2; // Queues

public:
    // Constructor
    stack()
    {
        // Initialize the size
        N = 0;
    }

    // Push operation
    void push(int data)
    {
        // Push our new data to queue q2
        q2.push(data);

        // Update the size of stack
        N++;

        // Push all data from q1 to q2 and remove from q1
        while (!q1.empty())
        {
            // Add data to q2
            q2.push(q1.front());

            // Pop q1
            q1.pop();
        }

        // Reveres the queues
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;

        // Print the message
        cout << "\nData Enqueued Successfully!\n\n";
    }

    // Pop operation
    void pop()
    {
        // Check if queue is empty
        if (N == 0)
        {
            cout << "\nQUEUE UNDERFLOW!\n\n";

            return;
        }

        // Pop from q1
        q1.pop();

        // Decrease the size
        N--;

        // Print the message
        cout << "\nData Dequeued Successfully!\n\n";
    }

    // Top / Peek operation
    void top()
    {
        // Check if queue is empty
        if (N == 0)
        {
            cout << "\nQUEUE UNDERFLOW!\n\n";

            return;
        }

        cout << "\nThe front most element in the Queue is: " << q1.front() << "\n\n";
    }

    // Size of Queue
    void size()
    {
        cout << "\nThe size of the Queue is: " << N << "\n\n";
    }
};

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** STACK USING QUEUE - PUSH COSTLY *****\n\n";
    printLine();

    // Initialize the stack object
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
        cout << "4. Size of Queue\n";
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
            st.push(data);

            // Add line break
            printLine();

            break;

        case 2:
            // Pop the data from queue
            st.pop();

            // Add line break
            printLine();

            break;

        case 3:
            // Get the top of stack
            st.top();

            // Add line break
            printLine();

            break;

        case 4:
            // Get the top of stack
            st.size();

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