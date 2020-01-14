#ifndef TEAM_H
#define TEAM_H

#include <string>
#include <vector>
#include "Player.h"
using namespace std;

class Team{
private:
    string teamName;
    vector<Player> players;                         // vector of players (objects)
public:
    Team();                                         // Default constructor
    Team(string teamNameIn);                        // Parameterized constructor

    void setTeamName(string teamNameIn);            // setter
    void readRoster(string fileName);               // setter
    string getPlayerName(int position);             // getter
    double getPlayerPoints(int position);           // getter
    int getNumPlayers();                            // getter
    string getTeamName();                           // getter
};

#endif
