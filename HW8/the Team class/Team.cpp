#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Player.h"
#include "Team.h"

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
// HELPER FUNCTIONS //

// Default constructor
Team::Team(){
    teamName = "";
    vector<Player> players;
}

// Paramaterized constructor
Team::Team(string teamNameIn){
    teamName = teamNameIn;
    vector <Player> players;
}

/*
    SET the team's name
    @param teamNameIn (string) - the team's name
    @return N/A
*/
void Team::setTeamName(string teamNameIn){
    teamName = teamNameIn;
}

/*
    SET the players vector
    @param fileName (string) - name of file from which the player objects are created
    @return N/A
*/
void Team::readRoster(string fileName){
    // open file to read
    ifstream inFile;
    inFile.open(fileName);

    string line;
    string messageSubstrings[2];

    while(getline(inFile,line)){
        split(line, ',', messageSubstrings,2);

        // create player objects based on input from file
        Player playerIn = Player(messageSubstrings[0], stod(messageSubstrings[1]));
        players.push_back(playerIn);
    }

    // close file
    inFile.close();
}

/*
    GET the player's name at a given location
    @param N/A
    @return name (string) - the player's name
*/
string Team::getPlayerName(int position){
    if(position >= players.size() || position < 0){
        return "ERROR";
    }
    else{
        string name = players[position].getName();
        return name;
    }
}

/*
    GET the player's points at a given location
    @param N/A
    @return points (double) - the player's points
*/
double Team::getPlayerPoints(int position){
    if(position >= players.size() || position < 0){
        return -1;
    }
    else{
        double points = players[position].getPoints();
        return points;
    }
}

/*
    GET the number of players in the vector
    @param N/A
    @return numPlayers (int) - the number of players in the vector
*/
int Team::getNumPlayers(){
    int numPlayers = players.size();
    return numPlayers;
}

/*
    GET the team name
    @param N/A
    @return teamName (string) - the team name
*/
string Team::getTeamName(){
    return teamName;
}
