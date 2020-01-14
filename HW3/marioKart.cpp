// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 3 - Problem # 10

#include <iostream>
#include <math.h>
using namespace std;

/*
    Calculate the deceleration form a given initial speed and the distance
    @param speedInitial (double) and distance (dobule)
    @return deceleration (double)
*/
double marioKart (double speedInitial, double distance)
{
    double deceleration;
    deceleration = (pow(speedInitial,2)) / (2 * distance);
    return deceleration;
}

main()
{
    //initialize speedInitial and distance and set the to user inputs
    double speedInitial;
    double distance;
    cout << "Please enter Baby Mario's initial speed: " << endl;
    cin >> speedInitial;
    cout << "Please enter the distance between Baby Mario's kart and the broken down one: " << endl;
    cin >> distance;
    //initialize deceleration and calculate by calling marioKart function
    double deceleration = marioKart(speedInitial,distance);
    cout << "The deceleration needed is: " << deceleration << endl;

    cout << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // The deceleration needed is: 0.950625
    deceleration = marioKart(7.8,32);
    cout << "The deceleration needed is: " << deceleration << endl;

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // The deceleration needed is: 30.1786
    deceleration = marioKart(13,2.8);
    cout << "The deceleration needed is: " << deceleration << endl;

    return 0;

}
