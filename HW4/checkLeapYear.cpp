// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 4 - Problem # 7

#include <iostream>
using namespace std;

/*
    Determine if the input year is a leap year
    @param year(int) - input year
    @return true/false
*/
bool checkLeapYear(int year)
{
    if (year%4 == 0)
    {
        if (year%100 == 0 && year >= 1582)
        {
            if (year%400 == 0 && year >= 1582)
            {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

main()
{
    //initialize year and set it to the user input
    int year;
    cout << "Please input a year: " << endl;
    cin >> year;
    //initialize leap to a boolean
    bool leap;

    //call function to set leap
    leap = checkLeapYear(year);
    if (leap == true)
    {
        cout << year << " is a leap year." << endl;
    }
    else
    {
        cout << year << " is not a leap year." << endl;
    }

    cout<<endl;

    cout << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // is not a leap year
    leap = checkLeapYear(1700);
    if (leap == true)
    {
        cout << "1700 is a leap year." << endl;
    }
    else
    {
        cout << "1700 is not a leap year." << endl;
    }

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // is a leap year
    leap = checkLeapYear(1616);
    if (leap == true)
    {
        cout <<"1616 is a leap year." << endl;
    }
    else
    {
        cout <<"1616 is not a leap year." << endl;
    }

    return 0;
}
