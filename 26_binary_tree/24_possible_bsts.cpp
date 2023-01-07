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

// Function to print the preorder
void printPreorder(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    // Print the node data
    cout << root->data << " ";

    // Go to left sub tree
    printPreorder(root->left);

    // Go to right sub tree
    printPreorder(root->right);
}

// Function to get all possible BST's
vector<Node *> constructTrees(int start, int end)
{
    // Array to store the different trees
    vector<Node *> trees;

    // Base Case
    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }

    // Looping
    for (int i = start; i <= end; i++)
    {
        // Generating the left and right sub tree
        vector<Node *> leftSubtrees = constructTrees(start, i - 1);
        vector<Node *> rightSubtrees = constructTrees(i + 1, end);

        // Combining the left sub trees to right sub trees
        for (int j = 0; j < leftSubtrees.size(); j++)
        {
            // Store the node from left
            Node *left = leftSubtrees[j];

            for (int k = 0; k < rightSubtrees.size(); k++)
            {
                // Store the node from right
                Node *right = rightSubtrees[k];

                // New Node
                Node *node = new Node(i);

                // Create the tree
                node->left = left;
                node->right = right;

                // Add the tree to the array
                trees.push_back(node);
            }
        }
    }

    // Return the array
    return trees;
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** POSSIBLE BINARY TREES *****\n\n";
    printLine();

    // Getting the trees for values 1 to 3
    vector<Node *> totalTrees = constructTrees(1, 3);

    // Output title
    cout << "All Possible Binary Trees for Values 1 to 3 are:\n\n";

    // Print the preorder sequence of all the trees
    for (int i = 0; i < totalTrees.size(); i++)
    {
        cout << (i + 1) << " : ";
        printPreorder(totalTrees[i]);
        cout << "\n";
    }

    // Line breaks
    cout << "\n";
}