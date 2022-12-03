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

// Function get the length of linked list
int getLength(node *head)
{
    // Default length = 0
    int l = 0;

    // Make a temp node to traverse over the linked list
    node *temp = head;

    // Loop until we reach the end of linked list
    while (temp != NULL)
    {
        // Update the length
        l++;

        // Move to next node
        temp = temp->next;
    }

    return l;
}

// Function to add an intersection in linked list
void intersect(node *&head1, node *&head2, int pos)
{
    // Temp nodes for both linkedlist
    node *temp1 = head1;
    node *temp2 = head2;

    // Find the node at pos in head1 linked list
    pos--;
    while (pos--)
    {
        temp1 = temp1->next;
    }

    // Traverse head2 linked list and get the last node
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }

    /*
     *  Pointer the last node of head2 linked list
     *  To the node at pos in head1 linked list
     */
    temp2->next = temp1;
}

// Function to check for intersection in linked list
int findIntersection(node *&head1, node *&head2)
{
    // Get the length of both the linked list
    int l1 = getLength(head1);
    int l2 = getLength(head2);

    // Calculate the difference in length of linked list
    int diff = 0;

    // Initialize pointers for both the long and short linked list
    node *longHead, *shortHead;

    // If first linked list longer than second
    if (l1 > l2)
    {
        // Update the difference
        diff = l1 - l2;

        // Update the longHead and shortHead
        longHead = head1;
        shortHead = head2;
    }
    else
    {
        // Update the difference
        diff = l2 - l1;

        // Update the longHead and shortHead
        longHead = head2;
        shortHead = head1;
    }

    // Loop till we find the intersection in longHead
    while (diff)
    {
        // Update the longHead
        longHead = longHead->next;

        // If linked list is finished
        if (longHead == NULL)
        {
            // No intersection found
            return -1;
        }

        // Decrement the difference
        diff--;
    }

    // Traverse through both linked lists
    while (longHead != NULL && shortHead != NULL)
    {
        // If intersection found
        if (longHead == shortHead)
        {
            // Return data of intersection node
            return longHead->data;
        }

        // Update the longHead and shortHead
        longHead = longHead->next;
        shortHead = shortHead->next;
    }

    // If no intersection found
    return -1;
} // findIntersection

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
    cout << "***** INTERSECTING LINKED LIST *****\n\n";
    printLine();

    // Create heads for both the linked list
    node *head1 = NULL;
    node *head2 = NULL;

    // Add elements to linked list 1
    insertAtTail(head1, 10);
    insertAtTail(head1, 20);
    insertAtTail(head1, 30);
    insertAtTail(head1, 40);
    insertAtTail(head1, 50);
    insertAtTail(head1, 60);
    insertAtTail(head1, 70);
    insertAtTail(head1, 80);

    // Add elements to linked list 2
    insertAtTail(head2, 100);
    insertAtTail(head2, 200);
    insertAtTail(head2, 300);
    insertAtTail(head2, 400);
    insertAtTail(head2, 500);

    // Insert intersection
    intersect(head1, head2, 5);

    // Display the linked lists
    display(head1);
    display(head2);

    // Check if intersection found
    if (findIntersection(head1, head2) != -1)
    {
        cout << "\nIntersection found at: " << findIntersection(head1, head2) << "\n\n";
    }
    else
    {
        cout << "\nNo Intersection found!"
             << "\n\n";
    }

    return 0;
} // main
