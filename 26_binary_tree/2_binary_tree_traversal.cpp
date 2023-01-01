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

// Function to traverse the tree in Inorder
void inorder(struct Node *root)
{
    // Base Case
    if (root == NULL)
        return;

    //* 1. Traverse the left subtree
    inorder(root->left);

    //* 2. Visiting the node
    cout << root->data << " ";

    //* 3. Traverse the right subtree
    inorder(root->right);
}

// Function to traverse the tree in Preorder
void preorder(struct Node *root)
{
    // Base Case
    if (root == NULL)
        return;

    //* 1. Visiting the node
    cout << root->data << " ";

    //* 2. Traverse the left subtree
    preorder(root->left);

    //* 3. Traverse the right subtree
    preorder(root->right);
}

// Function to travers the tree in Postorder
void postorder(struct Node *root)
{
    // Base Case
    if (root == NULL)
        return;

    //* 1. Traverse the left subtree
    postorder(root->left);

    //* 2. Traverse the right subtree
    postorder(root->right);

    //* 3. Visiting the node
    cout << root->data << " ";
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** BINARY TREE TRAVERSALS *****\n\n";
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

    // Print the Inorder traversal result
    cout << "The Inorder Expressions is:\n";
    inorder(root);
    cout << "\n\n";

    // Print the Preorder traversal result
    cout << "The Preorder Expressions is:\n";
    preorder(root);
    cout << "\n\n";

    // Print the Postorder traversal result
    cout << "The Postorder Expressions is:\n";
    postorder(root);
    cout << "\n\n";
}