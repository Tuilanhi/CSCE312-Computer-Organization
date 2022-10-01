#include <iostream>
#include <stdlib.h>

using namespace std;

// Deciaml to Binary conversion
void DecimalToBinary(int n)
{

    int binaryNumber[100], num = n;
    int i = 0;

    // Logic
    while (n > 0)
    {
        binaryNumber[i] = n % 2;
        n = n / 2;
        i++;
    }

    cout << "Binary value is ";
    // print value
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNumber[j];
    cout << endl;
}

// Decimal to hEX conversion
void DecimalToHex(int n)
{
    char hex[100];
    int i = 0;
    // logic conversion
    while (n != 0)
    {
        int temp = 0;
        temp = n % 16;
        if (temp < 10)
        {
            hex[i] = temp + 48;
            i++;
        }
        else
        {
            hex[i] = temp + 55;
            i++;
        }
        n = n / 16;
    }
    // print value
    cout << "Hexadecimal value ";
    for (int j = i - 1; j >= 0; j--)
        cout << hex[j];

    cout << endl;
}

int main(int argc, char *argv[])
{
    char opt1;
    char opt2;
    char *number;

    int opt;

    // Argument Count
    if (argc < 4 && argc > 4)
    {
        cout << "Required Exact 3 argument ";
    }

    opt1 = *argv[1];
    opt2 = *argv[2];

    // String to NUmber
    int number2 = atoi(argv[3]);

    if (opt1 == 'b')
    {
        DecimalToBinary(number2);
    }
    else
    {
        DecimalToHex(number2);
    }

    if (opt2 == 'h')
    {
        DecimalToHex(number2);
    }
    else
    {
        DecimalToBinary(number2);
    }

    return 0;
}