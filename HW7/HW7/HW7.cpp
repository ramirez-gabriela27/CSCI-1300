// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 7 - Problem # 9

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Book.h"
#include "User.h"
using namespace std;

//////////////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////

/*
    Read the books and authors in a text file and place them in an array
    @param fileName (string) - The name of the file being read
    @param books (Book) - Array of book objects
    @param numBookStored (int) - The number of books already stored
    @param booksArrSize (int) - size of array (50)
    @return numberBooksStored (int) - The number of books stored
*/
//////////////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////

/*
    read all of the ratings for books and put them in an array
    @param fileName (string) - The name of the file being read
    @param users (User) - array of user names
    @param numUsersStored (int) - number of users currently stored
    @param usersArrSize (int) - capacity of users array (100)
    @param maxCol (int) - maximum number of columns (50)
    @return numUsers (int) - the total number of users in the system
*/
//////////////////////////////////////////////////////////////////////////
int readRatings (string fileName, User users[], int numUsersStored, int usersArrSize, int maxCol){
    // open file to read
    ifstream inFile;
    inFile.open(fileName);

    //When the array is "full" return -2
    if (numUsersStored >= usersArrSize){
        return -2;
    }
    //When file isn't opened successfully return -1
    else if (inFile.fail()) {
        return -1;
    }
    else{
        string line;
        string substrings[maxCol+1];

        while(getline(inFile,line) && numUsersStored < usersArrSize){
            // if line is empty, skip it
            if(line.empty()) continue;

            int numSub = split(line,',',substrings,maxCol+1);

            users[numUsersStored].setUsername(substrings[0]);

            for (int j = 0; j<numSub; j++){
                if(substrings[j+1] == "")break;
                else{
                    users[numUsersStored].setRatingAt(j,stoi(substrings[j+1]));
                }
            }
            numUsersStored ++;
        }
    }
    return numUsersStored;
}
//////////////////////////////////////////////////////////////////////////

/*
    print all of the books in the array
    @param books (array) - Array of books
    @param numBooksStored (int) - The number of books already stored
    @return N/A
*/
//////////////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////

/*
    return the rating that the user gave for a book based on its title and the user name
    @param username (string) - the user name
    @param bookTitle (string) - the title of the book
    @param users (User) - array of users
    @param books (Book) - array of books
    @param usersStored (int) - The number of users in the array
    @param booksStored (int) - The number of books in the arra
    @return rateNum (int) - the rating given if the user name and title are found
*/
//////////////////////////////////////////////////////////////////////////
int getRating(string username, string bookTitle, User users[], Book books[], int usersStored, int booksStored){

    //change all of username to uppercase
    for(int i = 0; i < username.length(); i++){
        username[i] = toupper(username[i]);
    }
    //change all of book title to uppercase
    for(int i = 0; i < bookTitle.length(); i++){
        bookTitle[i] = toupper(bookTitle[i]);
    }

    bool userExist;
    bool titleExist;

    if(usersStored == 0 || booksStored == 0){
        return -3;
    }
    else{
        int userIndex = 0;
        for (int i = 0; i < usersStored; i++){
            //change the username being tested to uppercase
            string userTest = users[i].getUsername();
            for(int i = 0; i < userTest.length(); i++){
                userTest[i] = toupper(userTest[i]);
            }

            if(username == userTest){
                userIndex = i;
                userExist = true;
                break;
            }
            else{
                userExist = false;
            }
        }

        int bookIndex = 0;
        for (int j = 0; j < booksStored; j++){
            //change the booktitle being tested to uppercase
            string titleTest = books[j].getTitle();
            for(int i = 0; i < titleTest.length(); i++){
                titleTest[i] = toupper(titleTest[i]);
            }

            if(bookTitle == titleTest){
                bookIndex = j;
                titleExist = true;
                break;
            }
            else{
                titleExist = false;
            }
        }

        if(userExist == false || titleExist == false){
            return -3;
        }
        else{
            int rateNum = users[userIndex].getRatingAt(bookIndex);
            return rateNum;
        }
    }
}
//////////////////////////////////////////////////////////////////////////

/* displayMenu:
 * displays a menu with options
 * DO NOT MODIFY THIS FUNCTION
 */
void displayMenu(){
  cout << "Select a numerical option:" << endl;
  cout << "======Main Menu=====" << endl;
  cout << "1. Read book file" << endl;
  cout << "2. Read user file" << endl;
  cout << "3. Print book list" << endl;
  cout << "4. Get rating" << endl;
  cout << "5. Quit" << endl;
}


int main(int argc, char const *argv[]) {

    // taking menu choice
    string choice;

    // number of books and users stored in the arrays
    int numBooks = 0;
    int numUsers = 0;

    // Use the these values to declare your
    // titles, authors, users and ratings arrays
    const static int  userArrSize = 100;
    const static int  bookArrSize = 50;


    // variables to store user inputs
    string bookFileName;
    string userFileName;
    string userName, bookTitle;

    Book books[bookArrSize];
    User users[userArrSize];
    int rate;

    while (choice != "5") {
        displayMenu();

        // take an opton (1, 2, 3, or 4)
        getline(cin, choice);

        // convert the `choice` to an integer
        int menuChoice = stoi(choice);
        switch (menuChoice) {
            case 1:
                // read book file
                cout << "Enter a book file name:" << endl;
                getline(cin, bookFileName);

                //////////////////////////////////////////////////////////////////////////
                numBooks = readBooks(bookFileName,books, numBooks, bookArrSize);
                //////////////////////////////////////////////////////////////////////////

                if(numBooks == -2){
                    cout << "Database is already full. No books were added." << endl;
                }
                else if(numBooks == -1){
                    cout << "No books saved to the database." << endl;
                }
                else if(numBooks == bookArrSize){
                    cout << "Database is full. Some books may have not been added." << endl;
                }
                else{
                    cout << "Total books in the database: " << numBooks << endl;
                }

                cout << endl;
                break;

            case 2:
                // read ratings file
                cout << "Enter a user file name:" << endl;
                getline(cin, userFileName);

                //////////////////////////////////////////////////////////////////////////
                numUsers = readRatings(userFileName, users, numUsers, userArrSize, 100);
                //////////////////////////////////////////////////////////////////////////
                if(numUsers == -2){
                    cout << "Database is already full. No users were added." << endl;
                }
                else if(numUsers == -1){
                    cout << "No users saved to the database." << endl;
                }
                else if(numUsers == userArrSize){
                    cout << "Database is full. Some users may have not been added." << endl;
                }
                else{
                    cout << "Total users in the database: " << numUsers << endl;
                }

                cout << endl;
                break;

            case 3:
                // print the list of the books

                //////////////////////////////////////////////////////////////////////////
                printAllBooks(books, numBooks);
                //////////////////////////////////////////////////////////////////////////

                cout << endl;
                break;

            case 4:
                // get user's rating
                // take user name
                cout << "Enter username:" << endl;
                getline(cin, userName);

                // take book title
                cout << "Enter book title:" << endl;
                getline(cin, bookTitle);

                //////////////////////////////////////////////////////////////////////////
                rate = getRating(userName, bookTitle, users, books, numUsers, numBooks);
                //////////////////////////////////////////////////////////////////////////
                if(rate == -3){
                    cout << userName << " or " << bookTitle << " does not exist" << endl;
                }
                else if(rate == 0){
                    cout << userName << " has not rated " << bookTitle << endl;
                }
                else{
                    cout << userName << " rated " << bookTitle << " with " << rate << endl;
                }

                cout << endl;
                break;
            case 5:
                // quit
                cout << "good bye!" << endl;
                break;

            default:
                cout << "invalid input" << endl;
        }
    }

    return 0;
}
