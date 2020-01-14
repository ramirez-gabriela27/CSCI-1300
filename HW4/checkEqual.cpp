// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 4 - Problem # 3

#include <iostream>
using namespace std;

/*
    Determine if a set of input numbers is all the same, all different, or neither
    @param num1, num2, num3 (int) - input 3 numbers as an integers
    @return N/A
*/
void checkEqual (int num1, int num2, int num3)
{
    if (num1==num2 && num2==num3 && num1==num3)
    {
        cout << "All same" << endl;
    }
    else
        if (num1!=num2 && num2!=num3 && num1!=num3)
        {
            cout << "All different" << endl;
        }
    else
    {
        cout << "Neither" << endl;
    }
}

int main()
 {
    //initialize num1,num2,num3 and set them all to inputs form the user
    int num1, num2, num3;
    cout << "Please input 3 numbers: " << endl;
    cin >> num1;
    cin >> num2;
    cin >> num3;
    //call function using the 3 input numbers
    checkEqual (num1, num2, num3);

    cout << endl;

    cout << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // All different
    cout << "The set (1,3,2) is: ";
    checkEqual(1,3,2);

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // All Same
    cout << "The set (1,1,1) is: ";
    checkEqual(1,1,1);

    return 0;
}
