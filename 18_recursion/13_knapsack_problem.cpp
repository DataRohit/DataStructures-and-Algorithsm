#include <iostream>
using namespace std;

int knapsack(int value[], int weight[], int n, int capacity)
{
    // Base Case

    /*
     *  1. No items left
     *  2. No capacity left
     */
    if (n == 0 || capacity == 0)
    {
        return 0;
    }

    /*
     *  If the weight of next item exceeds the capacity
     *  then we cannot include it in the knapsack
     */
    if (weight[n - 1] > capacity)
    {
        return knapsack(value, weight, n - 1, capacity);
    }

    // Include the nth item

    /*
     *  1. Decrease the capacity by the weight of the nth item
     *  2. Increase the value by the value of the nth item
     */
    int included_value = knapsack(value, weight, n - 1, capacity - weight[n - 1]) + value[n - 1];

    // Exclude the nth item

    /*
     *  1. Capacity remains the same
     *  2. Value remains the same
     *  3. Decrease the number of items by 1
     */
    int excluded_value = knapsack(value, weight, n - 1, capacity);

    // Return the maximum value
    return max(included_value, excluded_value);
}

int main()
{
    // Title of the program
    cout
        << "***** 0-1 KNAPSACK PROBLEM *****"
        << endl
        << endl;

    // Number of items
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    // Value of each item
    int value[n];
    cout
        << endl
        << "Enter the value of each item: "
        << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Item " << i + 1 << ": ";
        cin >> value[i];
    }

    // Weight of each item
    int weight[n];
    cout
        << endl
        << "Enter the weight of each item: "
        << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Item " << i + 1 << ": ";
        cin >> weight[i];
    }

    // Capacity of the knapsack
    int capacity;
    cout
        << endl
        << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    // Maximum value that can be stored in the knapsack
    int max_value = knapsack(value, weight, n, capacity);

    // Display the maximum value
    cout
        << endl
        << "Maximum value that can be stored in the knapsack: " << max_value
        << endl;

    return 0;
} // main
