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

// Function for zigzag traversal
void zigzagTraversal(Node *root)
{
    // Base Condition
    if (root == NULL)
    {
        return;
    }

    // Initalize stacks to store the current and next level
    stack<Node *> currLevel, nextLevel;

    // Var to keep track of direction of traversal
    bool leftToRight = true;

    // Pushing the root node of tree to current level
    currLevel.push(root);

    // Loop till current level is not empty
    while (!currLevel.empty())
    {
        // Save the top element from the currLevel stack
        Node *temp = currLevel.top();

        // Pop the stack
        currLevel.pop();

        // If temp exist
        if (temp)
        {
            // Print the data of temp
            cout << temp->data << " ";

            // Check the direction
            if (leftToRight)
            {
                // Add the left child to nextLevel stack
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }

                // Add the right child to nextLevel stack
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
            }
            else
            {
                // Add the right child to nextLevel stack
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }

                // Add the left child to nextLevel stack
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
            }
        }

        // Update the value of direction variable
        if (currLevel.empty())
        {
            // Update the direction variable by opposite value
            leftToRight = !leftToRight;

            // Swap our stacks
            swap(currLevel, nextLevel);
        }
    }
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** ZIGZAG TRAVERSAL BINARY SEARCH TREE *****\n\n";
    printLine();

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

    Node *root = new Node(3);

    root->left = new Node(2);
    root->right = new Node(7);

    root->left->left = new Node(1);

    root->right->left = new Node(5);
    root->right->right = new Node(8);

    root->right->left->left = new Node(4);
    root->right->left->right = new Node(6);

    // Print the binary tree
    cout << "The Stored Binary Tree is:\n\n";
    printTree(root, 0);
    cout << "\n\n";

    // Print the zigzag traversal
    cout << "The ZigZag Traversal of the Tree is:\n";
    zigzagTraversal(root);
    cout << "\n\n";
}