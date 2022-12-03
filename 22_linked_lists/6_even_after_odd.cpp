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

// Function to insert node at tail of linked list
void insertAtTail(node *&head, int data)
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
}

// Function to add even nodes after odd
void evenAfterOdd(node *&head)
{
    // Initialize our odd and even pointers
    node *odd = head;
    node *even = head->next;

    // Store our even pointer
    node *evenStart = even;

    // If next of odd node and next of even node is not NULL
    while (odd->next != NULL && even->next != NULL)
    {
        // Update next of odd to next of even
        odd->next = even->next;

        // Update the odd node
        odd = odd->next;

        // Update next of even to next of odd
        even->next = odd->next;

        // Update the even node
        even = even->next;
    }

    /*
     *  If odd node is the last node in linked list
     *  Point next of last to evenStart
     */
    odd->next = evenStart;

    /*
     *  If even node is the last node in linked list
     *  Point next of last to null
     */
    if (odd->next != NULL)
    {
        even->next = NULL;
    }
}

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
        cout << temp->data << "  ->  ";

        // Move to next node
        temp = temp->next;
    }

    // Add a line break
    cout << "NULL\n\n";
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
    cout << "***** EVEN NODES AFTER ODD NODES *****\n\n";
    printLine();

    // Initialize HEAD for our linked list
    node *head = NULL;

    // Add data to our linked list
    for (int i = 1; i < 7; i++)
    {
        insertAtTail(head, i);
    }

    // Display our default linked list
    display(head);

    // Apply our evenAfterOdd function
    evenAfterOdd(head);

    // Display the modified linked list
    display(head);
}
