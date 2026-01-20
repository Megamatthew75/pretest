// PreTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    
    cout << "DECIMAL          BINARY          HEXADECIMAL          BCD     " << "\n"; //set banner
    int maxNum = 256;
    for (int i = 0; i < maxNum; i++) {
        
        //Binary
        cout << left << setfill(' ') << setw(17) << i << right; // setup the "whitespace" and alignment properly.
        int n = i;
        string binStr = "";
        while (n > 0) { //binary expression formula, find the binary representation with the remainders
            int remainder = n % 2;
            n = n / 2;
            binStr = to_string(remainder) + binStr;
        }
        while (binStr.length() < 8) { //adds the missing zeroes to express in 8 bits
            binStr = "0" + binStr;
        }
        binStr = binStr.insert(4, " "); //insert space between nibs
        cout << binStr;
        
        //Hexadecimal
        n = i;
        string hexStr = "";
        char tempChar = ' ';
        while (n > 0) { //like the binary expression formula, but for base 16.
            int remainder = n % 16;
            n = n / 16;
            if (remainder >= 10) {
                tempChar = remainder - 10 + 'A'; //because we're using characters this should iterate thru A to F based on Char value.
            }
            else {
                tempChar = remainder + '0'; //convert int to char with char addition
            }
            hexStr = tempChar + hexStr; //get the full hexadecimal string
        }
        while (hexStr.length() < 2) {
            hexStr = "0" + hexStr;
        }
        cout << setfill(' ') << setw(13) << hexStr;

        //BCD
        n = i;
        string nibStr = "";
        string bcdStr = "";
        
        while (n > 0) { //get the digit in each position of the number
            nibStr = "";
            int digit = n % 10;
            n = n / 10;
            while (digit > 0) { //get the binary expression for each digit
                int remainder = digit % 2;
                digit = digit / 2;
                nibStr = to_string(remainder) + nibStr;
            }
            while (nibStr.length() < 4) { //make the nib expressed in 4 bits
                nibStr = "0" + nibStr;
            }
            bcdStr = nibStr + bcdStr; //add the nibs together
        }
        while (bcdStr.length() < 12) { //if not enough nibs for a 3 nib expression, this adds the remaining zeroes
            bcdStr = "0" + bcdStr;
        }
        bcdStr = bcdStr.insert(8, " "); //make the spaces in between each nib
        bcdStr = bcdStr.insert(4, " "); //contd
        cout << setw(23) << bcdStr;
        
        cout << "\n";
    
        
    
    
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
