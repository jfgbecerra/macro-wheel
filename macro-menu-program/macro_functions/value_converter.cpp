// Driver script to call your functions that you want to run for macros this is a call for a python script 
// You can make calls for other languages like this. 

#pragma once
#include <iostream>
#include <cstdlib>
#include <unordered_map> 
#include <string>
#include "value_converter.h" 

using namespace std;

void createMap(unordered_map<string, char> *um)
{
    (*um)["0000"] = '0';
    (*um)["0001"] = '1';
    (*um)["0010"] = '2';
    (*um)["0011"] = '3';
    (*um)["0100"] = '4';
    (*um)["0101"] = '5';
    (*um)["0110"] = '6';
    (*um)["0111"] = '7';
    (*um)["1000"] = '8';
    (*um)["1001"] = '9';
    (*um)["1010"] = 'A';
    (*um)["1011"] = 'B';
    (*um)["1100"] = 'C';
    (*um)["1101"] = 'D';
    (*um)["1110"] = 'E';
    (*um)["1111"] = 'F';
}

// function to convert 
// Hexadecimal to Binary Number 
void HexToBin(string hexdec)
{
    long int i = 0;

    while (hexdec[i]) {

        switch (hexdec[i]) {
        case '0':
            cout << "0000";
            break;
        case '1':
            cout << "0001";
            break;
        case '2':
            cout << "0010";
            break;
        case '3':
            cout << "0011";
            break;
        case '4':
            cout << "0100";
            break;
        case '5':
            cout << "0101";
            break;
        case '6':
            cout << "0110";
            break;
        case '7':
            cout << "0111";
            break;
        case '8':
            cout << "1000";
            break;
        case '9':
            cout << "1001";
            break;
        case 'A':
        case 'a':
            cout << "1010";
            break;
        case 'B':
        case 'b':
            cout << "1011";
            break;
        case 'C':
        case 'c':
            cout << "1100";
            break;
        case 'D':
        case 'd':
            cout << "1101";
            break;
        case 'E':
        case 'e':
            cout << "1110";
            break;
        case 'F':
        case 'f':
            cout << "1111";
            break;
        default:
            cout << "\nInvalid hexadecimal digit "
                << hexdec[i];
        }
        i++;
    }
}

void value_converter() 
{
    string choice;
    int i;
    string bin;
    char buffer[33];

    cout << "1: Convert Decimal to Decimal." << endl;
    cout << "2: Convert Decimal to Binary." << endl;
    cout << "3: Convert Decimal to Hex." << endl;
    cout << "4: Convert Binary to Binary." << endl;
    cout << "5: Convert Binary to Decimal." << endl;
    cout << "6: Convert Binary to Hex." << endl;
    cout << "7: Convert Hex to Hex." << endl;
    cout << "8: Convert Hex to Binary." << endl;
    cout << "9: Convert Hex to Decimal." << endl;
    cout << "Please enter the number: ";
    cin >> choice;
    fflush(stdin);


    if(choice == "1") {
        cout << "Uh you alright?" << endl;
    }
    else if(choice == "2") {
        cout << "Enter the integer: ";
        cin >> i;
        _itoa_s(i, buffer, 2);
        cout << "Hex value is: " << buffer << endl;
    }
    else if (choice == "3") {
        cout << "Enter the integer: ";
        cin >> i;
        _itoa_s(i, buffer, 16);
        cout << "Hex value is: " << buffer << endl;
    }
    else if (choice == "4") {
        cout << "Uh you alright?" << endl;
    }
    else if (choice == "5") {
        cout << "Enter the binary number: ";
        cin >> i;
        int num = i;
        int dec_value = 0;

        // Initializing base value to 1, i.e 2^0 
        int base = 1;

        int temp = num;
        while (temp) {
            int last_digit = temp % 10;
            temp = temp / 10;

            dec_value += last_digit * base;

            base = base * 2;
        }

        cout << "Decimal value is: " << dec_value << endl;
    }
    else if (choice == "6") {
        cout << "Enter the binary number: ";
        cin >> bin;
        int l = bin.size();
        int t = bin.find_first_of('.');

        // length of string before '.' 
        int len_left = t != -1 ? t : l;

        // add min 0's in the beginning to make 
        // left substring length divisible by 4  
        for (int i = 1; i <= (4 - len_left % 4) % 4; i++)
            bin = '0' + bin;

        // if decimal point exists     
        if (t != -1)
        {
            // length of string after '.' 
            int len_right = l - len_left - 1;

            // add min 0's in the end to make right 
            // substring length divisible by 4  
            for (int i = 1; i <= (4 - len_right % 4) % 4; i++)
                bin = bin + '0';
        }

        // create map between binary and its 
        // equivalent hex code 
        unordered_map<string, char> bin_hex_map;
        createMap(&bin_hex_map);

        int i = 0;
        string hex = "";

        while (1)
        {
            // one by one extract from left, substring 
            // of size 4 and add its hex code 
            hex += bin_hex_map[bin.substr(i, 4)];
            i += 4;
            if (i == bin.size())
                break;

            // if '.' is encountered add it 
            // to result 
            if (bin.at(i) == '.')
            {
                hex += '.';
                i++;
            }
        }

        cout << "Hex value is: " << hex << endl;
    }
    else if (choice == "7") {
        cout << "Uh you alright?" << endl;
    }
    else if (choice == "8") {
        // Convert HexaDecimal to Binary
        cout << "Enter the hex number: ";
        cin >> bin;

        cout << "Binary value is: ";
        HexToBin(bin);
    }
    else if (choice == "9") {
        // Hex to binary
        cout << "Enter the binary number: ";
        cin >> bin;


        int len = bin.size();

        // Initializing base value to 1, i.e 16^0 
        int base = 1;

        int dec_val = 0;

        // Extracting characters as digits from last character 
        for (int i = len - 1; i >= 0; i--)
        {
            // if character lies in '0'-'9', converting  
            // it to integral 0-9 by subtracting 48 from 
            // ASCII value. 
            if (bin[i] >= '0' && bin[i] <= '9')
            {
                dec_val += (bin[i] - 48) * base;

                // incrementing base by power 
                base = base * 16;
            }

            // if character lies in 'A'-'F' , converting  
            // it to integral 10 - 15 by subtracting 55  
            // from ASCII value 
            else if (bin[i] >= 'A' && bin[i] <= 'F')
            {
                dec_val += (bin[i] - 55) * base;

                // incrementing base by power 
                base = base * 16;
            }
        }

        cout << "Decimal value is: " << dec_val << endl;
    }
}