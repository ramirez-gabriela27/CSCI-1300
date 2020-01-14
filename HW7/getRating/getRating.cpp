// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 7 - Problem # 8

#include <iostream>
#include <fstream>
#include <string>
#include "Book.h"
#include "User.h"

using namespace std;

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

main(){

    cout << endl << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // User1 rated Book2 to 4

    Book books[2];
    books[0].setTitle("Book1");
    books[0].setAuthor("Author1");
    books[1].setTitle("Book2");
    books[1].setAuthor("Author2");

    User users[2];
    users[0].setUsername("User1");
    users[0].setNumRatings(2);
    users[0].setRatingAt(0,3);
    users[0].setRatingAt(1,4);
    users[1].setUsername("User2");
    users[1].setNumRatings(2);
    users[1].setRatingAt(0,5);
    users[1].setRatingAt(1,0);

    int rateNum = getRating("User1", "Book2", users, books, 2, 2);
    cout << "User1 rated Book2 to " << rateNum << endl;

    cout << "Test Case 2" << endl;
    // test 1
    // expected output
    // User2 rated Book1 to 5
    rateNum = getRating("User2", "Book1", users, books, 2, 2);
    cout << "User2 rated Book1 to " << rateNum << endl;

    return 0;
}
