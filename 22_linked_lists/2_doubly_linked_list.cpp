#include <iostream>
using namespace std;

// Node class
class node
{
public:
    node *prev;
    int data;
    node *next;

    // Constructor
    node(int data)
    {
        this->prev = NULL;
        this->data = data;
        this->next = NULL;
    }
};

// Function to insert node at head of linked list
void insertAtHead(node *&head, int data)
{
    // Initialize new node with our data

    /*
     *  New node with data and
     *  next pointer pointing to NULL
     */
    node *newNode = new node(data);

    // If head is NULL, then make new node as head
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    // Update the next of new node to head
    newNode->next = head;

    // Update the prev of head to new node
    head->prev = newNode;

    // Set our new node as the head of linked list
    head = newNode;
}

// Function to insert node at tail of linked list
void insertAtTail(node *&head, int data)
{
    // Initialize new node with our data

    /*
     *  New node with our data
     *  next pointer pointing to NULL
     *  prev pointer pointing to NULL
     */
    node *newNode = new node(data);

    // If head is NULL, then make new node as head
    if (head == NULL)
    {
        insertAtHead(head, data);
        return;
    }

    // Initialize temp node to head for traversing
    node *temp = head;

    // Traverse till we find the last node
    while (temp->next != NULL)
    {
        // Move to next node
        temp = temp->next;
    }

    // Point last node to new node
    temp->next = newNode;

    // Point new node's prev pointer to last node
    newNode->prev = temp;

    return;
}

// Function to delete an element from linked list
void deleteData(node *&head, int data)
{
    // Initialize temp node to head for traversing
    node *temp = head;

    // If head is NULL, then linked list is empty
    if (head == NULL)
    {
        return;
    }

    // If element found at head
    if (head->data == data)
    {
        // If head is the only node in linked list
        if (head->next == NULL)
        {
            // Delete temp node
            delete temp;

            // Set head to NULL
            head = NULL;

            return;
        }
        // If there are multiple elements in linked list
        else
        {
            // Update head to next node
            head = head->next;

            // Delete the previous node
            delete temp;

            // Update the prev pointer of new head to NULL
            head->prev = NULL;

            return;
        }
    }

    // Traverse till we find the element to be deleted
    while (temp->data != data)
    {
        // Move to next node
        temp = temp->next;

        // If we reach the end of linked list and element not found
        if (temp == NULL)
        {
            cout << "\nData not found!\n";
            return;
        }
    }

    // If element is found at last node
    if (temp->next == NULL && temp->data == data)
    {
        // Point the prev node to NULL
        temp->prev->next = NULL;

        // Delete the node
        delete temp;

        return;
    }

    // Update the next of prev node
    temp->prev->next = temp->next;

    // Update the prev of next node
    temp->next->prev = temp->prev;

    // Delete the node
    delete temp;
} // deleteData

// Function to print linked list
void display(node *head)
{
    // Initialize temp node to head for traversing
    node *temp = head;

    // If head is NULL, then linked list is empty
    if (head == NULL)
    {
        cout << "\nLinked list is empty!\n\n";
        return;
    }

    // Print the message
    cout << "\nThe elements of linked list are: \n";

    // Traverse till we find the last node
    while (temp != NULL)
    {
        // Print data of current node
        cout << temp->data << " -> ";

        // Move to next node
        temp = temp->next;
    }

    // Add a line break
    cout << "NULL\n\n";

    return;
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
    cout << "***** DOUBLY LINKED LIST *****\n\n";
    printLine();

    // Var to store the data
    int data;

    // Declare the head of the linked list
    node *head = NULL;

    // Loop till user exits
    while (true)
    {
        // Declare all the operations
        cout << "1. Insert at head\n";
        cout << "2. Insert at tail\n";
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

            // Insert at head
            insertAtHead(head, data);

            // Display the linked list
            display(head);

            break;

        case 2:
            // Get the data from user
            cout << "\nEnter the data: ";
            cin >> data;

            // Insert at tail
            insertAtTail(head, data);

            // Display the linked list
            display(head);

            break;

        case 3:
            // Get the data from user
            cout << "\nEnter the data: ";
            cin >> data;

            // Delete the data in linked list
            deleteData(head, data);

            // Display the linked list
            display(head);

            break;

        case 4:
            // Display the linked list
            display(head);

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

        // Print a line
        printLine();
    }

    return 0;
} // main
