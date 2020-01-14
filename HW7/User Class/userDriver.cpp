// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 7 - Problem # 4

#include <iostream>
#include <string>
#include "User.h"
using namespace std;

main(){
    cout << endl << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // All of the ratings in the input array
    int ratings[] = {3,1,5,2,1,3,5,0,1,4,0,4,0,2,4,1,4,5,1,5,0,3,0,4,3,1,0,2,1,5,0,3,2,1,2,1,4,2,2,5,3,2,5,4,2,1,3,1,4,2,2,1,3,3,1};
    User user1 = User("john", ratings, 50);

    cout << "username: " << user1.getUsername() << endl;
    cout << "number of ratings: " << user1.getNumRatings() << endl;

    for(int i = 0; i < 50; i++){
        cout << user1.getRatingAt(i) << endl;
    }

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // print 2
    user1.setRatingAt(17, 2);
    cout << user1.getRatingAt(17);

    return 0;
}
