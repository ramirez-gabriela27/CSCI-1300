// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 6 - Problem # 3

#include <iostream>
#include <string>
using namespace std;

/*
    split a message based on a delimiter and put it in a two dimensional array
    @param message (string) - message input by user
    @param delimiter (char) - delimiter (place of division) input by the user
    @param messageSubstrings (array) - array of substrings
    @param size (int) - size of the array
    @return substringNums (int) - the number of substrings
*/
int split (string message, char delimiter, string messageSubstrings[], int size){
    if (message.length() == 0) {
        return 0;
    }
    string temp = "";
    int substringNums = 0;

    message += delimiter;

    for (int i = 0; i < message.length(); i++)
    {
        if(message[i]==delimiter){
            if(temp.length() == 0) continue;
            messageSubstrings[substringNums] = temp;
            substringNums ++;
            temp = "";
        }
        else{
            temp = temp + message[i];
        }
    }

    if(size<substringNums){
        return -1;
    }
    else{
        return substringNums;
    }
}

main(){
    string message;
    char delimiter;
    int size;
    string messageSubstrings[10];

    cout << "Please input a message: " << endl;
    getline(cin,message);

    cout << "Please input a delimiter: " << endl;
    cin >> delimiter;

    cout << "Please input a size for the array: " <<endl;
    cin >> size;

    int substringNums = split(message, delimiter, messageSubstrings, size);
    cout << "There are " << substringNums << " words in the array" << endl;
    for (int i = 0; i<size; i++){
        cout << messageSubstrings[i]<< endl;
    }


    cout << endl;

    cout << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // there are 4 words in the message
    // print words
    substringNums = split("cat,pig,cow,elephant", ',', messageSubstrings, 4);
    cout << "There are " << substringNums << " words in the array" << endl;
    for (int i = 0; i<4; i++){
        cout << messageSubstrings[i] << endl;
    }

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // There are 2 words in the message
    // print words
    substringNums = split(" there was  ", ' ', messageSubstrings, 2);
    cout << "There are " << substringNums << " words in the array" << endl;
    for (int i = 0; i<2; i++){
        cout << messageSubstrings[i] << endl;
    }
    return 0;
}
