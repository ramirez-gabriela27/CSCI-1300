// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 9 - Problem # 2

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

/*
    Using a recursive function, convert a decimal to a binary string
    @param inputToConvert (int) - the decimal number being converted
    @return inputConverted (string) - the binary equivalent
*/
string decimalToBinaryRecursive(int inputToConvert){
    string inputConverted = "";

    if(inputToConvert == 0){
        inputConverted = "0";
    }
    else{
        int remain = fmod(inputToConvert,2.0);
        inputConverted += to_string(remain);
        inputToConvert = inputToConvert/2;
        inputConverted = decimalToBinaryRecursive(inputToConvert) + inputConverted;
    }
    return inputConverted;
}

main(){
    cout << "Please enter a decimal you wish to convert: " << endl;
    int inputToConvert;
    cin >> inputToConvert;

    string inputConverted;
    inputConverted = decimalToBinaryRecursive(inputToConvert);

    cout << "The binary equivalent of " << inputToConvert << " is " << inputConverted << endl;

    cout << endl << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // 0
    cout << "The binary equivalent of 0 is " << decimalToBinaryRecursive(0) << endl;

    cout << endl;

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // 010101111
    cout << "The binary equivalent of 175 is " << decimalToBinaryRecursive(175) << endl;

    return 0;
}
