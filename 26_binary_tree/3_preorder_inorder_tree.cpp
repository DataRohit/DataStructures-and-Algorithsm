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

// Function to search the index of curr in inorder sequence
int search(int inorder[], int start, int end, int curr)
{
    // Traverse the inorder sequence
    for (int i = start; i <= end; i++)
    {
        // Check if current element == array element
        if (inorder[i] == curr)
        {
            // Return the index if found
            return i;
        }
    }

    // Else return -1
    return -1;
}

// Function to build the tree
Node *buildTree(int preorder[], int inorder[], int start, int end)
{
    // Static index for traversing the preorder sequence
    static int idx = 0;

    // Base Case
    if (start > end)
        return NULL;

    // Get the first element (root node data) from the preorder sequence
    int curr = preorder[idx];

    // Update the idx pointer
    idx++;

    // Create a new node with our current data
    Node *node = new Node(curr);

    // If start == end we only have one element
    if (start == end)
        return node;

    // Get the position of current element in inorder sequence
    int pos = search(inorder, start, end, curr);

    // Build the left subtree
    node->left = buildTree(preorder, inorder, start, pos - 1);

    // Build the right subtree
    node->right = buildTree(preorder, inorder, pos + 1, end);

    // Return the node
    return node;
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** TREE FROM PREORDER AND INORDER *****\n\n";
    printLine();

    // Consider our preorder and inorder sequences
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};

    // Build our tree and get the root node
    Node *root = buildTree(preorder, inorder, 0, 4);

    // Print the Inorder sequence
    cout << "The Input Inorder Expressions is:\n";
    for (auto i : inorder)
        cout << i << " ";
    cout << "\n\n";

    // Print the Preorder sequence
    cout << "The Input Preorder Expressions is:\n";
    for (auto i : preorder)
        cout << i << " ";
    cout << "\n\n";

    // Print the binary tree
    cout << "The Built Binary Tree is:\n\n";
    printTree(root, 0);
    cout << "\n\n";
}