#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string bin, temp, ones, twos;
    int len, carry = 1;
    cout << "\n\t\t\t\t***** 1's and 2's COMPLEMENT *****\n\n";
    cout << "Enter the valid binary number: ";
    cin >> bin;
    len = bin.length();
    
    int count = 0;
    while (count < len)
    {
        if (bin[count] != '1' && bin[count] != '0')
        {
            cout << "Invalid binary number" << endl;
            main();
        }
        count++;
    }
    
    // 1's complement
    for (int i = 0; i < len; i++)
    {
        if (bin[i] == '1')
        {
            bin[i] = '0';
        }
        else if (bin[i] == '0' && carry == 1)
        {
            bin[i] = '1';
        }
    }
    
    ones = bin;
    temp = ones;
    bin = temp;
    
    // 2's complement;
    for (int i = len; i >= 0; i--)
    {
        if (bin[i] == '1' && carry == 1)
        {
            bin[i] = '0';
        }
        else if (bin[i] == '0' && carry == 1)
        {
            bin[i] = '1';
            carry = 0;
        }
    }
    
    twos = bin;
    
    cout << "The 1's complement of the entered number is: " << ones << endl;
    cout << "The 2's complement of the entered number is: " << twos << endl;
    
    return 0;
}