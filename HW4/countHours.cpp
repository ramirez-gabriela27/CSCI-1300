// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 4 - Problem # 6

#include <iostream>
using namespace std;

/*
    Determine the number of hours in a given month
    @param month (int) - input month as an integer
    @return hours (int) - number of hours as integer
*/
int countHours(int month)
{
    switch (month)
    {
        case 2:
        return 672;
        break;
        case 8:
        return 744;
        break;

        case 9:
        return 720;
        break;

        case 10:
        return 744;
        break;

        case 11:
        return 720;
        break;

        case 12:
        return 744;
        break;

    }
    int monthType = month%2;
    switch (monthType)
    {
        case 0:
        return 720;
        break;

        default:
        return 744;
    }
}

main()
{
    //initialize month and set it to user input
    int month;
    cout << "Please enter a month: " << endl;
    cin >> month;
    //initialize hours and call function to set variable
    int hours = countHours(month);
    cout << "There are " << hours << " hours in month " << month << endl;
    cout << endl;

    cout << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // hours: 720
    hours = countHours(11);
    cout << "There are " << hours << " hours in the month 11" << endl;


    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // hours: 672
    hours = countHours(2);
    cout << "There are " << hours << " hours in the month 2" << endl;


    return 0;
}
