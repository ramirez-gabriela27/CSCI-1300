// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 4 - Problem # Extra Credit

#include <iostream>
#include <string>
using namespace std;

/*
    Take an input number and set it to its Roman Numeral equivalent
    @param num (int) - input number as an integer
    @return N/A
*/
void integerToRoman (int num)
{
    /*    roman digit     integer value
            I               1
            V               5
            X               10
            L               50
            C               100
            D               500
            M               1000
    */
    string roman;

    while (num>=1000)
    {
        num -= 1000;
        roman = roman + "M";
    }
    while (num>=500)
    {
        if (num<900)
        {
            num -= 500;
            roman = roman + "D";
        }
        else
        {
            num -= 900;
            roman = roman+"CM";
        }
    }
    while (num>=100)
    {
        if (num<400)
        {
            num -= 100;
            roman = roman+"C";
        }
        else
        {
            num -= 400;
            roman = roman+"CD";
        }
    }
    while (num >=50)
    {
        if(num<90)
        {
            num -= 50;
            roman = roman+"L";
        }
        else
        {
            num -=90;
            roman = roman+"XC";
        }
    }
    while (num>=10)
    {
        if (num<40)
        {
            num -= 10;
            roman = roman+"X";
        }
        else
        {
            num -= 40;
            roman = roman+"XL";
        }
    }
    while (num >=5)
    {
        if(num<9)
        {
            num -= 5;
            roman = roman+"V";
        }
        else
        {
            num -=9;
            roman = roman+"IX";
        }
    }
    while (num>=1)
    {
        if (num<4)
        {
            num -= 1;
            roman = roman+"I";
        }
        else
        {
            num -= 4;
            roman = roman+"IV";
        }
    }

    cout << roman << endl;
}

int main()
 {
    //initialize num and set it to user input
    int num;
    cout << "Please enter an integer: " << endl;
    cin >> num;
    if (num>=4000 || num<=0)
    {
        cout <<"Invalid Integer" <<endl;

    }
    else
    {
    //call function
    integerToRoman(num);
    }

    cout << endl;

    cout << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    //IX
    cout << "The number 9 is: ";
    integerToRoman(9);

    cout << endl;

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // MMMCMXCIX
    cout << "The number 3999 is: ";
    integerToRoman(3999);

    return 0;
}
