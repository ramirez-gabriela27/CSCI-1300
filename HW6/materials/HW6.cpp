// CSCI1300 Spring 2019
// Author: <Your name>
// Recitation: <123> – <Your TA name>
// Cloud9 Workspace Editor Link: <https://ide.c9.io/ .....>
// hmwk6 


#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;


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
// your readBooks function goes here
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
 // your readBooks function goes here
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
// your printAllBooks function goes here
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
// your getRating function goes here
//////////////////////////////////////////////////////////////////////////


 //////////////////////////////////////////////////////////////////////////
 // other helper functions
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
    string choice;
    int numBooks = 0;
    int numUsers = 0;

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
                
                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
                //////////////////////////////////////////////////////////////////////////

                // Use the below messages and match them to the return code. Redefine variables as needed.
                // cout << "No books saved to the database" << endl;
                // cout << "Database is already full. No books were added" << endl; 
                // cout << "Database is full" << endl; 
                // cout << "Total books in the database: " << numBooks << endl;
                
                cout << endl;
                break;

            case 2:
                // read ratings file
                cout << "Enter a raitng file name:" << endl;

                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
                //////////////////////////////////////////////////////////////////////////

                // Use the below messages and match them to the return code. Redefine variables as needed.
                // cout << "No users saved to database" << endl;
                // cout << "Database is already full. No ratings were added" << endl; 
                // cout << "Database is full" << endl; 
                // cout << "Total users in the database: " << numUsers << endl;
                
                cout << endl;
                break;

            case 3:
                // print the list of the books
                
                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
                //////////////////////////////////////////////////////////////////////////

                cout << endl;
                break;

            case 4:
            	// get user's rating 
                // take user name
                cout << "Enter username:" << endl;

                // take book title 
                cout << "Enter book title:" << endl;

                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
                //////////////////////////////////////////////////////////////////////////
                
                // Use the below messages and match them to the return code. Redefine variables as needed.
                // cout << userName << " has not rated " << bookTitle << endl; 
                // cout << userName << " or " << bookTitle << " does not exist" << endl; 
                // cout << userName << " rated " << bookTitle << " with " << rate << endl; 

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
