#include <bits/stdc++.h>
using namespace std;

/*
 * Diameter of Tree
 *
 * Number of nodes in the longest path between any 2 leaves
 */

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

// Function to get the height of tree
int getHeight(Node *root)
{
    // Base Case
    if (root == NULL)
        return 0;

    // Return the height of tree
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

// Function to get the diameter of the tree if height is given
// Time Complexity -> O(n)
int getDiameter(Node *root, int *height)
{
    // Base Case
    if (root == NULL)
    {
        // Set height to 0
        *height = 0;

        // Return 0
        return 0;
    }

    // Initialize left and right height
    int lh = 0, rh = 0;

    // Get the left diameter
    int lDiameter = getDiameter(root->left, &lh);
    int rDiameter = getDiameter(root->right, &rh);

    // Calculate our current diameter
    int currDiameter = lh + rh + 1;

    // Update our height
    *height = max(lh, rh) + 1;

    // Return the diameter of tree
    return max(currDiameter, max(lDiameter, rDiameter));
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** DIAMETER OF TREE *****\n\n";
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

    // Set Height variable and Print the diameter of tree
    int height = 0;
    cout << "The Diameter of the Tree is: " << getDiameter(root, &height) << "\n\n";
}