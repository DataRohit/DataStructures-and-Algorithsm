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

// Function to get the height of the tree
int getHeight(Node *root)
{
    // Base Case
    if (root == NULL)
        return 0;

    // Get the height of left and right subtree recursively
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    // Return the height of tree
    return max(leftHeight, rightHeight) + 1;
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** HEIGHT OF TREE *****\n\n";
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

    // Print the height of tree
    cout << "The Height of the Tree is: " << getHeight(root) << "\n\n";
}