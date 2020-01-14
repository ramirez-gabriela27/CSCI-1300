// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 5 - Problem # 3

#include <iostream>
#include <string>
using namespace std;

/*
    Split the input message based on the input "split character"
    @param userInsert (string) delimiter (char) - message as string, and the delimiter
    @return substringNums (int) - returns the amount of substrings
*/
int split(string userInsert, char delimiter){
    int substringNums = 0;
    string temp;

    if (userInsert == ""){
        substringNums = 0;
        return substringNums;
    }

    userInsert += delimiter;
    for (int i=0; i < userInsert.length(); i++)
    {
        if (userInsert[i] != delimiter){
            temp += userInsert[i];
        }
        else{
            cout << temp << endl;
            temp = "";
            substringNums++;
        }
    }
    return substringNums;
}

main(){
    string userInsert;
    char delimiter;

    cout << "Please enter a statement: " << endl;
    getline(cin,userInsert);

    cout << "Where would you like to split the statement?" << endl;
    cin >> delimiter;

    int substringNums = split(userInsert,delimiter);

    cout << "The statement has " << substringNums << " substrings." << endl;

    cout << endl;

    cout << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // 0
    substringNums = split("", ' ');
    cout << "The statement has " << substringNums << " substrings." << endl;

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // 2
    substringNums = split("ABCD,EFG",',');
    cout << "The statement has " << substringNums << " substrings." << endl;

    return 0;
}
