#include <iostream>
using namespace std;

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

// Function to add data before/at head
void insertAtHead(node *&head, int data)
{
    // Create newNode to store our data
    node *newNode = new node(data);

    // If linked list is empty
    if (head == NULL)
    {
        // Point newNode to itself
        newNode->next = newNode;

        // Set newNode as head
        head = newNode;

        return;
    }

    // Temp node for traversing
    node *temp = head;

    // Traverse and find the last node
    while (temp->next != head)
    {
        temp = temp->next;
    }

    // Point last node to newNode
    temp->next = newNode;

    // Point newNode to head
    newNode->next = head;

    // Set newNode as head
    head = newNode;
}

// Function to add data at tail
void insertAtTail(node *&head, int data)
{
    // If the head is null add the newNode before/at head
    if (head == NULL)
    {
        insertAtHead(head, data);
        return;
    }

    // Create a newNode to store our data
    node *newNode = new node(data);

    // Create temp node for traversing
    node *temp = head;

    // Traverse and find the last node
    while (temp->next != head)
    {
        temp = temp->next;
    }

    // Point the last node to newNode
    temp->next = newNode;

    // Point the newNode to head
    newNode->next = head;
}

// Function to delete a node at head
void deleteAtHead(node *&head)
{
    // Create temp node for traversing
    node *temp = head;

    // Traverse and get last node
    while (temp->next != head)
    {
        // Update the temp pointer
        temp = temp->next;
    }

    // Store the node to delete
    node *toDelete = temp->next;

    // Point the last node to second node
    temp->next = head->next;

    // Update the head pointer
    head = head->next;

    // Delete the toDelete pointer
    delete toDelete;
}

// Function to delete a node
void deleteData(node *&head, int pos)
{
    // Check if linked list is empty
    if (head == NULL)
    {
        return;
    }

    // Delete the head node
    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }

    // Create temp node for traversing
    node *temp = head;

    // Counter to keep track of position
    int count = 1;

    // Loop to find the pos-1 node
    while (count != pos - 1)
    {
        // Update the temp node
        temp = temp->next;

        // Update the counter
        count++;
    }

    // Store the node to delete
    node *toDelete = temp->next;

    // Remove the node from linked list
    temp->next = temp->next->next;

    // Delete the toDelete pointer
    delete toDelete;
} // deleteData

// Function to display the linked list
void display(node *head)
{
    // If head is NULL, then linked list is empty
    if (head == NULL)
    {
        cout << "\nLinked list is empty!\n\n";
        return;
    }

    // Create temp node for traversing
    node *temp = head;

    // Print the message
    cout << "\nThe elements of linked list are: \n";

    // Print the linked list items
    do
    {
        // Print data of current node
        cout << temp->data << " -> ";

        // Move to next node
        temp = temp->next;
    } while (temp != head);

    cout << "HEAD\n\n";
}

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

int main()
{
    // Title of the program
    printLine();
    cout << "***** CIRCULAR LINKED LIST *****\n\n";
    printLine();

    // Initialize head of our linked list
    node *head = NULL;

    // Var to store the data
    int data;

    // Loop till user exits
    while (1)
    {
        // Declare all the operations
        cout << "1. Insert at tail\n";
        cout << "2. Insert at head\n";
        cout << "3. Delete an element\n";
        cout << "4. Display linked list\n";
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

            // Insert at tail
            insertAtTail(head, data);

            // Display the linked list
            display(head);

            // Add line seperator
            printLine();

            break;

        case 2:
            // Get the data from user
            cout << "\nEnter the data: ";
            cin >> data;

            // Insert at tail
            insertAtHead(head, data);

            // Display the linked list
            display(head);

            // Add line seperator
            printLine();

            break;

        case 3:
            // Get the data from user
            cout << "\nEnter the position to delete: ";
            cin >> data;

            // Delete the data in linked list
            deleteData(head, data);

            // Display the linked list
            display(head);

            // Add line seperator
            printLine();

            break;

        case 4:
            // Display the linked list
            display(head);

            // Add line seperator
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
        }
    }

    return 0;
} // main
