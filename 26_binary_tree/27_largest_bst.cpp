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

// Create a structure to store the information for every node
struct Info
{
    int size, max, min, ans;
    bool isBST;
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

// Function to get the largest BST in Binary Tree
Info largestBSTinBT(Node *root)
{
    // Check if root is NULL
    if (root == NULL)
    {
        // Return the default values
        return {0, INT_MIN, INT_MAX, 0, true};
    }

    // Check if root is leaf node
    if (!root->left && !root->right)
    {
        // Return the values for leaf node
        return {1, root->data, root->data, 1, true};
    }

    // Calls for left and right sub trees
    Info leftInfo = largestBSTinBT(root->left);
    Info rightInfo = largestBSTinBT(root->right);

    // Information for current level
    Info curr;

    // Update the current level size
    curr.size = (1 + leftInfo.size + rightInfo.size);

    // Check if BST formed at current node
    if (leftInfo.isBST && rightInfo.isBST && leftInfo.max < root->data && rightInfo.min > root->data)
    {
        // Update the current level information
        curr.min = min(leftInfo.min, min(rightInfo.min, root->data));
        curr.max = max(leftInfo.max, max(rightInfo.max, root->data));

        curr.ans = curr.size;

        curr.isBST = true;

        // Return the current level information
        return curr;
    }

    // If BST is not formed
    curr.ans = max(leftInfo.ans, rightInfo.ans);
    curr.isBST = false;

    // Return the information of last found BST
    return curr;
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** LARGEST BINARY SEARCH TREE *****\n\n";
    printLine();

    Node *root = new Node(8);

    root->left = new Node(2);
    root->right = new Node(7);

    root->left->left = new Node(1);

    root->right->left = new Node(5);
    root->right->right = new Node(9);

    root->right->left->left = new Node(4);
    root->right->left->right = new Node(6);

    /*
     * Current Tree Structure
     *
     *          8
     *         / \
     *        2   7
     *       /   / \
     *      1   5   9
     *         / \
     *        4   6
     */

    // Print the binary tree
    cout << "The Stored Binary Tree is:\n\n";
    printTree(root, 0);
    cout << "\n\n";

    // Get the largest BST in BT
    Info largestBST = largestBSTinBT(root);

    // Print the Output
    cout << "The Size of Largest BST: " << largestBST.ans << "\n\n";
}