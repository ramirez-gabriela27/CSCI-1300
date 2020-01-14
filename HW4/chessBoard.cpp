// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 4 - Problem # 4

#include <iostream>
#include <string>
using namespace std;

/*
    Determine the space color based on the combination of letters and numbers
    @param letter(char), number(int) - input letter and number
    @return N/A
*/
void chessBoard(char letter, int number)
{
    if (number <=8 && letter == 'a'||letter == 'c'|| letter == 'e' ||letter == 'g')
    {
        if (number%2 == 0)
        {
            cout << "white" << endl;
        }
        else
        {
            cout << "black" << endl;
        }
    }
    else if (number <=8 && letter == 'b'||letter == 'd'||letter == 'f'||letter == 'h')
    {
        if (number%2 == 1)
        {
            cout << "white" << endl;
        }
        else
        {
            cout << "black" << endl;
        }
    }
    else
    {
        cout << "Chessboard squares can only have letters between a-h and numbers between 1-8" << endl;
    }
}

main()
{
    //initialize letter and int and number as a character and set them to user inputs
    char letter;
    int number;
    cout << "Please input the letter to the corresponding space: " << endl;
    cin>>letter;
    cout << "Please input the number to the corresponding space: " << endl;
    cin>>number;
    //call function using input letter and number
    chessBoard(letter, number);

    cout << endl;

    cout << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // black
    cout << "The space 'g''5' is: ";
    chessBoard ('g',5);

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // white
    cout << "The space 'c''4' is: ";
    chessBoard ('c',4);

    return 0;
}
