// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 3 - Problem # 3

#include <iostream>
using namespace std;

/*
    Creates a class greeting based on the course number
    @param courseNum (int) - input course number as an integer
    @return N/A
*/
void classGreeting (int courseNum)
{
    cout<<"Hello, CS "<<courseNum<<" World!"<< endl;
}

int main()
{
    //initialized courseNum and set it to 0000 to test that it works
    int courseNum = 0000;
    cout<<"Enter a CS course number: "<<endl;
    //courseNum is set to the user input
    cin>> courseNum;
    //call the classGreeting fucntion and use courseNum as a param
    classGreeting(courseNum);
    cout << endl;

    cout << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // Hello, CS 1320 World!
    classGreeting(1320);

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // Hello, CS 1200 World!
    classGreeting(1200);
    return 0;
}
