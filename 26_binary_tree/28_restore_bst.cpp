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

// Function to print the inorder
void printInorder(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    // Go to left sub tree
    printInorder(root->left);

    // Print the node data
    cout << root->data << " ";

    // Go to right sub tree
    printInorder(root->right);
}

// Swap utility function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Uitiliy function
void calcPointers(Node *root, Node **first, Node **mid, Node **last, Node **prev)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    // Calls for left sub tree
    calcPointers(root->left, first, mid, last, prev);

    // If violating the property
    if (*prev && root->data < (*prev)->data)
    {
        // First violation condition
        if (!*first)
        {
            *first = *prev;
            *mid = root;
        }

        // Second violation condition
        else
        {
            *last = root;
        }
    }

    // Update the previous
    *prev = root;

    // Calls for right sub tree
    calcPointers(root->right, first, mid, last, prev);
}

// Function to restore the BST
void restoreBST(Node *root)
{
    // Declare all the required variables
    Node *first, *mid, *last;
    Node *prev;

    // Inialize all the variables
    first = NULL;
    mid = NULL;
    last = NULL;
    prev = NULL;

    // Call the utility function
    calcPointers(root, &first, &mid, &last, &prev);

    // Case 1 -> First and last node both exist
    if (first && last)
    {
        // Swap the data of first and the last node
        swap(&(first->data), &(last->data));
    }

    // Case 2 -> First and mid exist and last does not exist
    else if (first && mid)
    {
        // Swap the data of first and the mid node
        swap(&(first->data), &(mid->data));
    }
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** RESTORE BINARY SEARCH TREE *****\n\n";
    printLine();

    Node *root = new Node(6);

    root->left = new Node(9);
    root->right = new Node(3);

    root->left->left = new Node(1);
    root->left->right = new Node(4);

    root->right->right = new Node(10);

    /*
     * Current Tree Structure
     *
     *          6
     *         / \
     *        9   3
     *       / \   \
     *      1   4   10
     *
     */

    // Print the binary tree
    cout << "The Stored Binary Tree is:\n\n";
    printTree(root, 0);
    cout << "\n\n";

    // Print the inorder of the binary tree
    cout << "The Inorder Sequence of Store Binary Tree is:\n";
    printInorder(root);
    cout << "\n\n";

    // Restoring the binary search tree
    restoreBST(root);

    // Print the binary tree
    cout << "The Restored Binary Tree is:\n\n";
    printTree(root, 0);
    cout << "\n\n";

    // Print the inorder of the binary tree
    cout << "The Inorder Sequence of Restored Binary Tree is:\n";
    printInorder(root);
    cout << "\n\n";
}