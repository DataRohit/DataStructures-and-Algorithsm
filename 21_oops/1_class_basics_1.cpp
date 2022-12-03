#include <iostream>
using namespace std;

// Initializing a class

/*
 *  name, age, gender -> Data Members
 *
 *  By default the data members are private
 *
 *  public -> Access Specifier
 *
 *  If data memeber specified before public keyword
 *  then it will be private by default
 */
class Students
{
public:
    string name;
    int age;
    bool gender;

    // Function to print the data members
    void
    printData()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }
};

int main()
{
    // Title of the program
    cout
        << "***** OOPS - CLASS BASICS *****"
        << endl
        << endl;

    // Ask for number of students
    int n;
    cout << "Enter number of students (<=5): ";
    cin >> n;

    /*
     *  Instead of adding the data members one by one
     *  We can create an array of objects
     */
    Students studentsArr[n];

    // Take input from user
    cout
        << endl
        << endl
        << "Enter details of students:"
        << endl;
    for (int i = 0; i < n; i++)
    {
        cout
            << endl
            << "Student " << i + 1
            << endl;

        cout << "Name :";
        cin >> studentsArr[i].name;

        cout << "Age :";
        cin >> studentsArr[i].age;

        cout << "Gender :";
        cin >> studentsArr[i].gender;
    }

    cout
        << endl
        << endl
        << "Display details of students:"
        << endl;
    for (int i = 0; i < n; i++)
    {
        cout
            << endl
            << "Student " << i + 1
            << endl;

        // Call the printData function from class
        studentsArr[i].printData();
    }

    return 0;
} // main
