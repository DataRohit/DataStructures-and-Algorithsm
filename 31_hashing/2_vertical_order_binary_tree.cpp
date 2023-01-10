#include <bits/stdc++.h>
using namespace std;

// Defining short forms
#define ll long long

#define pii pair<int, int>
#define mk make_pair
#define ff first
#define ss second

#define vi vector<int>
#define pb push_back
#define pf pop_front

#define imax INT_MAX
#define imin INT_MIN

#define mii map<int, int>
#define umii unordered_map<int, int>

#define f(i, s, e) for (int i = s; i < e; i++)
#define cf(i, s, e) for (int i = s; i <= e; i++)

#define rf(i, s, e) for (int i = e - 1; i >= s; i--)

// Function to print a seperator line
void printLine() { cout << "--------------------------------------------\n\n"; }

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

// Function to get the vertical order of tree
void getVerticalOrder(Node *root, int hdis, map<int, vi> &m)
{
    // Base Case
    if (root == NULL)
        return;

    // Push the data at the key (distance)
    m[hdis].push_back(root->data);

    // Traverse the left and right sub tree
    getVerticalOrder(root->left, hdis - 1, m);
    getVerticalOrder(root->right, hdis + 1, m);
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** VERTICAL ORDER TRAVERSAL *****\n\n";
    printLine();

    // Create a root node pointer
    struct Node *root = new Node(10);

    // Add other nodes to the tree
    root->left = new Node(7);
    root->right = new Node(4);

    root->left->left = new Node(3);
    root->left->right = new Node(11);

    root->right->left = new Node(14);
    root->right->right = new Node(6);

    /*
     * Current Tree Structure
     *
     *         10
     *       /    \
     *      7      4
     *     / \    / \
     *    3  11  14  6
     *
     */

    // Print the binary tree
    cout << "The Stored Binary Tree is:\n\n";
    printTree(root, 0);
    cout << "\n\n";

    // Create a map to store the distance as index and element
    map<int, vi> m;

    // Initialize the horizontal distance by 0
    int hdis = 0;

    // Call the function to print the vertical order
    getVerticalOrder(root, hdis, m);

    // Line break
    cout << "\n";

    // Iterate over each index
    cout << "Vertical Order Traversal is:\n";
    for (auto i : m)
    {
        // Iterate over available elements for each index
        for (auto j : i.ss)
        {
            // Print the elements
            cout << j << " ";
        }
    }

    // Line break
    cout << "\n\n";
}
