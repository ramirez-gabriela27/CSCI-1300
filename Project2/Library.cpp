#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "Book.h"
#include "User.h"
#include "Library.h"

using namespace std;

// HELPER FUNCTIONS //
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
    change all characters to uppercase
    @param message (string) - string that is being manipulated
    @return message (string) - already altered message
*/
string toUpperCase (string message){
    for(int i = 0; i < message.length(); i++){
        message[i] = toupper(message[i]);
    }
    return message;
}
// HELPER FUNCTIONS //

// Default constructor
Library::Library(){
    numBooks = 0;
    numUsers = 0;
}

/*
    GET the size of the books array
    @param N/A
    @return sizeBook (int) - books size
*/
int Library::getSizeBook() const{
    return sizeBook;
}

/*
    GET the size of the users array
    @param N/A
    @return sizeUser (int) - users size
*/
int Library::getSizeUser() const{
    return sizeUser;
}

/*
    GET the number of books in the books array
    @param N/A
    @return numBooks (int) - number of books in array
*/
int Library::getNumBooks() const{
    return numBooks;
}

/*
    GET the number of users in the users array
    @param N/A
    @return numUsers (int) - number of users in array
*/
int Library::getNumUsers() const{
    return numUsers;
}

/*
    Populate books array and return the total number of books in array
    @param fileName (string) - The name of the file being read
    @return numBooks (int) - The number of books stored
*/
int Library::readBooks(string fileName){
    // open file to read
    ifstream inFile;
    inFile.open(fileName);

    //When array is full, return -2
    if(numBooks == sizeBook){
        return -2;
    }
    //When file isn't opened succesfully return -1
    if(inFile.fail()){
        return -1;
    }

    string line;
    string messageSubstrings[2];

    while(getline(inFile,line) && numBooks < sizeBook){
        // if the line is empty, skip it
        if (line.empty()) continue;
        // else take in the line and split it at the comma
        split(line, ',', messageSubstrings,2);

        // update the books array with the title and the author
        books[numBooks] = Book(messageSubstrings[1],messageSubstrings[0]);
        numBooks ++;    // increment numBooks
    }

    //close file and return numBooks
    inFile.close();
    return numBooks;
}

// display all books in books array
void Library::printAllBooks(){
    if(numBooks <= 0){
        cout << "No books are stored" << endl;
    }
    else{
        cout << "Here is a list of books" << endl;
        for (int i = 0; i < numBooks; i++){
            cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
        }
    }
}

/*
    populate users array and return the total number of users in array
    @param fileName (string) - The name of the file being read
    @return numUsers (int) - the total number of users in the system
*/
int Library::readRatings(string fileName){
    int numUser = getNumUsers();

    // open file to read
    ifstream inFile;
    inFile.open(fileName);

    //When array is full, return -2
    if(getNumUsers() == sizeUser){
        return -2;
    }
    //When file isn't opened succesfully return -1
    if(inFile.fail()){
        return -1;
    }

    string line;
    string messageSubstrings[sizeUser+1];
    int substringNums = 0;

    while(getline(inFile, line) && numUsers < sizeUser){
        // if line is empty, skip it
        if (line.empty()) continue;
        // else take in the line and split at the comma
        substringNums = split(line, ',', messageSubstrings, sizeUser+1);
        // set the username to the first substring
        users[numUsers].setUsername(messageSubstrings[0]);

        for(int i = 0; i < substringNums-1; i++){
            if(messageSubstrings[i+1] == "") break;
            else{
                users[numUsers].setRatingAt(i,stoi(messageSubstrings[i+1]));
            }
        }
        numUsers ++;
    }
    inFile.close();
    return numUsers;
}

/*
    return the rating that the user gave for a book based on its title and the user name
    @param username (string) - the user name
    @param bookTitle (string) - the title of the book
    @return rating (int) - the rating given if the user name and title are found
*/
int Library::getRating(string username, string bookTitle){
    // get numbers for corresponding variables
    int numUser = getNumUsers();
    int numBooks = getNumBooks();

    // change the username and book title to uppercase
        // to test for case insensitve inputs
    username = toUpperCase(username);
    bookTitle = toUpperCase(bookTitle);

    // create flag for the existance of the user and the title
    bool userExist;
    bool titleExist;

    // find the index of the username in the data base
    int userIndex = 0;
    string userTest = "";
    for (int i = 0; i < numUsers; i++){
        //change the username being tested to uppercase
        userTest = toUpperCase(users[i].getUsername());
        // if it exists the flag is set to true
        if(username == userTest){
            userIndex = i;
            userExist = true;
            break;
        }
        else{
            userExist = false;
        }
    }
    // find the index of the book (by title) in the data base
    int bookIndex = 0;
    string titleTest = "";
    for (int j = 0; j < numBooks; j++){
        //change the booktitle being tested to uppercase
        titleTest = toUpperCase(books[j].getTitle());
        // if it exists the flag is set to true
        if(bookTitle == titleTest){
            bookIndex = j;
            titleExist = true;
            break;
        }
        else{
            titleExist = false;
        }
    }
    // if either of them don't exist, return -3
    if(userExist == true && titleExist == true){
        int rating = users[userIndex].getRatingAt(bookIndex);
        return rating;
    }
    else{
        return -3;
    }
}

/*
    return the number of books read by the user given
    @param username (string) - the username input
    @return numBooksReviewed (int) - the number of books rad by the user
*/
int Library::getCountReadBooks(string username){
    // variable for the number of books reviewd
    int numBooksReviewed = 0;
    int rate = 0;
    /*loop through the books array and if rating is not 0 and not -3, it has
      been rated*/
    for (int i = 0; i < getNumBooks(); i++){
        rate = getRating(username, books[i].getTitle());
        if (rate > 0 && rate < 6){
            numBooksReviewed ++;
        }
    }
    if(numBooksReviewed == 0 && rate == -3){
        return -3;
    }
    else{
        return numBooksReviewed;
    }
}

/*
    print a list of the books rated and their ratings
    @param username (string) - the username input
    @return N/A
*/
void Library::viewRatings(string username){
    bool userExist;
    string userName = toUpperCase(username);
    string userTest = "";
    for (int i = 0; i < numUsers; i++){
            //change the username being tested to uppercase
            string userTest = toUpperCase(users[i].getUsername());
            for(int i = 0; i < userTest.length(); i++){
                userTest[i] = toupper(userTest[i]);
            }
            // if it exists the flag is set to true
            if(userName == userTest){
                userExist = true;
                break;
            }
            else{
                userExist = false;
            }
        }
    if (userExist == false){
        cout << username << " does not exist." << endl;
    }
    else{
        // use getCountReadBooks function to find how many books have been reviewed
        int bookRating = getCountReadBooks(username);
        // if it's 0, the user hasn't rated anything
        if(bookRating == 0){
            cout << username << " has not rated any books yet." << endl;
        }
        else{
            /*loop through the books array and if rating is not 0 and not -3, it has
              been rated*/
            cout << "Here are the books that " << username << " rated" << endl;
            for (int i = 0; i < getNumBooks(); i++){
                bookRating = getRating(username, books[i].getTitle());
                if (bookRating != 0 && bookRating != -3){
                    // print a list of the books and their ratings
                    cout << "Title : " << books[i].getTitle() << endl;
                    cout << "Rating : " << bookRating << endl;
                    cout << "-----" << endl;
                }
            }
        }
    }
}

/*
    return the average rating provided for a book based on the title
    @param bookTitle (string) - book title input
    @return (bookRateSum/numTotalRead) (int) - average rating
*/
double Library::calcAvgRating(string bookTitle){
    //search for book title and index of book
    bool titleExist;
    int bookIndex = 0;
    bookTitle = toUpperCase(bookTitle);
    for (int j = 0; j < getNumBooks(); j++){
        //change the booktitle being tested to uppercase
        string titleTest = toUpperCase(books[j].getTitle());
        // if it exists the flag is set to true
        if(bookTitle == titleTest){
            bookIndex = j;
            titleExist = true;
            break;
        }
        else{
            titleExist = false;
        }
    }
    if(titleExist == true){
        // number to calculate the sum of all the ratings
        double bookRateSum = 0.0;
        // number to calculate the total ratings provided
        double numTotalRead = 0.0;
        // holder for ratings
        double bookRate = 0.0;
        // add the rating for the book per user
        for(int i =0; i < getNumUsers(); i++){
            bookRate = users[i].getRatingAt(bookIndex);
            if(bookRate > 0 && bookRate < 6){
                numTotalRead ++;
                bookRateSum = bookRateSum + bookRate;
            }
        }
        if(bookRateSum == 0 || numTotalRead == 0){
            return 0;
        }
        else{
            // calculate and return the average
            double avg = bookRateSum / numTotalRead;
            return avg;
        }
    }
    else{
        return -3;
    }
}

/*
    add user (if it doesn't exist or array still has space)
    @param username (string) - username input
    @return number to indicate success/failure of adding usernames
*/
int Library::addUser(string username){
    numUsers = getNumUsers();
    bool userExist;
    for (int i = 0; i < numUsers; i++){
        // change the username to uppercase to test for case insensitve inputs
        // but keep original usernmame so it can be added if possible
        string testUserIn = toUpperCase(username);
        // test usernames in array to see if it already exists
        // but do not modify original usernames
        string testUser = toUpperCase(users[i].getUsername());
        if(testUserIn == testUser){
            userExist = true;
            break;
        }
        else{
            userExist = false;
        }
    }
    // if the array is already full, return -2
    if(numUsers == sizeUser){
        return -2;
    }
    // if the user exists, return 0
    else if(userExist == true){
        return 0;
    }
    else{
        User newUser;
        users[numUsers] = newUser;
        users[numUsers].setUsername(username);
        numUsers ++;
        for(int i = 0; i < getNumUsers(); i++){
            newUser.setRatingAt(i,0);
        }
        return 1;
    }
}

/*
    set rating (if the rating is valid and the title/username exists)
    @param username (string) - username input
    @param bookTitle (string) - book input
    @param newRating (int) - the rating for the book
    @return number to indicate success/failure of adding rating
*/
int Library::checkOutBook(string username, string bookTitle, int newRating){
    bool userExist;
    int userIndex = 0;
    // change username to uppercase to compare
    username = toUpperCase(username);
    //create string to test username
    string userTest = "";
    for (int i = 0; i < getNumUsers(); i++){
        userTest = toUpperCase(users[i].getUsername());
        if(username == userTest){
            userIndex = i;
            userExist = true;
            break;
        }
        else{
            userExist = false;
        }
    }

    bool bookExist;
    int bookIndex = 0;
    // change book title to uppercase to compare
    bookTitle = toUpperCase(bookTitle);
    //create string to test book titlr
    string bookTest = "";
    for (int i = 0; i < getNumBooks(); i++){
        bookTest = toUpperCase(books[i].getTitle());
        if(bookTitle == bookTest){
            bookIndex = i;
            bookExist = true;
            break;
        }
        else{
            bookExist = false;
        }
    }

    if(newRating < 0 || newRating > 5){
        return -4;
    }
    else if (bookExist == false || userExist == false){
        return -3;
    }
    else{
        username = toUpperCase(username);
        users[userIndex].setRatingAt(bookIndex, newRating);
        return 1;
    }
}

/*
    print the first 5 book recommendations for most similar user
    @param username (string) - username input
    @return N/A
*/
void Library::getRecommendations(string username){
    int numUsers = getNumUsers();
    int numBooks = getNumBooks();
    int userIndex =0;
    // find if the user exists in the data base
    bool userExist;
    // change username to uppercase to compare
    string userNameTest = toUpperCase(username);
    //create string to test username
    string userTest = "";
    for (int i = 0; i < numUsers; i++){
        userTest = toUpperCase(users[i].getUsername());
        if(userNameTest == userTest){
            userIndex = i;
            userExist = true;
            break;
        }
        else{
            userExist = false;
        }
    }
    if (userExist == false){
        cout << username << " does not exist." << endl;
    }
    else{
        // sum of squared differeces
        int ssd = 0;
        // to test ssd
        int userSSD = 1000000;

        int indexSimilar = 0;

        for (int i = 0; i < numUsers; i ++){
            ssd = 0;

            if(userIndex == i) continue;
            else{
                for(int j = 0; j < numBooks; j++){
                    ssd = ssd + pow((users[userIndex].getRatingAt(j)-users[i].getRatingAt(j)),2);
                }

                if (ssd > 0 && ssd < userSSD){
                    userSSD = ssd;
                    indexSimilar = i;
                }
            }
        }
        // variable to count the number of books to recommend
        int booksToRecommend = 0;
        // list of book onjects being recommended
        Book booksRecommend[5];

        for(int i = 0; i < numBooks; i++){
            if(booksToRecommend == 5){
                break;
            }
            if(users[userIndex].getRatingAt(i) == 0 && users[indexSimilar].getRatingAt(i) >= 3){
                booksRecommend[booksToRecommend].setTitle(books[i].getTitle());
                booksRecommend[booksToRecommend].setAuthor(books[i].getAuthor());
                booksToRecommend ++;
            }
        }

        if(booksToRecommend == 0){
            cout << "There are no recommendations for " << username << " at present." << endl;
        }
        else if (booksToRecommend > 5){
            cout << "Here is the list of recommendations" << endl;
            int counter = 0;
            while(counter < 5){
                cout << booksRecommend[counter].getTitle() << " by " << booksRecommend[counter].getAuthor() << endl;
                counter ++;
            }
        }
        else{
            cout << "Here is the list of recommendations" << endl;
            for (int i = 0; i < booksToRecommend; i++){
                cout << booksRecommend[i].getTitle() << " by " << booksRecommend[i].getAuthor() << endl;
            }
        }
    }
}
