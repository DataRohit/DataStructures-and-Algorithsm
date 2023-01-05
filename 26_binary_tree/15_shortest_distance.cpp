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

// Function to find LCA - Lowest Common Ancestor of the input two nodes
Node *getLCA(Node *root, int n1, int n2)
{
    // Cannot find LCA of null values
    if (root == NULL)
    {
        return NULL;
    }

    // If one of the two values is the root
    if (root->data == n1 || root->data == n2)
    {
        // Return root as it is the ancestor for every node
        return root;
    }

    // Find LCA in left and right subtree
    Node *left = getLCA(root->left, n1, n2);
    Node *right = getLCA(root->right, n1, n2);

    // Nodes exist in the left and right subtree
    if (left != NULL && right != NULL)
    {
        return root;
    }

    // Nodes does not exist in the left and right subtree
    if (left == NULL && right == NULL)
    {
        return NULL;
    }

    // Both the nodes in left sub tree
    if (left != NULL)
    {
        return getLCA(root->left, n1, n2);
    }

    // Both the nodes in right sub tree
    if (right != NULL)
    {
        return getLCA(root->right, n1, n2);
    }
}

// Function to calculate the distance of node from LCA
int getDistance(Node *root, int k, int dist)
{
    // If root is null distance cannot be found
    if (root == NULL)
    {
        return -1;
    }

    // If k found in the tree
    if (root->data == k)
    {
        return dist;
    }

    // Check if the node in left sub tree
    int leftDist = getDistance(root->left, k, dist + 1);

    // If found return the distance
    if (leftDist != -1)
    {
        return leftDist;
    }

    // Else return the distance in right sub tree
    return getDistance(root->right, k, dist + 1);
}

// Function to get the final distance
int getDistBtwNodes(Node *root, int n1, int n2)
{
    // Find the LCA
    Node *lca = getLCA(root, n1, n2);

    // Find the left and right distance to node from the LCA
    int d1 = getDistance(lca, n1, 0);
    int d2 = getDistance(lca, n1, 0);

    // Return the total
    return d1 + d1;
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** SHORTEST DISTANCE BETWEEN TWO NODES *****\n\n";
    printLine();

    // Create a root node pointer
    struct Node *root = new Node(1);

    // Add the child nodes to the root node
    root->left = new Node(2);
    root->right = new Node(3);

    // Add more child nodes
    root->left->left = new Node(4);

    root->right->left = new Node(5);
    root->right->right = new Node(6);

    root->right->left->left = new Node(7);

    /*
     * Current Tree Structure
     *
     *          1
     *        /   \
     *       2     3
     *      /     / \
     *     4     5   6
     *          /
     *         7
     */

    // Print the binary tree
    cout << "The Stored Binary Tree is:\n\n";
    printTree(root, 0);
    cout << "\n\n";

    // Print the distance between nodes
    cout
        << "Distance Between nodes 4 and 5 is: "
        << getDistBtwNodes(root, 4, 5) << "\n\n";
}