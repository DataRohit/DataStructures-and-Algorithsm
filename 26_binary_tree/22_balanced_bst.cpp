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

// Function to create a BST from sorted array
Node *sortedArrayToBST(vector<int> arr, int start, int end)
{
    // If start > end
    if (start > end)
    {
        return NULL;
    }

    // Find the mid
    int mid = (start + end) / 2;

    // Create a new node for the mid element of arr
    Node *root = new Node(arr[mid]);

    // Construct the left and right sub tree
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    // Return the root node of the tree
    return root;
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** BALANCED BINARY SEARCH TREE *****\n\n";
    printLine();

    // Initialize the array with sorted numbers
    vector<int> arr = {10, 20, 30, 40, 50};

    // Build the BST
    Node *root = sortedArrayToBST(arr, 0, arr.size() - 1);

    // Print the binary tree
    cout << "The Stored Binary Tree is:\n\n";
    printTree(root, 0);
    cout << "\n\n";
}