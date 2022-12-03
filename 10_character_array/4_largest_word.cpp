#include <iostream>
using namespace std;

// NOTE: cin.ignore() is used to ignore or clear characters from input buffer.
// NOTE: cin.getline() is used to take input of sentence with spaces.

int main()
{
    // Title for the program
    cout
        << "***** LARGEST WORD IN SENTENCE *****"
        << endl
        << endl;

    // Take user input for the lenght of character array
    int n;
    cout << "Enter the length of the sentence: ";
    cin >> n;
    cin.ignore();

    // Initializing a character array
    char arr[n + 1];

    // Take user input for the array
    cout
        << endl
        << "Enter the sentence: ";
    cin.getline(arr, n);
    cin.ignore();

    // Variables
    int i = 0;
    int currLen = 0, maxLen = 0;
    int currSt = 0, maxSt = 0;

    while (true)
    {
        // If the current character is a space or null character
        if (arr[i] == ' ' || arr[i] == '\0')
        {
            // If the current word is larger than the previous largest word
            if (currLen > maxLen)
            {
                // Update largest word length and starting index
                maxLen = currLen;
                maxSt = currSt;
            }

            // Reset current word length and starting index
            currLen = 0;
            currSt = i + 1;
        }
        // If the current character is not a space or null character
        else
        {
            // Increment currLen
            currLen++;
        }

        // Break the loop if we encounter the null character
        if (arr[i] == '\0')
            break;

        // Increment i
        i++;
    }

    // Output the lenght of longest word
    cout
        << endl
        << "Lenght of the largest word in sentence is: "
        << maxLen
        << endl
        << endl;

    // Output the longest word
    cout << "Longest word: ";
    for (int i = 0; i < maxLen; i++)
    {
        cout << arr[i + maxSt];
    }

    return 0;
} // main
