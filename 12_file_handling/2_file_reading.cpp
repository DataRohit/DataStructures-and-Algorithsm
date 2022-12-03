#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Title for the program
    cout
        << "***** FILE HANDLING - READING *****"
        << endl
        << endl;

    // Declaring variables
    char sentence[100];

    // Initialinzg file object
    ifstream myfile_r;

    // Opening the file for manipulation
    myfile_r.open("text_file.txt");

    // Reading from file
    myfile_r.getline(sentence, 100);

    // Closing the file
    myfile_r.close();

    // Display the content in the text file
    cout
        << "The content of the file is: " << endl
        << sentence << endl;

    return 0;
}
