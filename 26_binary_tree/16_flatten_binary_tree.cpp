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

// Function to flatten the binary tree
void flatten(Node *root)
{
    // Base Case -> Tree already flatten
    if (root == NULL || root->left && root->right == NULL)
    {
        return;
    }

    // Flatten only if left not null
    if (root->left != NULL)
    {
        // Flatten the left sub tree
        flatten(root->left);

        // Save the right subtree
        Node *temp = root->right;

        // Add left sub tree to right and empty the left sub tree
        root->right = root->left;
        root->left = NULL;

        // Loop the right sub tree to find the tail
        Node *t = root->right;
        while (t->right != NULL)
        {
            t = t->right;
        }

        // Add the store right sub tree to the flatten tree
        t->right = temp;
    }

    // Flatten the right sub tree
    flatten(root->right);
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** FLATTEN BINARY TREE IN PREORDER *****\n\n";
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

    // Print the binary tree
    cout << "The Stored Binary Tree is:\n\n";
    printTree(root, 0);
    cout << "\n\n";

    // Call the function to flatten the tree
    flatten(root);

    // Print the flatten binary tree
    cout << "The Flatten Binary Tree is:\n\n";
    printTree(root, 0);
    cout << "\n\n";
}