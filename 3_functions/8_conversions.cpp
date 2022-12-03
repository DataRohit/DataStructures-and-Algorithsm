#include <iostream>
#include <math.h>
using namespace std;

// Function to convert binary to decimal
void binary_to_decimal()
{
    int num;

    cout << "Enter the binary number: ";
    cin >> num;

    int power = 0, decimal = 0;

    while (num > 0)
    {
        int rem = num % 10;
        decimal += rem * pow(2, power);
        num = num / 10;
        power++;
    }

    cout << "Decimal number is: " << decimal << endl;

    return;
}

// Function to convert octal to decimal
void octal_to_decimal()
{
    int num;

    cout << "Enter the octal number: ";
    cin >> num;

    int power = 0, decimal = 0;

    while (num > 0)
    {
        int rem = num % 10;
        decimal += rem * pow(8, power);
        num = num / 10;
        power++;
    }

    cout << "Decimal number is: " << decimal << endl;

    return;
}

// Function to convert hexadecimal to decimal
void hex_to_decimal()
{
    string num;

    cout << "Enter the hexadecimal number: ";
    cin >> num;

    int len = num.length();

    int power = 0, decimal = 0;

    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] >= '0' && num[i] <= '9')
        {
            decimal += (num[i] - 48) * pow(16, power++);
        }
        else if (num[i] >= 'A' && num[i] <= 'F')
        {
            decimal += (num[i] - 55) * pow(16, power++);
        }
    }

    cout << "Decimal number is: " << decimal << endl;

    return;
}

// Function to convert decimal to binary
void decimal_to_binary()
{
    int num;

    cout << "Enter the decimal number: ";
    cin >> num;

    int power = 1, binary = 0;

    while (num > 0)
    {
        int rem = num % 2;
        binary += rem * power;
        power *= 10;
        num = num / 2;
    }

    cout << "Binary number is: " << binary << endl;

    return;
}

// Function to convert decimal to octal
void decimal_to_octal()
{
    int num;

    cout << "Enter the decimal number: ";
    cin >> num;

    int power = 1, octal = 0;

    while (num > 0)
    {
        int rem = num % 8;
        octal += rem * power;
        power *= 10;
        num = num / 8;
    }

    cout << "Octal number is: " << octal << endl;

    return;
}

// Function to convert decimal to hexadecimal
void decimal_to_hex()
{
    int num;

    cout << "Enter the decimal number: ";
    cin >> num;

    string hex = "";

    int i = 0;

    while (num != 0)
    {
        int rem = num % 16;

        if (rem < 10)
        {
            hex += rem + 48;
        }
        else
        {
            hex += rem + 55;
        }

        i++;
        num = num / 16;
    }

    for (int j = i - 1; j >= 0; j--)
        cout << hex[j];
}

int main()
{
    cout
        << "***** FUNCTIONS - CONVERSIONS *****" << endl
        << endl;

    cout << "a. Binary to Decimal" << endl;
    cout << "b. Octal to Decimal" << endl;
    cout << "c. Hexadecimal to Decimal" << endl;
    cout << "d. Decimal to Binary" << endl;
    cout << "e. Decimal to Octal" << endl;
    cout
        << "f. Decimal to Hexadecimal" << endl
        << endl;

    char choice;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 'a':
        binary_to_decimal();
        break;

    case 'b':
        octal_to_decimal();
        break;

    case 'c':
        hex_to_decimal();
        break;

    case 'd':
        decimal_to_binary();
        break;

    case 'e':
        decimal_to_octal();
        break;

    case 'f':
        decimal_to_hex();
        break;

    default:
        cout << "Invalid choice" << endl;
        break;
    }

    return 0;
} // main
