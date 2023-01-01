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

// Function for sum replacement
// Time Complexity -> O(n)
void sumReplacement(Node *root)
{
    // Base Condition
    if (root == NULL)
        return;

    // Call sum replacement for left and right subtree
    sumReplacement(root->left);
    sumReplacement(root->right);

    // Check left child
    if (root->left != NULL)
    {
        root->data += root->left->data;
    }

    // Check right child
    if (root->right != NULL)
    {
        root->data += root->right->data;
    }
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** SUM REPLACEMENT *****\n\n";
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

    // Call the sum replacement function
    sumReplacement(root);

    /*
     * Updated Tree Structure
     *
     *          28
     *        /    \
     *       11    16
     *      / \    / \
     *     4   5  6   7
     *
     */

    // Print the updated binary tree
    cout << "The Updated Binary Tree is:\n\n";
    printTree(root, 0);
    cout << "\n\n";
}