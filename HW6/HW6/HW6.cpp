// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 6 - Problem # 9

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
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

//////////////////////////////////////////////////////////////////////////
// other helper functions... split
//////////////////////////////////////////////////////////////////////////


/* readBooks function
 * the function reads a book file from the text into book and author arrays
 *
 * @param: fileName, string, name of the book file
 * @param: titles, string array, titles of the books are stored
 * @param: authors, string array, authors of the books are stored
 * @param: numBookStored, int, the number of books currently stored in the arrays
 * @param: size, int, the size of the arrays (titles and authors)
 * @return: the number of books read into the array (number of lines in the file)
 *          or appropriate return code
 */

//////////////////////////////////////////////////////////////////////////
// ToDo: implement readBooksfunction
int readBooks(string fileName, string titles[], string authors[], int numBookStored, int size){

    // open file to read
    ifstream inFile;
    inFile.open(fileName);

    //When file isn't opened successfully return -1
    if (inFile.fail()) {
        return -1;
    }
    //When the array is full return -2
    if (numBookStored == size){
        return -2;
    }

    string line;
    string messageSubstrings[2];

    if (numBookStored < size){
        while(getline(inFile,line) && numBookStored < size){
            // if the line is empty, skip it
            if (line.empty()) continue;
            split(line, ',', messageSubstrings,2);
            authors[numBookStored] = messageSubstrings[0];
            titles[numBookStored] = messageSubstrings[1];
            numBookStored ++;
        }
    }
    else{
        numBookStored = 0;
        while(getline(inFile,line) && numBookStored < size){
            // if the line is empty, skip it
            if (line.empty()) continue;
            split(line, ',', messageSubstrings,2);
            authors[numBookStored] = messageSubstrings[0];
            titles[numBookStored] = messageSubstrings[1];
            numBookStored ++;
        }
    }
    return numBookStored;
}
//////////////////////////////////////////////////////////////////////////


/* readRatings function
 * Read the user ratings from the file and store them
 * into users array and ratings array
 *
 * @param: fileName, string, the name of user rating file
 * @param: users, string array, the array of users
 * @param: ratings, int 2D array, the ratings of each user
 *         row i is user, and column j is a book.
 *         ratings[i][j] is the user_i rated book_j
 * @param: numUsers, int, the number of users currently stored in the array
 * @param: sizeRow, int, the number of rows in the 2D array (capacity)
 * @param: sizeCol, int, the number of column in the 2D array (capacity)
 * @return: the number of users in total or appropriate return code
 */

 //////////////////////////////////////////////////////////////////////////
 // ToDo: implement readRatings function
 int readRatings (string fileName, string users[], int ratings[][50], int numUsers, int maxRows, int maxColumns){
     // open file to read
     ifstream inFile;
     inFile.open(fileName);

     //When file isn't opened successfully return -1
     if (inFile.fail()) {
         return -1;
     }
     //When the array is "full" return -2
     else if (numUsers >= maxRows){
         return -2;
     }
     else{
         string line;
         string substrings[maxColumns];

         while(getline(inFile,line) && numUsers < maxRows){
             // if line is empty, skip it
             if(line.empty()) continue;

             int numSub = split(line,',',substrings,maxColumns+1);

             users[numUsers] = substrings[0];

             for (int j = 0; j<numSub; j++){
                 if(substrings[j+1] == "")break;
                 else{
                     ratings[numUsers][j] = stoi(substrings[j+1]);
                 }
             }
             numUsers ++;
         }
     }
     return numUsers;
 }
 //////////////////////////////////////////////////////////////////////////

/* printBookList function (helper function)
 * print the list of books in the array
 *
 * @param: titles, string, the title of books
 * @param: authors, string, the author of books
 * @param: numBooks, int, the number of books
 * @return: void
 */
//////////////////////////////////////////////////////////////////////////
// ToDo: implement printAllBooks function
void printAllBooks(string titles[], string authors[], int numBookStored){
    if (numBookStored <=0){
        cout << "No books are stored" << endl;
    }
    else{
        cout << "Here is a list of books" << endl;
        for (int i = 0; i<numBookStored; i++){
            cout << titles[i] << " by " << authors [i] << endl;
        }
    }
}
//////////////////////////////////////////////////////////////////////////

/* getRating function
 * Search for a rating given the user's name and
 * book's title and return that value
 *
 * @param: string, username
 * @param: string, title of the book
 * @param: string, array, user names
 * @param: string, array, titles
 * @param: 2D int array, list of ratings for each user
 * @param: int, number of users whose names/ratings are currently
 *         stored in the string array/2D array respectively
 * @param: int, number of books whose titles/ratings are currently
 *         stored in the string array/2D array respectively
 * @return: int, users's rating value or appropriate return code
 */

//////////////////////////////////////////////////////////////////////////
// ToDo: implement getRating function
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
                string titles[bookArrSize];
                string authors[bookArrSize];
                numBooks = readBooks(bookFileName,titles,authors,numBooks,bookArrSize);
                //////////////////////////////////////////////////////////////////////////

                if(numBooks == -1){
                    cout << "No books saved to the database." << endl;
                }
                else if (numBooks == -2){
                    cout << "Database is already full. No books were added." << endl;
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
                string users[userArrSize];
                int ratings[bookArrSize][userArrSize];
                numUsers = readRatings(userFileName,users,ratings,numUsers,bookArrSize,userArrSize);
                //////////////////////////////////////////////////////////////////////////
                if(numUsers == -1){
                    cout << "No users saved to the database." << endl;
                }
                else if (numUsers == -2){
                    cout << "Database is already full. No users were added." << endl;
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
                numBooks = readBooks(bookFileName,titles,authors,numBooks,bookArrSize);
                printAllBooks(titles, authors, numBooks);
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
                numBooks = readBooks(bookFileName,titles,authors, numBooks, bookArrSize);
                numUsers = readRatings(userFileName,users,ratings,numUsers,bookArrSize,userArrSize);
                int rate = getRating(userName,bookTitle,users,titles,ratings,numUsers,numBooks);
                //////////////////////////////////////////////////////////////////////////
                if(rate == 0){
                    cout << userName << " has not rated " << bookTitle << endl;
                }
                else if (rate == -3){
                    cout << userName << " or " << bookTitle << " does not exist" << endl;
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
