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

    return;
}

// Function to merget two sorted linked list
node *
mergeSortedIterative(node *&head1, node *&head2)
{
    // Temp nodes for head1 and head2
    node *temp1 = head1;
    node *temp2 = head2;

    // Create a dummy node for merged list
    node *dummyNode = new node(-1);

    // Temp node for dummy node
    node *temp3 = dummyNode;

    // Traverse both the list till one of the list is finished
    while (temp1 != NULL && temp2 != NULL)
    {
        /*
         *  Element of first linked list less than
         *  element of second linked list
         */
        if (temp1->data < temp2->data)
        {
            /*
             *  Update dummyNode by node of first linked list
             */
            temp3->next = temp1;

            // Update the temp1 pointer
            temp1 = temp1->next;
        }
        else
        {
            /*
             *  Update dummyNode by node of second linked list
             */
            temp3->next = temp2;

            // Update the temp1 pointer
            temp2 = temp2->next;
        }

        // Update the dummyNode pointer
        temp3 = temp3->next;
    }

    // Update remaining nodes of linked list 1
    while (temp1 != NULL)
    {
        // Add data to dummyNode
        temp3->next = temp1;

        // Update the temp1
        temp1 = temp1->next;

        // Update the temp3
        temp3 = temp3->next;
    }

    // Update remaining nodes of linked list 2
    while (temp2 != NULL)
    {
        // Add data to dummyNode
        temp3->next = temp2;

        // Update the temp2
        temp2 = temp2->next;

        // Update the temp3
        temp3 = temp3->next;
    }

    return dummyNode->next;
} // mergeSortedIterative

// Function to merget two sorted linked list
node *
mergeSortedRecursive(node *&head1, node *&head2)
{
    // If list 1 is finished
    if (head1 == NULL)
    {
        return head2;
    }

    // If list 2 is finished
    if (head2 == NULL)
    {
        return head1;
    }

    // result to store the new head with smallest data
    node *result;

    // Compare the data in head of both the list
    if (head1->data < head2->data)
    {
        // Update the result node
        result = head1;

        // Rucurssion for next node
        result->next = mergeSortedRecursive(head1->next, head2);
    }
    else
    {
        // Update the result node
        result = head2;

        // Rucurssion for next node
        result->next = mergeSortedRecursive(head1, head2->next);
    }

    return result;
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
    cout << "***** MERGE SORTED LINKED LIST *****\n\n";
    printLine();

    // Arrays to store data of linked list
    int arr1[] = {1, 4, 5, 7, 9, 10};
    int arr2[] = {2, 3, 6, 8, 11};

    // Initialize heads for linked lists
    node *head1 = NULL;
    node *head2 = NULL;

    // Add data to linked list 1
    for (int i = 0; i < 6; i++)
    {
        insertAtTail(head1, arr1[i]);
    }

    // Add data to linked list 2
    for (int i = 0; i < 5; i++)
    {
        insertAtTail(head2, arr2[i]);
    }

    // Display the linked lists
    display(head1);
    display(head2);

    // // Get head of merged linked list using iterative method
    // node * newHead = mergeSortedIterative(head1, head2);

    // Get head of merged linked list using recursive method
    node *newHead = mergeSortedRecursive(head1, head2);

    // Display the merged linked list
    display(newHead);

    return 0;
} // main
