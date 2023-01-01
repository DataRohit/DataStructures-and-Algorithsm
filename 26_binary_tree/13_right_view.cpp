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
    space += 10;

    // Process right child first
    printTree(root->right, space);

    // Print spaces
    cout << "\n";
    for (int i = 10; i < space; i++)
        cout << " ";

    // Prin the current node
    cout << root->data << "\n";

    // Process left child
    printTree(root->left, space);
}

// Function to the right view of the tree
void rightView(Node *root)
{
    // If our root node is NULL
    if (root == NULL)
    {
        // Return nothing so to print nothing
        return;
    }

    // Queue to store the tree elements
    queue<Node *> q;

    // Traverse the first level (level 0) manually
    q.push(root);

    // Loop over till the queue is empty
    while (!q.empty())
    {
        // Store the number of nodes in the level
        int n = q.size();

        // Loop over queue elements
        for (int i = 0; i < n; i++)
        {
            // Store the front of the queue
            Node *curr = q.front();

            // Pop the queue to remove the front element
            q.pop();

            // If curr node is rightmost
            if (i == n - 1)
            {
                // Print its data
                cout << curr->data << "\n";
            }

            // If left of curr is not null
            if (curr->left != NULL)
            {
                // Push the left element to the queue
                q.push(curr->left);
            }

            // If right of curr is not null
            if (curr->right != NULL)
            {
                // Push the right element to the queue
                q.push(curr->right);
            }
        }
    }
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** RIGHT VIEW OF BINARY TREE *****\n\n";
    printLine();

    // Create a root node pointer
    struct Node *root = new Node(1);

    // Add the child nodes to the root node
    root->left = new Node(2);
    root->right = new Node(3);

    // Add more child nodes
    root->left->left = new Node(4);

    root->right->left = new Node(5);
    root->right->right = new Node(6);

    root->right->left->left = new Node(7);

    /*
     * Current Tree Structure
     *
     *          1
     *        /   \
     *       2     3
     *      /     / \
     *     4     5   6
     *          /
     *         7
     */

    /*
     * The output should be
     *
     * 1
     * 3
     * 6
     * 7
     */

    // Print the binary tree
    cout << "The Stored Binary Tree is:\n\n";
    printTree(root, 0);
    cout << "\n\n";

    // Print the right view of the tree
    cout << "The Right View of Binary Tree is:\n";
    rightView(root);
    cout << "\n\n";
}