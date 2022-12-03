#include <iostream>
using namespace std;

// Declaring a class
class Student
{
    string name;

public:
    int age;
    bool gender;

    // Default Constructor

    /*
     *  Default constructor is a constructor which has no parameters.
     */
    Student()
    {
        cout
            << "Default Constructor Called"
            << endl;
    }

    // Parameterised Constructor
    Student(string s, int a, int g)
    {
        cout
            << "Parameterised Constructor Called"
            << endl;
        name = s;
        age = a;
        gender = g;
    }

    // Copy Constructor
    Student(Student &a)
    {
        cout
            << "Copy Constructor Called"
            << endl;
        name = a.name;
        age = a.age;
        gender = a.gender;
    }

    // Destructor

    /*
     *  Destructor is called with we exit our main function
     */
    ~Student()
    {
        cout
            << endl
            << "Destructor Called"
            << endl;
    }

    // Function to set the name
    void
    setName(string s)
    {
        name = s;
    }

    // Function to get the name
    void
    getName()
    {
        cout << name << endl;
    }

    // Function to print the data members
    void
    printData()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }

    // Operator Overloading

    /*
     *  Operator overloading is a way to overload the operators
     *  for our own classes.
     */
    bool
    operator==(Student &a)
    {
        if (name == a.name && age == a.age && gender == a.gender)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    // Title of the program
    cout
        << "***** CLASS CONSTRUCTOR *****"
        << endl
        << endl;

    // Creating an object of class Student
    Student s1("Rohit", 19, 0);

    // Get the data of student s1
    // s1.printData();

    // Creating an object of class Student
    cout << endl;
    Student s2("Ketki", 19, 1);

    // Copying data from s1 to s3
    cout << endl;
    Student s3 = s1;

    // Operator overloading

    /*
     *  Operator overloading is a technique in which
     *  we can overload the operators to perform
     *  operations on our own defined data types.
     */

    //    Check if s1 and s3 are equal
    cout << endl;
    if (s1 == s3)
    {
        cout << "Student 1 and 3 are Same" << endl;
    }
    else
    {
        cout << "Student 1 and 3 are Not Same" << endl;
    }

    //    Check if s1 and s2 are equal
    cout << endl;
    if (s1 == s2)
    {
        cout << "Student 1 and 2 are Same" << endl;
    }
    else
    {
        cout << "Student 1 and 2 are Not Same" << endl;
    }

    return 0;
} // main
