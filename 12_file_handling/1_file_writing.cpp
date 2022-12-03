#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Title for the program
    cout
        << "***** FILE HANDLING - WRITING *****"
        << endl
        << endl;

    // Declaring variables
    char sentence[100];

    // Accept input from user
    cout << "Enter a sentence: ";
    cin.getline(sentence, 100);

    // Initialinzg file object
    ofstream myfile_w;

    // Opening the file for manipulation
    myfile_w.open("text_file.txt");

    // Writing to a file
    myfile_w << sentence;

    // Closing the file
    myfile_w.close();

    // Message for the user
    cout
        << endl
        << "File created successfully. File write operation completed successfully." << endl;

    return 0;
} // main
