#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include "Book.h"
#include "User.h"

using namespace std;

class Library{
private:
    // constant size of books array
    const static int sizeBook = 50;
    // constat size of users array
    const static int sizeUser = 100;
    // array of book objects
    Book books[sizeBook];
    // array of user objects
    User users[sizeUser];
    // number of books in dtabase (library)
    int numBooks = 0;
    // number of users in database (library)
    int numUsers = 0;

public:
    // set both numBooks and numUsers to 0
    Library();

    // return size of books array
    int getSizeBook() const;
    // return size of users arra
    int getSizeUser() const;
    // return number of books in array
    int getNumBooks() const;
    // return number of users in array
    int getNumUsers() const;

    // populate books array and return the total number of books in array
    int readBooks(string fileName);
    // populate users array and return the total number of users in array
    int readRatings(string fileName);
    // return rating for the specific book given by the user
    int getRating(string username, string bookTitle);
    // return the number of books read by the user given
    int getCountReadBooks(string username);
    // return the average rating of the given book
    double calcAvgRating(string bookTitle);
    // add user (if it doesn't exist or array still has space)
    int addUser(string username);
    // set rating (if the rating is valid and the title/username exists)
    int checkOutBook(string username, string bookTitle, int newRating);

    // display all books in books array
    void printAllBooks();
    // print all the books a user has provided ratings for
    void viewRatings(string username);
    // print the first 5 book recommendations for most similar user
    void getRecommendations(string username);
};

#endif
