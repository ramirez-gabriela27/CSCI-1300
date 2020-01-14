#include <iostream>
#include <string>
#include "Player.h"
using namespace std;

// Default constructor
Player::Player(){
    name = "";
    points = 0.0;
}

// Paramaterized constructor
Player::Player(string nameIn, double pointsIn){
    name = nameIn;
    points = pointsIn;
}

/*
    GET the player's name
    @param N/A
    @return name (string) - the player's name
*/
string Player:: getName(){
    return name;
}

/*
    GET the player's points
    @param N/A
    @return points (double) - the player's points
*/
double Player:: getPoints(){
    return points;
}

/*
    SET the player's name
    @param nameIn (string) - the player's name
    @return N/A
*/
void Player::setName(string nameIn){
    name = nameIn;
}

/*
    SET the player's points
    @param pointsIn (string) - the player's points
    @return N/A
*/
void Player::setPoints(double pointsIn){
    points = pointsIn;
}
