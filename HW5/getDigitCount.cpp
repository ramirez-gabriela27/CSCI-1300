// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 5 - Problem # 1

#include <iostream>
#include <string>
using namespace std;

/*
    Determine the number of digits in the string inserted by the user
    @param userInsert (string) - input a statement
    @return digit (int) - amount of digits returned as integers
*/
int getDigitCount (string userInsert){
    int digitNum = 0;

    for(int i = 0; i < userInsert.length(); i++ ){
        //compared to ASCII characters (0-9)
        if(userInsert[i] >= 48 && userInsert[i] <=57){
            digitNum ++;
        }
    }
    return digitNum;
}

int main(){
    // initialize userInsert and digitNum
    string userInsert;
    int digitNum;

    // define userInsert as the statement input by the user
    cout << "Please input one statement: " << endl;
    cin >> userInsert;

    // call func and define digitNum as the return value
    digitNum = getDigitCount(userInsert);
    cout << "The statement " << userInsert << " has " << digitNum << " digits." << endl;

    cout << endl;

    cout << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // 3
    digitNum = getDigitCount("Hello123");
    cout << "The statement \"Hello123\" has " << digitNum << " digits." << endl;

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // 0
    digitNum = getDigitCount("today&tomorrow");
    cout << "The statement \"Hello123\" has " << digitNum << " digits." << endl;

    return 0;

}
