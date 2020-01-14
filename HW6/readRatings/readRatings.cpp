// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 6 - Problem # 7

#include <iostream>
#include <fstream>
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

/*
    read all of the ratings for books and put them in an array
    @param fileName (string) - The name of the file being read
    @param users (array) - array of user names
    @param ratings (2 dimensional array) - list of ratings for each user.
        rows - number of users
        columns - number of books
    @param numUsers (int) - number of users currently stored
    @param maxRows (int) - max number of rows of the ratings (2d array) - 100
    @param maxColumns (int) - maximum number of columns of the ratings (2d array) - 50
    @return numUsers (int) - the total number of users in the system
*/
int readRatings (string fileName, string users[], int ratings[][50], int numUsers, int maxRows, int maxColumns){
    // open file to read
    ifstream inFile;
    inFile.open(fileName);

    //When the array is "full" return -2
    if (numUsers >= maxRows){
        return -2;
    }
    //When file isn't opened successfully return -1
    else if (inFile.fail()) {
        return -1;
    }
    else{
        string line;
        string substrings[maxColumns];

        while(getline(inFile,line) && numUsers < maxRows){
            // if line is empty, skip it
            if(line.empty()) continue;

            int numSub = split(line,',',substrings,maxColumns);

            users[numUsers] = substrings[0];

            for (int j = 0; j<numSub; j++){
                if(substrings[j+1] == "")break;
                else{
                    ratings[numUsers][j] = stoi(substrings[j+1]);
                }
            }
            numUsers ++;
        }
    }
    return numUsers;
}

main(){
    string fileName;
    cout << "Please enter the name of the file you want to use: " << endl;
    cin >> fileName;

    int numUsers;
    cout << "Please enter the number of users already stored: " << endl;
    cin >> numUsers;

    string users[100];
    int ratings[100][50];

    int maxRows;
    cout << "Please enter the max number of rows: " << endl;
    cin >> maxRows;

    int maxColumns;
    cout << "Please enter the max number of columns: " << endl;
    cin >> maxColumns;

    numUsers = readRatings(fileName,users,ratings,numUsers,maxRows,maxColumns);

    cout << "There are " << numUsers << " users stored." << endl;
    for(int i = 0; i < numUsers; i++){
        cout << users[i];
        for(int j = 0; j < maxColumns; j++){
            cout << ratings [i][j];
        }
        cout << endl;
    }

    cout << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // The are 2 users stored
    // print users and their ratings
    numUsers = 0;
    numUsers = readRatings("ratings1.txt",users,ratings,numUsers,maxRows,maxColumns);
    cout << "There are " << numUsers << " users stored." << endl;
    for(int i = 0; i < numUsers; i++){
        cout << users[i];
        for(int j = 0; j < maxColumns; j++){
            cout << ratings [i][j];
        }
        cout << endl;
    }

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // The are 3 users stored
    // print users and their ratings
    numUsers = 0;
    numUsers = readRatings("ratings2.txt",users,ratings,numUsers,maxRows,maxColumns);
    cout << "There are " << numUsers << " users stored." << endl;
    for(int i = 0; i < numUsers; i++){
        cout << users[i];
        for(int j = 0; j < maxColumns; j++){
            cout << ratings [i][j];
        }
        cout << endl;
    }
    return 0;
}
