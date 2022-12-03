#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    // Title of the program
    cout
        << "***** MOST FREQUENT CHARACTER *****"
        << endl
        << endl;

    // Declare string variable
    string str;

    // Input string
    cout << "Enter a string: ";
    getline(cin, str);
    cout << endl;

    // Sort the string
    sort(str.begin(), str.end());

    // Output sorted string
    cout << "Sorted string: " << str << endl;
    cout << endl;

    // Declare variables
    int currCount = 1, maxCount = 0;
    char currChar = str[0], maxChar = str[0];

    // Find the most frequent character
    for (int i = 1; i < str.length(); i++)
    {
        // If the current character is same as the previous character
        if (str[i] == str[i - 1])
        {
            // Increment the current count
            currCount++;
        }
        else
        {
            // If the current count is greater than the maximum count
            if (currCount > maxCount)
            {
                // Update the maximum count and character
                maxCount = currCount;
                maxChar = currChar;
            }

            // Reset the current count and character
            currCount = 1;
            currChar = str[i];
        }
    }

    // Output the most frequent character
    cout << "Most frequent character: " << maxChar << endl;
    cout << "Frequency: " << maxCount << endl;

    return 0;
} // main
