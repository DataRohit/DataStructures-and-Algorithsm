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

// Function to get the path to node from root
bool getPath(Node *root, int n, vector<int> &path)
{
    // If root is null
    if (root == NULL)
    {
        return false;
    }

    // Assuming the path is correct
    path.push_back(root->data);

    // Check if root data is the required data
    if (root->data == n)
    {
        // path is correct
        return true;
    }

    // Go to left sub tree to find the path
    if (getPath(root->left, n, path) || getPath(root->right, n, path))
    {
        // Return true if path found
        return true;
    }

    // Element not exist in tree
    path.pop_back();

    // return false -> path not exist
    return false;
}

// Function to find LCA - Lowest Common Ancestor of the input two nodes
int getLCA(Node *root, int n1, int n2)
{
    // Two vectors to store the paths
    vector<int> path1, path2;

    // Check if path to both the nodes does not exist
    if (!getPath(root, n1, path1) || !getPath(root, n2, path2))
    {
        return -1;
    }

    // Variable to store the path change
    int pc;

    // Loop over paths to get the pathChange (pc)
    for (pc = 0; pc < path1.size() && path2.size(); pc++)
    {
        // If the intersection found
        if (path1[pc] != path2[pc])
        {
            // Break the loop
            break;
        }
    }

    // Return the value at the intersection node
    return path1[pc - 1];
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** BINARY TREE *****\n\n";
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

    // Print the LCA
    cout
        << "The Lowest Common Ancestor of 7 and 6 is: "
        << getLCA(root, 7, 6) << "\n\n";
}