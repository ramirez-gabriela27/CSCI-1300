// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Project 1 - Problem # 1

#include <iostream>
using namespace std;

/*
    Print all odd numbers less than or equal to the max
    @param maxValue (int) -  input value as integer
    @return N/A
*/
void printOddNums (int maxValue)
{
    // initialize num for counter
    int num = 0;

    while (num <= maxValue)
    {
        if (num % 2 == 1)
        {
            cout << num << endl;
            num ++;
        }
        else
        {
            num ++;
        }
    }
}

main()
{
    // initialize maxValue and set it equal to the user input
    int maxValue;
    cout << "Please input a value: " << endl;
    cin >> maxValue;
    //call the function printOddNums
    printOddNums(maxValue);

    cout << endl;

    cout << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    //1 3 5 7 9 11
    cout << "Input number = 11" << endl;
    printOddNums(11);

    cout << endl;

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // 1 3 5 7 9 11 13 15
    cout << "Input number = 16 " << endl;
    printOddNums(16);

    return 0;
}
