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

// Function to insert value in binary search tree
Node *insertInBST(Node *root, int val)
{
    // If root becomes null
    if (root == NULL)
    {
        // Return the new node with the value to be added to tree
        return new Node(val);
    }

    // If the value is less than the root data
    if (val < root->data)
    {
        // Add the new value to left
        root->left = insertInBST(root->left, val);
    }
    else
    {
        // If the value is greater than the root data
        // Add the new value to right
        root->right = insertInBST(root->right, val);
    }

    // Return the updated root node
    return root;
}

// Function to search value in binary search tree
Node *searchInBST(Node *root, int key)
{
    // If the root is null
    if (root == NULL)
    {
        return NULL;
    }

    // If root data is the key
    if (key == root->data)
    {
        // Return the root
        return root;
    }

    // If key in right sub tree
    if (key > root->data)
    {
        // Search in right sub tree and return the node if found
        return searchInBST(root->right, key);
    }

    // Search in left sub tree and return the node if found
    return searchInBST(root->left, key);
}

// Function to find the Inorder Successor
Node *inorderSucc(Node *root)
{
    // Save the current root pointer
    Node *curr = root;

    // Loop till the current node and left child are not null
    while (curr && curr->left != NULL)
    {
        // Update the current pointer
        curr = curr->left;
    }

    // Return the updated value
    return curr;
}

// Function to delete value in binary search tree
Node *deleteInBST(Node *root, int key)
{
    // If the key is less than the root data
    if (key < root->data)
    {
        // Search the key in left sub tree
        root->left = deleteInBST(root->left, key);
    }

    // If the key is greater than the root data
    else if (key > root->data)
    {
        // Search the key in right sub tree
        root->right = deleteInBST(root->right, key);
    }

    // If the key is found
    else
    {
        // If left child is null and right child exist
        if (root->left == NULL)
        {
            // Save the sub tree after the key
            Node *temp = root->right;

            // Free the element
            free(root);

            // Return the remaining tree
            return temp;
        }

        // If right child is null and left child exist
        else if (root->right == NULL)
        {
            // Save the sub tree after the key
            Node *temp = root->left;

            // Free the element
            free(root);

            // Return the remaining tree
            return temp;
        }

        // Find inorder successor of the key
        Node *temp = inorderSucc(root->right);

        // Update the value in the tree
        root->data = temp->data;

        // Update the remaining right sub tree
        root->right = deleteInBST(root->right, temp->data);
    }

    return root;
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** BINARY SEARCH TREE - OPERATIONS *****\n\n";
    printLine();

    // Initialize the root node with NULL
    Node *root = NULL;

    // Create a array to store the BST elements
    vector<int> elements = {3, 7, 2, 8, 5, 1, 6, 4};

    // Loop over elements of the array
    for (auto i : elements)
    {
        // Add elements to the tree
        root = insertInBST(root, i);
    }

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

    // Print the binary tree
    cout << "The Stored Binary Tree is:\n\n";
    printTree(root, 0);
    cout << "\n\n";

    // Search if element 5 exist in the BST
    if (!searchInBST(root, 5))
    {
        cout << "Key " << 5 << " Doesn't Exist!\n\n";
    }
    else
    {
        cout << "Key " << 5 << " Found!\n\n";
    }

    // Search if element 10 exist in the BST
    if (!searchInBST(root, 10))
    {
        cout << "Key " << 10 << " Doesn't Exist!\n\n";
    }
    else
    {
        cout << "Key " << 10 << " Found!\n\n";
    }

    // Delete the element 5 in BST
    root = deleteInBST(root, 5);

    // Print the Updated tree
    cout << "The Updated Binary Tree is:\n\n";
    printTree(root, 0);
    cout << "\n\n";
}