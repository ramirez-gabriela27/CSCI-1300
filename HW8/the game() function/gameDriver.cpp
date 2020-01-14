// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 8 - Problem # 4

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Player.h"
#include "Team.h"

#include "Player.cpp"
#include "Team.cpp"

using namespace std;

/*
    determine the winnerof a game based on the points they accumulate
    @param team1 (Team) - team object with 1st set of players
    @param team2 (Team) - team object with 2nd set of players
    @return winner (string) - the name of the winner of the game
*/
string game(Team team1, Team team2){
    string winner = "";

    // if one or both teams do not have 4 or more players, return forfit
    if(team1.getNumPlayers() < 4 || team2.getNumPlayers() < 4){
        return "forfeit";
    }
    // if they have the same points, its a draw
    // otherwise, add up points for the first 4 players in each team
    else{
        int totalTeam1 = 0;
        int totalTeam2 = 0;

        for(int i = 0; i < 4; i++){
            double points1 = team1.getPlayerPoints(i);
            double points2 = team2.getPlayerPoints(i);
            totalTeam1 = totalTeam1 + points1;
            totalTeam2 = totalTeam2 + points2;
        }

        if(totalTeam1 == totalTeam2){
            return "draw";
        }
        else if(totalTeam1 > totalTeam2){
            winner = team1.getTeamName();
        }
        else{
            winner = team2.getTeamName();
        }

    }
    return winner;
}

main(){
    cout << "Test based on the 2 given rosters: " << endl;

    Team team1("Team 1");
    team1.readRoster("roster1.txt");

    Team team2("Team 2");
    team2.readRoster("roster2.txt");

    string winner = game(team1, team2);

    // expected output
    // The winner is: Team 1
    cout << "The winner is: " << winner << endl;

}
