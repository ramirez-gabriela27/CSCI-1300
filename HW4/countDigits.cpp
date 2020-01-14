// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 4 - Problem # 5

#include <iostream>
using namespace std;

/*
    Determine the number of digits in an input number
    @param num (int) - input number as an integer
    @return digits (int) - number of digits as integer
*/
int countDigits (int num)
{
    int digits = 0;

    if (num < 0)
    {
        num = num * (-1);
    }
    if (num >= 0 && num < 10)
    {
        digits = 1;
        return digits;
    }
    else
        if (num >= 10 && num < 100)
        {
            digits = 2;
            return digits;
        }
    else
        if (num >= 100 && num < 1000)
        {
            digits = 3;
            return digits;
        }
    else
        if (num >= 1000 && num < 10000)
        {
            digits = 4;
            return digits;
        }
    else
    {
        return 0;
    }
}

main()
{
    // initialize num and digits as integers
    int num, digits;
    cout << "Please input a number: " << endl;
    //set num to user input
    cin >> num;
    //call function to set digits
    digits = countDigits(num);
    if(digits == 0)
    {
        cout << "Entered number has more than 4 digits" << endl;
    }
    else
    {
        cout << "The number " << num << " has " << digits << " digits." << endl;
    }

    cout << endl;

    cout << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // digits: 3
    digits = countDigits(210);
    cout << "The number 210 has " << digits << " digits." << endl;


    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // digits: 2
    digits = countDigits(-14);
    cout << "The number -14 has " << digits << " digits." << endl;

    return 0;
}
