#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

// Default constructor
Book::Book(){
    title = "";
    author = "";
}

// Parameterized constructor
Book::Book(string titleIn, string authorIn){
    title = titleIn;
    author = authorIn;
}

/*
    GET the book's title
    @param N/A
    @return title (string) - the book's title
*/
string Book::getTitle(){
    return title;
}

/*
    SET the book's title
    @param titleIn (string) - the book's title
    @return N/A
*/
void Book::setTitle(string titleIn){
    title = titleIn;
}

/*
    GET the book's author
    @param N/A
    @return author (string) - the book's author
*/
string Book::getAuthor(){
    return author;
}

/*
    SET the book's author
    @param authorIn (string) - the book's author
    @return N/A
*/
void Book::setAuthor(string authorIn){
    author = authorIn;
}
