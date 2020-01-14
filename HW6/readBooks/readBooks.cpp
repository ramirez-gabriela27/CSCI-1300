// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 6 - Problem # 5

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
    Read the books and authors in a text file and place them in an array
    @param fileName (string) - The name of the file being read
    @param titles (array) - Array of book titles
    @param authors (array) - Array of authors of corresponding books
    @param numBookStored (int) - The number of books already stored
    @param size (int) - size of arrays (must be >= numBookStored)
    @return numberOfIntegers (int) - The number of integers read in a file.
*/
int readBooks(string fileName, string titles[], string authors[], int numBookStored, int size){

    // open file to read
    ifstream inFile;
    inFile.open(fileName);

    //When file isn't opened successfully return -1
    if (inFile.fail()) {
        return -1;
    }
    //When the array is full return -2
    if (numBookStored == size){
        return -2;
    }

    string line;
    string messageSubstrings[2];

    if (numBookStored < size){
        while(getline(inFile,line) && numBookStored < size){
            // if the line is empty, skip it
            if (line.empty()) continue;
            split(line, ',', messageSubstrings,2);
            authors[numBookStored] = messageSubstrings[0];
            titles[numBookStored] = messageSubstrings[1];
            numBookStored ++;
        }
    }
    else{
        numBookStored = 0;
        while(getline(inFile,line) && numBookStored < size){
            // if the line is empty, skip it
            if (line.empty()) continue;
            split(line, ',', messageSubstrings,2);
            authors[numBookStored] = messageSubstrings[0];
            titles[numBookStored] = messageSubstrings[1];
            numBookStored ++;
        }
    }
    return numBookStored;
}

main(){
    string fileName;
    cout << "Please enter the name of the file you want to use: " << endl;
    cin >> fileName;

    int size;
    cout << "Please enter the number of books you want to store: " << endl;
    cin >> size;

    int numBookStored;
    cout << "Please enter the number of books already stored: " << endl;
    cin >> numBookStored;

    string titles[size];
    string authors[size];

    numBookStored = readBooks(fileName,titles,authors,numBookStored,size);

    cout << "\nThere are " << numBookStored << " books stored." << endl;
    for (int i = 0; i < numBookStored; i++){
        cout << titles[i] << " by " << authors[i] << endl;
    }

    cout << endl;

    cout << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // The are 3 books stored
    // print books list

    numBookStored = readBooks("books1.txt",titles,authors,0,3);
    cout << "\nThere are " << numBookStored << " books stored." << endl;
    for (int i = 0; i < numBookStored; i++){
        cout << titles[i] << " by " << authors[i] << endl;
    }

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // The are 2 books stored
    // print books list

    numBookStored = readBooks("books2.txt",titles,authors,0,2);
    cout << "\nThere are " << numBookStored << " books stored." << endl;
    for (int i = 0; i < numBookStored; i++){
        cout << titles[i] << " by " << authors[i] << endl;
    }

    return 0;
}
