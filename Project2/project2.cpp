#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>

#include "Book.h"
#include "User.h"
#include "Library.h"

#include "Book.cpp"
#include "User.cpp"
#include "Library.cpp"

using namespace std;

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
	cout << "5. Find number of books user rated" << endl;
	cout << "6. View ratings" << endl;
	cout << "7. Get average rating" << endl;
	cout << "8. Add a user" << endl;
	cout << "9. Checkout a book" << endl;
	cout << "10. Get recommendations" << endl;
	cout << "11. Quit" << endl;
}

int main(int argc, char const *argv[]) {


	// temp variables
    string choice;
    string bookFileName;
    string userFileName;
    string userName, bookTitle;
    string strRating;

	Library libraryIn = Library();
	int numBooks = libraryIn.getNumBooks();
	int numUsers = libraryIn.getNumUsers();
	int addUseRet = 0;
	int rate = 0;
	int checkBook = 0;

    while (choice != "11") {
        displayMenu();

        // take a menu opton
        getline(cin, choice);

        // convert the `choice` to an integer
        int menuChoice = stoi(choice);

        switch (menuChoice) {

            case 1:
                // Initialize library -- readBooks
                cout << "Enter a book file name:" << endl;
                getline(cin, bookFileName);

                //////////////////////////////////////////////////////////////////////////
				numBooks = libraryIn.readBooks(bookFileName);
                //////////////////////////////////////////////////////////////////////////

				if(numBooks == -2){
                    cout << "Database is already full. No books were added." << endl;
                }
                else if(numBooks == -1){
                    cout << "No books saved to the database." << endl;
                }
                else if(numBooks == libraryIn.getSizeBook()){
                    cout << "Database is full. Some books may have not been added." << endl;
                }
                else{
                    cout << "Total books in the database: " << numBooks << endl;
                }

			    cout << endl;
                break;

            case 2:
                //  Initialize user catalog -- readRatings

                cout << "Enter a user file name:" << endl;
                getline(cin, userFileName);


                //////////////////////////////////////////////////////////////////////////
                numUsers = libraryIn.readRatings(userFileName);
                //////////////////////////////////////////////////////////////////////////

				if(numUsers == -2){
                    cout << "Database is already full. No users were added." << endl;
                }
                else if(numUsers == -1){
                    cout << "No users saved to the database." << endl;
                }
                else if(numUsers == libraryIn.getSizeUser()){
                    cout << "Database is full. Some users may have not been added." << endl;
                }
                else{
                    cout << "Total users in the database: " << numUsers << endl;
                }

                cout << endl;
                break;

            case 3:
                // Display library -- printAllBooks

                //////////////////////////////////////////////////////////////////////////
				if(numBooks == 0 && numUsers == 0){
					cout << "Database has not been fully initialized." << endl;
				}
				else{
					libraryIn.printAllBooks();
				}
                //////////////////////////////////////////////////////////////////////////

				cout << endl;
                break;

            case 4:
                //  Get a rating -- getRating

                //////////////////////////////////////////////////////////////////////////
				if(numBooks == 0 && numUsers == 0){
					cout << "Database has not been fully initialized." << endl;
				}
				else{
					// take user name
					cout << "Enter username:" << endl;
					getline(cin, userName);

					// take book title
					cout << "Enter book title:" << endl;
					getline(cin, bookTitle);

					rate = libraryIn.getRating(userName, bookTitle);
					if(rate == -3){
                    	cout << userName << " or " << bookTitle << " does not exist." << endl;
	                }
	                else if(rate == 0){
	                    cout << userName << " has not rated " << bookTitle << endl;
	                }
	                else{
	                    cout << userName << " rated " << bookTitle << " with " << rate << endl;
	                }
				}
                //////////////////////////////////////////////////////////////////////////

                // Use the below messages and match them to the return code. Update variables as needed.

            	cout << endl;
                break;

            case 5:
                // Get number of books the user has rated -- getCountReadBooks

				if(numBooks == 0 && numUsers == 0){
					cout << "Database has not been fully initialized." << endl;
				}
				else{
					// take user name
					cout << "Enter username:" << endl;
					getline(cin, userName);

					int numRated = libraryIn.getCountReadBooks(userName);
					if(numRated == -3){
						cout << userName << " does not exist." << endl;
					}
					else if(numRated == 0){
						cout << userName << " has not rated any books." << endl;
					}
					else{
						cout << userName << " rated " << numRated << " books." << endl;
					}
				}

            	cout << endl;
                break;

            case 6:
                // View user’s ratings -- viewRatings

				if(numBooks == 0 && numUsers == 0){
					cout << "Database has not been fully initialized." << endl;
				}
				else{
					// take user name
					cout << "Enter username:" << endl;
					getline(cin, userName);

					libraryIn.viewRatings(userName);
				}

            	cout << endl;
                break;

            case 7:
                // Calculate the average rating for the book -- calcAvgRating

				if(numBooks == 0 && numUsers == 0){
					cout << "Database has not been fully initialized." << endl;
				}
				else{
	        		// take book title
	                cout << "Enter book title:" << endl;
	                getline(cin, bookTitle);

					double avgRating = libraryIn.calcAvgRating(bookTitle);
					if(avgRating == -3){
						cout << bookTitle << " does not exist." << endl;
					}
					else{
						cout << "The average rating for " << bookTitle << " is " << avgRating << endl;
					}
				}

                cout << endl;
                break;

            case 8:
                // Add a user to the database -- addUser
        		// take user name
                cout << "Enter username:" << endl;
                getline(cin, userName);

				addUseRet = libraryIn.addUser(userName);
				if(addUseRet == 1){
					cout << "Welcome to the library " << userName << endl;
				}
				else if(addUseRet == 0){
					cout << userName << " already exists in the database." << endl;
	       		}
				else{
					cout << "Database is already full. " << userName << " was not added." << endl;
				}

            	cout << endl;
                break;

            case 9:
                // Check out the book -- checkOutBook

				if(numBooks == 0 && numUsers == 0){
					cout << "Database has not been fully initialized." << endl;
				}
				else{
	        		// take user name
	                cout << "Enter username:" << endl;
	                getline(cin, userName);

	                // take book title
	                cout << "Enter book title:" << endl;
	                getline(cin, bookTitle);

	                // take rating
	                cout<<"Enter rating for the book:"<<endl;
	                getline(cin, strRating);

					checkBook = libraryIn.checkOutBook(userName, bookTitle, stoi(strRating));
					if(checkBook == 1){
						cout << "We hope you enjoyed your book. The rating has been updated." << endl;
					}
					else if(checkBook == -4){
						cout << strRating << " is not valid." << endl;
					}
					else{
						cout << userName << " or " << bookTitle << " does not exist." << endl;
					}
				}

            	cout << endl;
                break;

            case 10:
                // get recommendations  -- getRecommendations

				if(numBooks == 0 && numUsers == 0){
					cout << "Database has not been fully initialized." << endl;
				}
				else{
	        		// take user name
	                cout << "Enter username:" << endl;
	                getline(cin, userName);
					libraryIn.getRecommendations(userName);
				}

            	cout << endl;
                break;

            case 11:
                // quit
                cout << "good bye!" << endl;
                break;

            default:
                cout << "invalid input" << endl;
                cout << endl;
        }
    }

    return 0;
}
