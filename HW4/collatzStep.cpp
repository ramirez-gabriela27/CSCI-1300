// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 4 - Problem # 2

#include <iostream>
using namespace std;

/*
    Find the next number in the Collatz sequence from an input number
    @param num (int) - input number as an integer
    @return nextNum (int) - following number in sequence as an integer
*/
int collatzStep (int num)
{
    int nextNum;

    if (num%2 == 0 && num > 0)
    {
        nextNum = (num / 2);
        return nextNum;
    }
    else
        if(num%2 == 1 && num > 0)
        {
            nextNum = (num *3) + 1;
            return nextNum;
        }
    else
    {
        return 0;
    }
}

main()
{
    //initialize num and ask user for input
    int num;
    cout << "Please input an integer: " << endl;
    cin >> num;
    //initialize nuxtNum and call function to set value of variable
    int nextNum = collatzStep(num);
    cout << "The number following " << num << " is " << nextNum << endl;

    cout << endl;

    cout << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // nextNum: 40
    nextNum = collatzStep(13);
    cout << "The number following 13 is: " << nextNum << endl;

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // nextNum: 2
    nextNum = collatzStep(4);
    cout << "The number 4 is: " << nextNum << endl;

    return 0;
}
