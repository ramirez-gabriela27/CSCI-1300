#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book{
private:
    string title;
    string author;

public:
    Book();                                  // Default constructor
    Book(string titleIn, string authorIn);   // Parameterized constructor

    string getTitle();                       // getter
    void setTitle(string titleIn);           // setter
    string getAuthor();                      // getter
    void setAuthor(string authorIn);         // setter
};

#endif
