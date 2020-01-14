// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 6 - Problem # 1

#include <iostream>
using namespace std;

main(){
    // array of 10 floating point numbers initialized with -459.67
    float temps[10];
    for (int i = 0; i<10; i++){
        temps[i] = -459.67;
    }
    for (int i = 0; i<10; i++){
        cout << temps[i] << endl;
    }

    cout << endl;

    // array of a list of colors
    string colors[5] = {"Red","Blue","Green","Cyan","Magenta"};
    for (int i = 0; i<5; i++){
        cout << colors[i] << endl;
    }

    cout << endl;

    // array of first 100 positive integers in order
    int sequences[100];
    int num = 1;
    for (int i = 0; i<100; i++){
        sequences[i] = num;
        num ++;
    }
    for (int i = 0; i<100; i++){
        cout << sequences[i] << endl;
    }

    cout << endl;

    // array of all uper case and lower case letters
    char letters[52];
    char letterAscii = 65;
    int index = 0;
    while (letterAscii >= 65 && letterAscii <= 90){
        letters[index] = letterAscii;
        letterAscii ++;
        index ++;
    }
    letterAscii = 97;
    while (letterAscii >= 97 && letterAscii <= 122){
        letters[index] = letterAscii;
        letterAscii ++;
        index ++;
    }
    for (int i = 0; i<26; i++){
        cout << letters[i] << " " << letters[i+26] << endl;
    }
}
