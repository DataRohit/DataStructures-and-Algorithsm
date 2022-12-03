#include <iostream>
using namespace std;

int main()
{
    cout
        << "***** SWITCH-CASE STATEMENTS *****"
        << endl
        << endl;

    char button;

    cout << "Input a character (a - e): ";
    cin >> button;

    switch (button)
    {
    case 'a':
        cout << "Hello! You pressed a" << endl;
        break;

    case 'b':
        cout << "Namaste! You pressed b" << endl;
        break;

    case 'c':
        cout << "Salute! You pressed c" << endl;
        break;

    case 'd':
        cout << "Hola! You pressed d" << endl;
        break;

    case 'e':
        cout << "Ciao! You pressed e" << endl;
        break;

    default:
        cout << "You pressed something else!" << endl;
        break;
    }

    return 0;
} // main
