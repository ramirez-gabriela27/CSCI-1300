// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 9 - Problem # 1

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

/*
    Using an iterative function, convert a decimal to a binary string
    @param inputToConvert (double) - the decimal number being converted
    @return inputConverted (string) - the binary equivalent
*/
string decimalToBinaryIterative(int inputToConvert){
    string inputConverted = "";

    vector<int> temporaryVector;
    int temporaryQuotient = 6;

    while(temporaryQuotient != 0){
        int remain = fmod(inputToConvert,2.0);
        temporaryQuotient = inputToConvert/2;
        inputToConvert = temporaryQuotient;
        temporaryVector.push_back(remain);
    }

    for(int i = temporaryVector.size(); i > 0; i--){
        string tempConverted = to_string(temporaryVector[(i-1)]);
        inputConverted += tempConverted;
    }

    return inputConverted;
}

main(){


    cout << "Please enter a decimal you wish to convert: " << endl;
    int inputToConvert;
    cin >> inputToConvert;

    string inputConverted;
    inputConverted = decimalToBinaryIterative(inputToConvert);

    cout << "The binary equivalent of " << inputToConvert << " is " << inputConverted << endl;

    cout << endl << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // 0
    cout << "The binary equivalent of 0 is " << decimalToBinaryIterative(0) << endl;

    cout << endl;

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // 010101111
    cout << "The binary equivalent of 175 is " << decimalToBinaryIterative(175) << endl;

    return 0;
}
