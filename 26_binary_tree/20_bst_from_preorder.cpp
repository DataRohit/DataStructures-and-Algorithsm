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

// Function to build the BST from preorder sequence
Node *constructBST(vector<int> preorder, int *preorderIdx, int key, int min, int max, int n)
{
    // Base Case
    if (*preorderIdx >= n)
    {
        return NULL;
    }

    // Initialize the root node by NULL
    Node *root = NULL;

    // Check the conditions for the value
    if (key > min && key < max)
    {
        // Create a new node for the values
        // Assign the new node to root
        root = new Node(key);

        // Update the preorder index
        *preorderIdx = *preorderIdx + 1;

        // Check if valid preorder index
        if (*preorderIdx < n)
        {
            root->left = constructBST(preorder, preorderIdx, preorder[*preorderIdx], min, key, n);
        }

        if (*preorderIdx < n)
        {
            root->right = constructBST(preorder, preorderIdx, preorder[*preorderIdx], key, max, n);
        }
    }

    // Return NULL if value does not satisfy BST conditions
    return root;
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** BINARY SEARCH TREE FROM PREORDER *****\n\n";
    printLine();

    // Initializing the preorder sequence
    vector<int> preorder = {10, 2, 1, 13, 11};

    // Initializing the required variables
    int n = preorder.size();
    int preorderIdx = 0;

    // Create the BST
    Node *root = constructBST(preorder, &preorderIdx, preorder[0], INT_MIN, INT_MAX, n);

    /*
     * Constructed Tree Structure
     *
     *          10
     *         /  \
     *        2   13
     *       /    /
     *      1    11
     */

    // Print the binary tree
    cout << "The Built Binary Tree is:\n\n";
    printTree(root, 0);
    cout << "\n\n";
}