
#include <iostream>
using namespace std;

// Parameterized Identifier for length of array
#define n 100

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

// Class to represent the queue
class queue
{
    int *arr;  // Array to store queue elements
    int front; // Front to store the first / start element
    int back;  // Back to insert new element

public:
    // Constructors
    queue()
    {
        arr = new int[n]; // Allocate memory for our array
        front = -1;       // Default value for front
        back = -1;        // Default value for back
    }

    // Enqueue Operation
    void enqueue(int x)
    {
        // Check if queue is full
        if (back == n - 1)
        {
            cout << "\nQUEUE OVERFLOW!\n\n";

            return;
        }

        // Increment the back index
        back++;

        // If first element update front
        if (front == -1)
        {
            front++;
        }

        // Add the data to new back index
        arr[back] = x;

        // Print the message
        cout << "\nData Enqueued Successfully!\n\n";
    }

    // Dequeue Operation
    void dequeue()
    {
        // Check if queue is empty
        if (front == -1 || front > back)
        {
            cout << "\nQUEUE UNDERFLOW!\n\n";

            return;
        }

        // Increment the front pointer
        front++;

        // Print the message
        cout << "\nData Dequeued Successfully!\n\n";
    }

    // Get the front value from queue
    void peek()
    {
        // Check if queue is empty
        if (front == -1 || front > back)
        {
            cout << "\nQUEUE UNDERFLOW!\n\n";

            return;
        }

        cout << "\nThe front most element in the Queue is: " << arr[front] << "\n\n";
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        // If front is -1 queue is empty
        if (front == -1 || front > back)
        {
            cout << "\nQUEUE IS EMPTY!\n\n";

            return true;
        }
        else
        {
            cout << "\nQUEUE IS NOT EMPTY!\n\n";

            return false;
        }
    }

    // Display the queue
    void display()
    {
        // If front is -1 queue is empty
        if (front == -1 || front > back)
        {
            cout << "\nQUEUE IS EMPTY!\n\n";

            return;
        }

        // Print the message
        cout << "\nThe elements in QUEUE are:\n";

        // Loop in order to get the queue elements
        for (int i = front; i <= back; i++)
        {
            cout << arr[i] << " ";
        }

        // Add line break
        cout << "\n\n";
    }
};

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** QUEUE ARRAY IMPLEMENTATION *****\n\n";
    printLine();

    // Initialize queue object
    queue q;

    // Var to store the data
    int data;

    // Loop till user exits
    while (1)
    {
        // Declare all the operations
        cout << "1. Enqueue Operation\n";
        cout << "2. Dequeue Operation\n";
        cout << "3. Peek Operation\n";
        cout << "4. Check Empty Queue\n";
        cout << "5. Display Queue\n";
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
            // Display the top element
            q.peek();

            // Add line break
            printLine();

            break;

        case 4:
            // Check if queue is emtpy
            q.isEmpty();

            // Add line break
            printLine();

            break;

        case 5:
            // Display the elements of queue
            q.display();

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