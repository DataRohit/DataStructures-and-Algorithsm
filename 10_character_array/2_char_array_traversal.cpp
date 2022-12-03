#include <iostream>
using namespace std;

int main()
{
    // Title for the program
    cout
        << "***** CHARACTER ARRAY TRAVERSAL *****"
        << endl
        << endl;

    // Initializing a character array
    char fruit[10] = "mango";

    // Traversing the array
    int i = 0;

    // get all the elements till the null character
    while (fruit[i] != '\0')
    {
        // Output each element of the array
        cout << fruit[i] << endl;
        i++;
    }

    return 0;
}
