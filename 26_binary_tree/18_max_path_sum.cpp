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

// Utility function
int getMaxPathSumUtil(Node *root, int &ans)
{
    // If root is null -> path not exist
    if (root == NULL)
    {
        // Sum will be 0
        return 0;
    }

    // Sum of left and right paths through left and right subtree
    int left = getMaxPathSumUtil(root->left, ans);
    int right = getMaxPathSumUtil(root->right, ans);

    // Calculate the maximium of node
    int nodeMax = max(max(root->data, root->data + left + right), max(root->data + left, root->data + right));

    // Update the answer
    ans = max(ans, nodeMax);

    // Getting the final answer
    int singlePathSum = max(root->data, max(root->data + left, root->data + right));

    // Return the answer
    return singlePathSum;
}

// Function to return the max path sum
int getMaxPathSum(Node *root)
{
    // Set the answer variable
    int ans = INT_MIN;

    // Create a utility function to calculate the max of the different paths
    getMaxPathSumUtil(root, ans);

    // Return the answer
    return ans;
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** MAX PATH SUM BINARY TREE *****\n\n";
    printLine();

    // Create a root node pointer
    struct Node *root = new Node(1);

    // Add the child nodes to the root node
    root->left = new Node(-12);
    root->right = new Node(3);

    // Add more child nodes
    root->left->left = new Node(4);

    root->right->left = new Node(5);
    root->right->right = new Node(-6);

    /*
     * Current Tree Structure
     *
     *          1
     *        /   \
     *      -12    3
     *      /     / \
     *     4     5   -6
     *
     */

    // Print the binary tree
    cout << "The Stored Binary Tree is:\n\n";
    printTree(root, 0);
    cout << "\n\n";

    // Print the Max Path Sum
    cout
        << "The Max Path Sum is: "
        << getMaxPathSum(root) << "\n\n";
}