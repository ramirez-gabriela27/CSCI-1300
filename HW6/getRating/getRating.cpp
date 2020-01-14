// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 6 - Problem # 8

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
    return the rating that the user gave for a book based on its title and the user name
    @param username (string) - the user name
    @param bookTitle (string) - the title of the book
    @param users (array) - array of users
    @param titles (array) - array of titles
    @param ratings (2D array) - list of ratings for each user (100 rows, 50 columns)
    @param numNameRate (int) - The number of user names and their ratings currently stored
    @param numBookRate (int) - The number of books and their ratings currently stored
    @return ratingValue (int) - the rating given if the user name and title are found
*/
int getRating(string username, string bookTitle, string users[], string titles[], int ratings [100][50],int numNameRate, int numBookRate){

    // I don't know how to test for the case sensitivity

    int usernameIndex = 0;
    for (int i = 0; i < numNameRate; i++){
        if(username == users[i]){
            usernameIndex = i;
            break;
        }
        else{
            return -3;
        }
    }
    
    int titleIndex = 0;
    for (int j = 0; j < numBookRate; j++){
        if(bookTitle == titles[j]){
            titleIndex = j;
            break;
        }
        else{
            return -3;
        }
    }
    int ratingValue = ratings[usernameIndex][titleIndex];
    return ratingValue;
}

main(){
    // sorry, I didn't get to finish the main function or the test cases
}
