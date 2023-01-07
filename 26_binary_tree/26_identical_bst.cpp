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

// Function to check if two trees are identical
bool isIdentical(Node *root1, Node *root2)
{
    // If both the roots are null
    if (root1 == NULL && root2 == NULL)
    {
        // The trees are identical
        return true;
    }

    // If any one of the root is null
    if (root1 == NULL || root2 == NULL)
    {
        // The trees are not identical
        return false;
    }

    // Both the nodes are not null
    else
    {
        // Condition 1
        bool cond1 = root1->data == root2->data;

        // Condition 2
        bool cond2 = isIdentical(root1->left, root2->left);

        // Condition 3
        bool cond3 = isIdentical(root1->right, root2->right);

        // If all true return true
        return cond1 && cond2 && cond3;
    }
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** IDENTICAL BINARY TREES *****\n\n";
    printLine();

    // Tree 1
    Node *root1 = new Node(1);

    root1->right = new Node(3);

    root1->right->left = new Node(2);
    root1->right->right = new Node(5);

    // Tree 2
    Node *root2 = new Node(1);

    root2->right = new Node(3);

    root2->right->left = new Node(2);
    root2->right->right = new Node(5);

    /*
     * Tree 1 and Tree 2 Structure
     *
     *          1
     *           \
     *            3
     *           / \
     *          2   5
     *
     */

    // Tree 3
    Node *root3 = new Node(1);

    root3->right = new Node(3);

    root3->right->left = new Node(2);
    root3->right->right = new Node(8);

    /*
     * Tree 3 Structure
     *
     *          1
     *           \
     *            3
     *           / \
     *          2   8
     *
     */

    // Print the preorder of all 3 nodes
    cout << "Preorder Sequence of Trees are:\n\n";

    cout << "Tree 1 : ";
    printPreorder(root1);
    cout << "\n";

    cout << "Tree 2 : ";
    printPreorder(root2);
    cout << "\n";

    cout << "Tree 3 : ";
    printPreorder(root3);
    cout << "\n\n";

    // Compare and check the trees
    cout << "Results:\n\n";

    cout << "Tree 1 and Tree 2 : " << isIdentical(root1, root2) << "\n";
    cout << "Tree 2 and Tree 3 : " << isIdentical(root2, root3) << "\n";
    cout << "Tree 1 and Tree 3 : " << isIdentical(root1, root3) << "\n\n";
}