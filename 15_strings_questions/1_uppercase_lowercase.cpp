#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
 * NOTES:
 *  1. Smaller case character have larger ASCII value than the corresponding
 *      upper case character.
 *  2. To convert a character to upper case, subtract 32 from its ASCII value.
 *  3. To convert a character to lower case, add 32 to its ASCII value.
 *
 *  4. Alternate method is to use toupper() and tolower() functions.
 */

int main()
{
    // Title of the program
    cout
        << "***** UPPERCASE AND LOWERCASE *****"
        << endl
        << endl;

    // Declare string variable
    string str;

    // Input string
    cout << "Enter a string: ";
    getline(cin, str);
    cout << endl;

    /*
     *  // Variables to store the uppcase and lowercase string
     *  string strUpper = "", strLower = "";
     */

    /*
     *  // Convert string to uppercase and lowercase
     *  for (int i = 0; i < str.length(); i++)
     *  {
     *      strUpper += toupper(str[i]);
     *      strLower += tolower(str[i]);
     *  }
     */

    // Output uppercase and lowercase string
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout << "Uppercase string: " << str << endl;

    transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout << "Lowercaes string: " << str << endl;

    return 0;
}
