#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User{
private:
    string username;
    // array of ratings (size = 50)
    int ratings[50];
    // number of books in database
    int numRatings;
    // capacity of the ratings array (50) constant
    int size;

public:
    User();                                           // Default constructor
    User(string userIn, int rateIn[], int numRateIn); // Parameterized constructor

    string getUsername();                             // getter
    void setUsername(string userIn);                  // setter
    int getRatingAt(int index);                       // getter
    bool setRatingAt(int index, int value);           // setter
    int getNumRatings();                              // getter
    void setNumRatings(int rateIn);                   // setter
    int getSize();                                    // getter
};

#endif
