#include <iostream>
using namespace std;

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

// Node class
class node
{
public:
    int data;
    node *next;

    // Constructor
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Queue class
class queue
{
    node *front;
    node *back;

public:
    // Constructor
    queue()
    {
        this->front = NULL;
        this->back = NULL;
    }

    // Function to add data to queue
    void enqueue(int data)
    {
        // Create a new node for data
        node *newNode = new node(data);

        // If Queue is empty
        if (front == NULL)
        {
            // Update the back pointer
            back = newNode;

            // Update the front pointer
            front = newNode;

            return;
        }

        // Add the data to next of back
        back->next = newNode;

        // Update the back pointer
        back = newNode;
    }

    // Function to remove data from queue
    void dequeue()
    {
        // Check if queue is empty
        if (front == NULL)
        {
            cout << "\nQUEUE UNDERFLOW!\n\n";

            return;
        }

        // Copy the node to delete
        node *toDelete = front;

        // Update the front
        front = front->next;

        // Free the memory
        delete toDelete;
    }

    // Get the front value from queue
    void peek()
    {
        // Check if queue is empty
        if (front == NULL)
        {
            cout << "\nQUEUE UNDERFLOW!\n\n";

            return;
        }

        cout << "\nThe front most element in the Queue is: " << front->data << "\n\n";
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        // If front is NULL queue is empty
        if (front == NULL)
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
        // If front is NULL queue is empty
        if (front == NULL)
        {
            cout << "\nQUEUE IS EMPTY!\n\n";

            return;
        }

        // Create a copy of front for traversing
        node *temp = front;

        // Print the message
        cout << "\nThe elements in QUEUE are:\n";

        // Traverse to print the queue
        while (temp != NULL)
        {
            // Print the data
            cout << temp->data << " ";

            // Update the temp
            temp = temp->next;
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
    cout << "***** QUEUE LINKED LIST IMPLEMENTATION *****\n\n";
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