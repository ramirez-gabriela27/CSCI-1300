// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 7 - Problem # 7

#include <iostream>
#include <fstream>
#include <string>
#include "User.h"

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

/*
    read all of the ratings for books and put them in an array
    @param fileName (string) - The name of the file being read
    @param users (User) - array of user names
    @param numUsersStored (int) - number of users currently stored
    @param usersArrSize (int) - capacity of users array (100)
    @param maxCol (int) - maximum number of columns (50)
    @return numUsers (int) - the total number of users in the system
*/
int readRatings (string fileName, User users[], int numUsersStored, int usersArrSize, int maxCol){
    // open file to read
    ifstream inFile;
    inFile.open(fileName);

    //When the array is "full" return -2
    if (numUsersStored >= usersArrSize){
        return -2;
    }
    //When file isn't opened successfully return -1
    if (inFile.fail()) {
        return -1;
    }

    string line;
    string substrings[maxCol+1];
    int numSub = 0;

    while(getline(inFile,line) && numUsersStored < usersArrSize){
        // if line is empty, skip it
        if(line.empty()) continue;

        numSub = split(line,',',substrings,maxCol+1);

        users[numUsersStored].setUsername(substrings[0]);

        for (int j = 0; j<numSub-1; j++){
            if(substrings[j+1] == "")break;
            else{
                users[numUsersStored].setRatingAt(j,stoi(substrings[j+1]));
            }
        }
        numUsersStored ++;
    }
    return numUsersStored;
}

main(){
    int usersArrSize = 50;
    int maxCol = 100;
    User users[usersArrSize];

    string fileName = "";
    cout << "Please enter the name of the file: " << endl;
    getline(cin, fileName);

    int numUsersStored = 0;
    cout << "How many users are already stored? " << endl;
    cin >> numUsersStored;

    int rateNum = readRatings (fileName, users, numUsersStored, usersArrSize, maxCol);

    cout << endl << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // The user name: laura, has the rating: 4 for book #11.
    cout << "The user name: " << users[10].getUsername() << ", has the rating: " << users[10].getRatingAt(10) << " for book #11."<< endl;

    cout << endl;

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // The user name: Waldo, has the rating: 0 for book #8.
    users[7].setUsername("Waldo");
    users[7].setRatingAt(7,0);
    cout << "The user name: " << users[7].getUsername() << ", has the rating: " << users[7].getRatingAt(7) << " for book #8."<< endl;

    return 0;
}
