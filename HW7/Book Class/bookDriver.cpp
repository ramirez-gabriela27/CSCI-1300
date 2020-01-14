// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 7 - Problem # 3

#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

main(){

    cout << "Test Cases" << endl;
    // tests for each member function
    // expected output
    // title by, author
    cout << "Please enter a book title: " << endl;
    string titleIn;
    getline(cin, titleIn);
    cout << "Please enter the author of the book: " << endl;
    string authorIn;
    getline(cin, authorIn);

    Book book1(titleIn, authorIn);
    cout << book1.getTitle() << " by, " << book1.getAuthor() << endl;

    return 0;
}
