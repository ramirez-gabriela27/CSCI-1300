#include <string>
#include <iostream>
#include <vector>
#include "Warrior.h"
#include "Hero.h"
using namespace std;

//Default constructor
Player::Player(){
    name = "";
    points = 0.0;
    turn = 0;
}

// Parameterized constructor
Player::Player(string nameIn, int pointsIn, Hero heroIn){
    name = nameIn;
    hero = heroIn;
    points = 0.0;
    turn = 0;
}

////////////////////////////////////GETTERS/////////////////////////////////////
/*
    GET the name of the player
    @param N/A
    @return name (string) - name of player
*/
string Player::getName(){
    return name;
}
/*
    GET the player's points
    @param N/A
    @return points (int) - player's points
*/
double Player::getPoints(){
    return points;
}
/*
    GET the player's turn number
    @param N/A
    @return turn (int) - players turn number
*/
int Player::getTurn(){
    return turn;
}
/*
    GET the player's hero
    @param N/A
    @return hero (Hero) - player's hero
*/
Hero Player::getHero(){
    return hero;
}
////////////////////////////////////GETTERS/////////////////////////////////////

////////////////////////////////////SETTERS/////////////////////////////////////
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
    @param pointsIn (int) - the player's points
    @return N/A
*/
void Player::setPoints(double pointsIn){
    points = pointsIn;
}
/*
    SET the player's hero
    @param heroIn (Hero) - the player's hero
    @return N/A
*/
void Player::setHero(Hero heroIn){
    hero = heroIn;
}
/*
    SET the player's turn number (adding 1)
    @param N/A
    @return N/A
*/
void Player::setTurn(){
    turn++;
}
////////////////////////////////////SETTERS/////////////////////////////////////
