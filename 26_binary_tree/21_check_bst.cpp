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

// Function to check for BST
bool isBST(Node *root, Node *min = NULL, Node *max = NULL)
{
    // Base Case
    if (root == NULL)
    {
        return true;
    }

    // Min value should not be null
    // Value of data should be more than or equal to min
    if (min != NULL && root->data <= min->data)
    {
        return false;
    }

    // Max value should not be null
    // Value of data should be less than or equal to max
    if (max != NULL && root->data >= max->data)
    {
        return false;
    }

    // Calls for left and right sub tree
    bool leftValid = isBST(root->left, min, root);
    bool rightValid = isBST(root->right, root, max);

    // If both sub tree valid then the tree is valid
    return leftValid && rightValid;
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** BINARY TREE *****\n\n";
    printLine();

    /*
     * Current Tree Structure
     *
     *          3
     *         / \
     *        2   7
     *       /   / \
     *      1   5   8
     *         / \
     *        4   6
     */

    Node *root = new Node(3);

    root->left = new Node(2);
    root->right = new Node(7);

    root->left->left = new Node(1);

    root->right->left = new Node(5);
    root->right->right = new Node(8);

    root->right->left->left = new Node(4);
    root->right->left->right = new Node(6);

    // Print the binary tree
    cout << "The Stored Binary Tree is:\n\n";
    printTree(root, 0);
    cout << "\n\n";

    // Check if Valid BST
    if (isBST(root, NULL, NULL))
    {
        cout << "Valid BST!\n\n";
    }
    else
    {
        cout << "Invalid BST!\n\n";
    }
}