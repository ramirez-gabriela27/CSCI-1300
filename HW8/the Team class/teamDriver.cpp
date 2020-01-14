// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 8 - Problem # 3

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Player.h"
#include "Team.h"

#include "Player.cpp"
#include "Team.cpp"

using namespace std;

main(){
    cout << "Test Cases" << endl;

    cout << "==============================" << endl;
    Team teamTest = Team();
    //should be blank
    cout << "The default name for the team is: " << teamTest.getTeamName() << endl;

    cout << endl;

    cout << "Please enter a team name: " << endl;
    string teamNameIn;
    getline(cin,teamNameIn);

    Team teamTest2 = Team(teamNameIn);
    // should be whatever the input is
    cout << "The team name initialized is: " << teamTest2.getTeamName() << endl;

    // set the team name to "Clever Team Name"
    teamTest2.setTeamName("Clever Team Name");
    // read the rosters to fill vector of players
    teamTest2.readRoster("roster1.txt");
    teamTest2.readRoster("roster2.txt");

    cout << "After reading both rosters, here is a list of players and points: " << endl;
    for (int i = 0; i < teamTest2.getNumPlayers(); i++){
        cout << teamTest2.getPlayerName(i) << " ";
        cout << teamTest2.getPlayerPoints(i) << endl;
    }
}
