#include <bits/stdc++.h>
using namespace std;

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

// Create a structure for tree node
struct Node
{
    // Members of the structure
    int data;
    struct Node *left;
    struct Node *right;

    // Constructor
    Node(int val)
    {
        // Add input values as the data of node
        data = val;

        // Initialize left and right childs as NULL
        left = NULL;
        right = NULL;
    }
};

// Function to print the binary tree in 2D
void printTree(Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 5;

    // Process right child first
    printTree(root->right, space);

    // Print spaces
    cout << "\n";
    for (int i = 5; i < space; i++)
        cout << " ";

    // Prin the current node
    cout << root->data << "\n";

    // Process left child
    printTree(root->left, space);
}

// Function to get the sum of elements at level k
int sumAtK(Node *root, int k)
{
    // If our root node is NULL
    if (root == NULL)
    {
        // Return -1 - Sum cannot be calculated
        return -1;
    }

    // Queue to store the tree elements
    queue<Node *> q;

    // Traverse the first level (level 0) manually
    q.push(root);
    q.push(NULL);

    // Variable to keep track of level
    int level = 0;

    // Variable to keep track of sum
    int sum = 0;

    // Loop till the queue is empty
    while (!q.empty())
    {
        // Get the front node from the queue
        Node *node = q.front();

        // Pop the element from the queue
        q.pop();

        // If the node is not NULL
        if (node != NULL)
        {
            // If current level == required level
            if (level == k)
            {
                // Add the current data to the sum
                sum += node->data;
            }

            // If node has left child push to stack
            if (node->left)
            {
                q.push(node->left);
            }

            // If node has right child push to stack
            if (node->right)
            {
                q.push(node->right);
            }
        }
        // If Queue in not empty
        else if (!q.empty())
        {
            // Add NULL to the queue after finishing the level
            q.push(NULL);

            // Update the level value
            level++;
        }
    }

    // Return the required sum
    return sum;
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** SUM OF ELEMENTS AT Kth LEVEL *****\n\n";
    printLine();

    // Create a root node pointer
    struct Node *root = new Node(1);

    // Add the child nodes to the root node
    root->left = new Node(2);
    root->right = new Node(3);

    // Add more child nodes
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    /*
     * Current Tree Structure
     *
     *          1
     *        /   \
     *       2     3
     *      / \   / \
     *     4   5 6   7
     *
     */

    // Print the binary tree
    cout << "The Stored Binary Tree is:\n\n";
    printTree(root, 0);
    cout << "\n\n";

    // Take user input for k
    int k;
    cout << "Enter the value for level (k): ";
    cin >> k;

    // Print the sum of elements at level k
    cout
        << "\nThe sum of element at the level " << k
        << " is: " << sumAtK(root, k) << "\n\n";
}