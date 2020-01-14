// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 5 - Problem # 2

#include <iostream>
#include <string>
using namespace std;

/*
    Determine the number of words in the string inserted by the user
    @param userInsert (string) - input a statement
    @return words (int) - amount of words returned as integers
*/
int getWordCount(string userInsert){
    int words = 0;
    //temporary placeholder for word
    string temp;
    char separator = ' ';

    // return 0 for NULL statements right away
    if(userInsert == ""){
        return 0;
    }

    // add separator at the end so that it counts the last word
    userInsert += separator;
    for(int i = 0; i < userInsert.length(); i++ ){
        if(userInsert[i]!= separator){
            temp += userInsert[i];
        }
        else{
            temp = "";
            words ++;
        }
    }
    return words;
}

main(){
    string userInsert;

    cout << "Please enter a sentence: " << endl;
    getline( cin, userInsert );

    int words = getWordCount(userInsert);

    cout << "The sentence \"" << userInsert << "\" has " << words << " word(s)." << endl;

    cout << endl;

    cout << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // The sentence has 2 words.
    words = getWordCount("How ya doing?");
    cout << "The sentence \"" << "How ya doing?" << "\" has " << words << " word(s)." << endl;

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // The sentence has 0 words.
    words = getWordCount("");
    cout << "The sentence \"" << "" << "\" has " << words << " word(s)." << endl;

    return 0;
}
