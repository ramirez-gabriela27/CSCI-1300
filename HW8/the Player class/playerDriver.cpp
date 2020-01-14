// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 8 - Problem # 2

#include <iostream>
#include <string>
#include "Player.h"
#include "Player.cpp"

using namespace std;

main(){
    cout << "Test Cases" << endl;

    cout << "==============================" << endl;
    Player playerTest1 = Player();
    // should be blank
    cout << "The default name for player 1 is: " << playerTest1.getName() << endl;
    // should be 0
    cout << "The default points for player 1 are: " << playerTest1.getPoints() << endl;

    cout << endl;

    cout << "Please enter a name: ";
    string nameIn;
    cin >> nameIn;
    cout << "Please enter points: ";
    double pointsIn;
    cin >> pointsIn;

    Player playerTest2 = Player(nameIn,pointsIn);
    // should be whatever the input is
    cout << "The name initialized for player 2 is: " << playerTest2.getName() << endl;
    // should be whatever the input is
    cout << "The points initialized for player 2 are: " << playerTest2.getPoints() << endl;

    // set the user name to Emma
    playerTest2.setName("Emma");
    // set the points to 5.3
    playerTest2.setPoints(5.3);

    cout << "After being updated..." << endl;
    // should be Emma
    cout << "The name initialized for player 2 is: " << playerTest2.getName() << endl;
    // should be 5.3
    cout << "The points initialized for player 2 are: " << playerTest2.getPoints() << endl;

    return 0;
    
}
