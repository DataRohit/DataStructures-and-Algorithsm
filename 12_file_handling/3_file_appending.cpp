#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Title for the program
    cout
        << "***** FILE HANDLING - APPENDING *****"
        << endl
        << endl;

    // Declaring variables
    char sentence[100];

    // Accept input from user
    cout << "Enter a sentence to append: ";
    cin.getline(sentence, 100);

    // Initialinzg file object
    ofstream myfile_a;

    // Opening the file for manipulation in append mode
    myfile_a.open("text_file.txt", ios::app);

    // Writing to a file
    myfile_a << sentence;

    // Closing the file
    myfile_a.close();

    // Message for the user
    cout
        << endl
        << "File appended successfully." << endl;

    return 0;
} // main
