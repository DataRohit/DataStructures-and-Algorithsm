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

// Function to check for balanced binary tree
// Time Complexity -> O(n)
bool isBalanced(Node *root, int *height)
{
    // Base Case -> If root has no children
    if (root == NULL)
    {
        // Set height to 0
        *height = 0;

        // It is balanced
        return true;
    }

    // Get the height of left and right subtree
    int lh = 0;
    int rh = 0;

    // If any node the binary tree is unbalnced then the tree is unbalnaced
    if (isBalanced(root->left, &lh) == false || isBalanced(root->right, &rh) == false)
    {
        // Binary tree is not balanced
        return false;
    }

    // Update our height
    *height = max(lh, rh) + 1;

    // Get the absolute height difference
    if (abs(lh - rh) <= 1)
    {
        // Balanced tree
        return true;
    }
    else
    {
        // Unbalnced tree
        return false;
    }
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** BALANCED HEIGHT TREE *****\n\n";
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

    // Set the height variable
    int height = 0;

    // Check if our tree is balnced
    if (isBalanced(root, &height))
    {
        cout << "The Tree is Balanced!";
    }
    else
    {
        cout << "The Tree is Unbalnced!";
    }

    // Add line break
    cout << "\n\n";

    // Create a root2 node pointer
    struct Node *root2 = new Node(1);

    // Add the child nodes to the root2 node
    root2->left = new Node(2);

    // Add more child nodes
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);

    /*
     * Current Tree Structure
     *
     *          1
     *        /
     *       2
     *      / \
     *     4   5
     *
     */

    // Print the binary tree
    cout << "The Stored Binary Tree is:\n\n";
    printTree(root2, 0);
    cout << "\n\n";

    // Set the height variable
    height = 0;

    // Check if our tree is balnced
    if (isBalanced(root2, &height))
    {
        cout << "The Tree is Balanced!";
    }
    else
    {
        cout << "The Tree is Unbalanced!";
    }

    // Add line break
    cout << "\n\n";
}