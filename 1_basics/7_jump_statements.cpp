#include <iostream>
using namespace std;

int main()
{
    cout
        << "***** JUMP STATEMENTS *****"
        << endl
        << endl;

    int pocketMoney = 3000;

    for (int date = 0; date <= 28; date++)
    {
        // If date is even number, skip the rest of the loop
        if (date % 2 == 0)

            continue;

        // If date is odd the person can go out
        cout
            << "Go Out Today! :\t"
            << "Date: " << date << "\n";

        // Every time the person goes out he/she uses 300
        pocketMoney -= 300;

        // Print the remaining money
        cout << "Remaining Money: " << pocketMoney << "\n\n";

        // If pocketMoney is less than 500, break the loop
        if (pocketMoney < 500)
        {
            // Print the message and break the loop
            cout
                << "Pocket Money is less than 500, "
                << "I can't go out anymore :("
                << "\n";

            break;
        }
    }

    return 0;
} // main
