// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 4 - Problem # 1

#include <iostream>
using namespace std;

/*
    Tells user if the number input is positive, negative, or zero
    @param num (int) - input number as an integer
    @return N/A
*/
void numberSign (int num)
{
    if (num < 0)
     {
        cout << "negative" << endl;
    }
    else
        if (num > 0)
        {
            cout << "positive" << endl;
        }
    else
    {
        cout << "zero" << endl;
    }
}

main()
{
    //initialize num and ask user for input for num
    int num;
    cout << "Please input an integer: " << endl;
    cin >> num;
    //call function
    numberSign(num);

    cout << endl;

    cout << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // num: negative
    cout << "The number -256 is: ";
    numberSign(-256);

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // num: positive
    cout << "The number 2 is: ";
    numberSign(2);

    return 0;
}
