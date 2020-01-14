// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Project 1 - Problem # 2

#include <iostream>
#include <cstdlib>
using namespace std;

/*
    Returns a random integer netween 1 and 6
    @param N/A
    @return random integer between 1 and 6 (inclusive)
    *** given function
*/
int rollDie()
{
    return rand()%6+1;
}

/*
    Add the values of 2 (simulated) rolled dice
    @param sumDesired (int) -  input sum as integer
    @return N/A
*/
void diceSum (int sumDesired)
{
    int die1, die2;
    int sum = 0;
    int rollNum = 0;

    if (sumDesired <2 || sumDesired > 12 || sumDesired < 0)
    {
        cout << "The desired sum should be between 2 and 12" << endl;
    }
    else
    {
        while (sum != sumDesired)
        {
            rollNum ++;

            die1 = rollDie();
            die2 = rollDie();
            cout << "You rolled a " << die1 << " and a " << die2 << endl;

            sum = die1 + die2;
        }

        cout << "Got a " << sumDesired << " in " << rollNum << " rolls!" << endl;
    }
}

main()
{
    // initialize the sumDesired and set it to user input
    int sumDesired;
    cout << "Please enter your deisred sum: ";
    cin >> sumDesired;

    //call function diceSum
    diceSum(sumDesired);

    cout << endl;

    cout << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    //The desired sum should be between 2 and 12
    cout << "With desired sum = -13" << endl;
    diceSum(-13);

    cout << endl;

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    //"Got a 10 in (random amount of) rolls!"
    cout << "With desired sum = 10" << endl;
    diceSum(10);



    return 0;
}
