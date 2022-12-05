
#include <iostream>
#include <deque>
using namespace std;

// Function to print a seperator line
void printLine()
{
    cout << "--------------------------------------------\n\n";
}

// Default function
int main()
{
    // Title of the program
    printLine();
    cout << "***** DEQUE BASICS *****\n\n";
    printLine();

    // Initialize our deque
    deque<int> dq;

    // Var to store the data
    int data;

    // Loop till user exits
    while (1)
    {
        // Declare all the operations
        cout << "1. Push Front Operation\n";
        cout << "2. Push Back Operation\n";
        cout << "3. Pop Front Operation\n";
        cout << "4. Pop Back Operation\n";
        cout << "5. Display Dequeue\n";
        cout << "6. Check Empty\n";
        cout << "0. Exit\n";

        // Get the choice from user
        int choice;
        cout << "\nEnter your choice: ";
        cin >> choice;

        // Switch case for different operations
        switch (choice)
        {
        case 1:
            // Get the data from user
            cout << "\nEnter the data: ";
            cin >> data;

            // Add data to deque at front
            dq.push_front(data);

            // Print the message
            cout << "\nData Pushed Successfully!\n\n";

            // Add line break
            printLine();

            break;

        case 2:
            // Get the data from user
            cout << "\nEnter the data: ";
            cin >> data;

            // Add data to deque at back
            dq.push_back(data);

            // Print the message
            cout << "\nData Pushed Successfully!\n\n";

            // Add line break
            printLine();

            break;

        case 3:
            // Check if deque is empty
            if (dq.empty())
            {
                cout << "\nQUEUE IS EMPTY!\n\n";
            }
            else
            {
                // Remove data from front
                dq.pop_front();

                // Print the message
                cout << "\nData Poped Successfully!\n\n";

                // Add line break
                printLine();
            }

            break;

        case 4:
            // Check if deque is empty
            if (dq.empty())
            {
                cout << "\nQUEUE IS EMPTY!\n\n";
            }
            else
            {
                // Remove data from back
                dq.pop_back();

                // Print the message
                cout << "\nData Poped Successfully!\n\n";

                // Add line break
                printLine();
            }

            break;

        case 5:
            // Check if deque is empty
            if (dq.empty())
            {
                cout << "\nQUEUE IS EMPTY!\n\n";
            }
            else
            {
                // Print the message
                cout << "\nThe elements in DEQUE are:\n";

                // Display the deque
                for (auto i : dq)
                {
                    cout << i << " ";
                }

                // Add line break
                cout << "\n\n";
            }

            // Add line break
            printLine();

            break;

        case 6:
            // Check if deque is empty
            if (dq.empty())
            {
                cout << "\nQUEUE IS EMPTY!\n\n";
            }
            else
            {
                cout << "\nQUEUE IS NOT EMPTY\n\n";
            }

            // Add line break
            printLine();

            break;

        case 0:
            // Print the message
            cout << "\nExiting the program...\n";

            // Exit the program
            exit(0);

        default:
            // Print the message
            cout << "\nInvalid choice!\n\n";

            // Add line break
            printLine();
        }
    }
}