#include <iostream>
using namespace std;

/*
 *  Floyd's Algorithm
 *  Hare and Totoise Algorithm
 *
 *  Distance moved by fast ptr =  m + n + (l * j)
 *  Distance moved by slow ptr =  m + n + (l * i)
 *
 *  m = distance from head to start of loop
 *  n = distance from start of loop to meeting point
 *  l = length of loop
 *  i = number of times slow ptr has completed the loop
 *  j = number of times fast ptr has completed the loop
 */

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

    return;
}

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

    // Point new node to head
    newNode->next = head;

    // Make new node as head
    head = newNode;

    return;
}

// Function to search element in linked list
void searchData(node *head, int data)
{
    // Initialize temp node to head for traversing
    node *temp = head;

    // If head is NULL, then linked list is empty
    if (head == NULL)
    {
        cout << "\nLinked list is empty!\n\n";
        return;
    }

    // Traverse till we find the last node
    int pos = 1; // Var to store position of element

    while (temp != NULL)
    {
        // If data is found, then print message
        if (temp->data == data)
        {
            cout << "\nData found as position: " << pos << "\n\n";
            return;
        }

        // Update the position counter
        pos++;

        // Move to next node
        temp = temp->next;
    }

    // If data is not found, then print message
    cout << "\nData not found!\n\n";
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

    // If head is the element to be deleted
    if (head->data == data)
    {
        // Make the next node as head
        head = head->next;

        // Delete the previous head
        delete temp;

        return;
    }

    // Finding the node preceding the node to be deleted
    while (temp->next->data != data)
    {
        // Move to next node
        temp = temp->next;

        // If we reach the end of linked list, then print message
        if (temp->next == NULL)
        {
            cout << "\nData not found!\n";
            return;
        }
    }

    // Save the node to delete
    node *toDelete = temp->next;

    // Update our linked list by updating the next pointer
    temp->next = temp->next->next;

    // Delete the node
    delete toDelete;
} // deleteData

// Function to reverse the linked list by returning the new head
node *
reverseIterative(node *&head)
{
    /*
     *  Reverse the linked list by
     *  Iterative method
     */

    // Initialize all required pointers
    node *prev = NULL;
    node *curr = head;
    node *next;

    // Loop untill we reach the end of linked list
    while (curr != NULL)
    {
        // Initialize and update the next pointer
        next = curr->next;

        // Update the next pointer of current node
        curr->next = prev; // Reverse the link

        // Update the previous pointer
        prev = curr;

        // Update the current pointer
        curr = next;
    }

    // return the new head of our linked list
    return prev;
}

// Function to reverse the linked list by returnin the new head
node *
reverseRecursive(node *&head)
{
    /*
     *  Reverse the linked list by
     *  Iterative method
     */

    // If head is NULL or there is only one node in linked list
    if (head == NULL || head->next == NULL)
    {
        // Return the head
        return head;
    }

    /*
     *  Using recursion to reverse the linked list
     *  The linked list starting from 2nd position is reversed
     */
    node *newHead = reverseRecursive(head->next);

    // Update the next pointer of 2nd node
    head->next->next = head;

    // Update the next pointer of 1st node
    head->next = NULL;

    // Return the new head
    return newHead;
}

// Function to reverse k nodes of linked list
node *
reversek(node *&head, int k)
{
    // Initialize all required pointers
    node *prev = NULL;
    node *curr = head;
    node *next;

    // Keep track of k nodes using count
    int count = 0;

    // Loop for k nodes and reverse them
    while (curr != NULL && count < k)
    {
        // Update the next pointer
        next = curr->next;

        // Update the next pointer of current node
        curr->next = prev;

        // Update the previous pointer
        prev = curr;

        // Update the current pointer
        curr = next;

        // Update the count
        count++;
    }

    // If there are more nodes left, then reverse them
    if (next != NULL)
    {
        // Reverse the remaining nodes
        head->next = reversek(next, k);
    }

    return prev;
} // reversek

// Function to make a cycle in linked list
void makeCycle(node *&head, int pos)
{
    // Make temp node to traverse over the linked list
    node *temp = head;

    // Startnode to store the node where cycle starts
    node *startNode;

    // Count to keep track of position
    int count = 1;

    // Traverse till we find the last node
    while (temp->next != NULL)
    {
        // If the position is found
        if (count == pos)
        {
            // Update the startNode
            startNode = temp;
        }

        // Move to next node
        temp = temp->next;

        // Increment count
        count++;
    }

    // Point last node to startNode
    temp->next = startNode;

    // Print message
    cout << "\nCycle created at position: " << pos << "\n\n";
}

// Function to detect cycle in linked list
bool detectCycle(node *&head)
{
    // Initialize slow and fast pointers
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        // Update slow pointer by 1 node
        slow = slow->next;

        // Update fast pointer by 2 nodes
        fast = fast->next->next;

        // If cycle detected
        if (fast == slow)
        {
            // Print the message
            cout << "\nCycle detected!\n\n";

            return true;
        }
    }

    // If cycle not detected
    cout << "\nCycle not detected!\n\n";

    return false;
}

// Function to remove the detected cycle in linked list
void removeCycle(node *&head)
{
    // Initialize slow and fast pointers
    node *slow = head;
    node *fast = head;

    // Loop until fast and slow pointers meet
    do
    {
        // Update slow pointer by 1 node
        slow = slow->next;

        // Update fast pointer by 2 nodes
        fast = fast->next->next;
    } while (slow != fast);

    /*
     *  Once slow and fast pointers meet
     *  Bring the fast pointer to head
     */
    fast = head;

    /*
     *  Loop until the next node of both
     *  slow and fast pointer are same
     */
    while (slow->next != fast->next)
    {
        // Update slow and fast by one node
        slow = slow->next;
        fast = fast->next;
    }

    // Update the next pointer of slow pointer
    slow->next = NULL;

    // Print message
    cout << "Cycle removed!\n\n";
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

// Function to Append last K nodes to start
node *
appendK(node *&head, int k)
{
    // Initialize our pointers
    node *newHead, *newTail, *tail = head;

    // Get the length of linked list
    int l = getLength(head);

    // Keeping track of position
    int count = 1;

    // NOTE: k can be greater than length of linked list
    // So, we need to take modulo of k with length of linked list
    k = k % l;

    // Loop until we reach the last node
    while (tail->next != NULL)
    {
        // If we reach the node before k nodes
        if (count == l - k)
        {
            // Update the newTail
            newTail = tail;
        }

        // If we reach the kth node
        if (count == l - k + 1)
        {
            // Update the newHead
            newHead = tail;
        }

        // Move to next node
        tail = tail->next;

        // Increment count
        count++;
    }

    // NewTail pointing to NULL
    newTail->next = NULL;

    // Old Tail pointing to old Head
    tail->next = head;

    // Return the newHead
    return newHead;
} // appendK

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
    cout << "***** SINGLY LINKED LIST *****\n\n";
    printLine();

    // Var to store the data
    int data;

    // Declare the head of the linked list
    node *head = NULL;

    // Loop till user exits
    while (1)
    {
        // Declare all the operations
        cout << "1. Insert at tail\n";
        cout << "2. Insert at head\n";
        cout << "3. Search an element\n";
        cout << "4. Delete an element\n";
        cout << "5. Reverse list iteratively\n";
        cout << "6. Reverse list recusively\n";
        cout << "7. Reverse k nodes\n";
        cout << "8. Make cycle\n";
        cout << "9. Detect cycle\n";
        cout << "10. Remove cycle\n";
        cout << "11. Append K nodes to start\n";
        cout << "12. Display linked list\n";
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

            break;

        case 2:
            // Get the data from user
            cout << "\nEnter the data: ";
            cin >> data;

            // Insert at tail
            insertAtHead(head, data);

            // Display the linked list
            display(head);

            break;

        case 3:
            // Get the data from user
            cout << "\nEnter the data: ";
            cin >> data;

            // Search the data in linked list
            searchData(head, data);

            break;

        case 4:
            // Get the data from user
            cout << "\nEnter the data: ";
            cin >> data;

            // Delete the data in linked list
            deleteData(head, data);

            // Display the linked list
            display(head);

            break;

        case 5:
            /*
             *  Get new head of our reversed linked list
             *  and update the head of our linked list
             */

            head = reverseIterative(head);

            // Display the linked list
            display(head);

            break;

        case 6:
            /*
             *  Get new head of our reversed linked list
             *  and update the head of our linked list
             */

            head = reverseRecursive(head);

            // Display the linked list
            display(head);

            break;

        case 7:
            // Get the data from user
            int k;
            cout << "\nEnter the value of k: ";
            cin >> k;

            // Reverse l nodes in linked list
            head = reversek(head, k);

            // Display the linked list
            display(head);

            break;

        case 8:
            // Get the data from user
            cout << "\nEnter the position: ";
            cin >> data;

            // Delete the data in linked list
            makeCycle(head, data);

            break;

        case 9:
            // Detect cycle in linked list
            detectCycle(head);

            break;

        case 10:
            // Detect and remove cycle in linked list
            if (detectCycle(head))
            {
                removeCycle(head);
            }

            break;

        case 11:
            // Append Last K nodes to the front
            // Get the data from user
            cout << "\nEnter the value of k: ";
            cin >> k;

            // Append last k nodes to start
            head = appendK(head, k);

            // Display the linked list
            display(head);

            break;

        case 12:
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
