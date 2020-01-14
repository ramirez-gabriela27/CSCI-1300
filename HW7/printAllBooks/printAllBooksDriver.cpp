// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 7 - Problem # 6

#include <iostream>
#include <fstream>
#include <string>
#include "Book.h"

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
    @param books (Book) - Array of book objects
    @param numBookStored (int) - The number of books already stored
    @param booksArrSize (int) - size of array (50)
    @return numberBooksStored (int) - The number of books stored
*/
int readBooks(string fileName,Book books[], int numBooksStored, int booksArrSize){
    // open file to read
    ifstream inFile;
    inFile.open(fileName);

    //When the array is full return -2
    if (numBooksStored == booksArrSize){
        return -2;
    }
    //When file isn't opened successfully return -1
    if (inFile.fail()) {
        return -1;
    }

    string line;
    string messageSubstrings[2];

    while(getline(inFile,line) && numBooksStored < booksArrSize){
        // if the line is empty, skip it
        if (line.empty()) continue;
        split(line, ',', messageSubstrings,2);
        books[numBooksStored] = Book(messageSubstrings[1],messageSubstrings[0]);
        numBooksStored ++;
    }
    inFile.close();
    return numBooksStored;
}

/*
    print all of the books in the array
    @param books (array) - Array of books
    @param numBooksStored (int) - The number of books already stored
    @return N/A
*/
void printAllBooks(Book books[], int numBooksStored){
    if (numBooksStored <=0){
        cout << "No books are stored" << endl;
    }
    else{
        cout << "Here is a list of books" << endl;
        for (int i = 0; i<numBooksStored; i++){
            cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
        }
    }
}

main(){
    int booksArrSize = 50;
    Book books[booksArrSize];

    string fileName = "";
    cout << "Please enter the name of the file from which you want to read from: " << endl;
    getline(cin,fileName);

    int numBooksStored;
    cout << "Please enter the number of books already stored: " << endl;
    cin >> numBooksStored;

    numBooksStored = readBooks(fileName, books, numBooksStored, booksArrSize);

    printAllBooks(books, numBooksStored);

    cout << endl << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // list of books in "books1.txt"
    numBooksStored = readBooks("books1.txt", books, 0, 3);
    printAllBooks(books, numBooksStored);

    cout << endl;

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // list of books in "books2.txt"
    numBooksStored = readBooks("books2.txt", books, 0, 2);
    printAllBooks(books, numBooksStored);


    return 0;

}
