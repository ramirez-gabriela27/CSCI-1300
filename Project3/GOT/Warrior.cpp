#include <string>
#include "Warrior.h"
using namespace std;

// Default constructor
Warrior::Warrior(){
    name = "";
    strength = 0;
    loyalty = 0;
    morale = 0;
    free = true;
    ship = false;
    dragonglass = false;
    locationRow = -1;
    locationColumn = -1;
}

// Parameterized constructor
Warrior::Warrior(string nameIn, int strengthIn, int loyaltyIn, int moraleIn, bool freeIn, bool shipIn, bool dragonglassIn){
    name = nameIn;
    strength = strengthIn;
    loyalty = loyaltyIn;
    morale = moraleIn;
    free = freeIn;
    ship = shipIn;
    dragonglass = dragonglassIn;
}

////////////////////////////////////GETTERS/////////////////////////////////////
/*
    GET the name of the warrior
    @param N/A
    @return name (string) - name of warrior
*/
string Warrior::getName(){
    return name;
}
/*
    GET the strength of the warrior
    @param N/A
    @return strength (int) - strength of warrior
*/
int Warrior::getStrenght(){
    return strength;
}
/*
    GET the loyalty of the warrior
    @param N/A
    @return loyalty (int) - loyalty of warrior
*/
int Warrior::getLoyalty(){
    return loyalty;
}
/*
    GET the morale of the warrior
    @param N/A
    @return morale (int) - morale of warrior
*/
int Warrior::getMorale(){
    return morale;
}
/*
    GET the free "status" of the warrior
    @param N/A
    @return free (bool) - is the warrior free or not
*/
bool Warrior::getFreeYN(){
    return free;
}
/*
    GET the ship "status" of the warrior
    @param N/A
    @return ship (bool) - does the warrior have a ship or not
*/
bool Warrior::getShipYN(){
    return ship;
}
/*
    GET the dragonglass "status" of the warrior
    @param N/A
    @return dragonglass (bool) - does the warrior have it or not
*/
bool Warrior::getDragonglassYN(){
    return dragonglass;
}
/*
    GET the row of the location of the warrior
    @param N/A
    @return locationRow(int) - row
*/
int Warrior::getLocationRow(){
    return locationRow;
}
/*
    GET the column of the location of the warrior
    @param N/A
    @return locationColumn(int) - column
*/
int Warrior::getLocationColumn(){
    return locationColumn;
}
////////////////////////////////////GETTERS/////////////////////////////////////

////////////////////////////////////SETTERS/////////////////////////////////////
/*
    SET the warrior's name
    @param nameIn (string) - the warrior's name
    @return N/A
*/
void Warrior::setName(string nameIn){
    name = nameIn;
}
/*
    SET the warrior's strength
    @param strengthIn (int) - the warrior's strength
    @return N/A
*/
void Warrior::setStrenght(int strengthIn){
    strength = strengthIn;
}
/*
    SET the warrior's loyalty
    @param loyaltyIn (int) - the warrior's loyalty
    @return N/A
*/
void Warrior::setLoyalty(int loyaltyIn){
    loyalty = loyaltyIn;
}
/*
    SET the warrior's morale
    @param moraleIn (int) - the warrior's morale
    @return N/A
*/
void Warrior::setMorale(int moraleIn){
    morale = moraleIn;
}
/*
    SET the warrior's free "status"
    @param freeIn (bool) - is the warrior free or not
    @return N/A
*/
void Warrior::setFreeYN(bool freeIn){
    free = freeIn;
}
/*
    SET the warrior's ship"status"
    @param shipIn (bool) - does the warrior have it or not
    @return N/A
*/
void Warrior::setShipYN(bool shipIn){
    ship = shipIn;
}
/*
    SET the warrior's dragonglass "status"
    @param dragonglassIn (bool) - does the warrior have it or not
    @return N/A
*/
void Warrior::setDragonglassYN(bool dragonglassIn){
    dragonglass = dragonglassIn;
}
/*
    SET the warriors location
    @param locationIn (int array) - (row, column)
    @return N/A
*/
void Warrior::setLocation(int locationIn[2]){
    locationRow = locationIn[0];
    locationColumn = locationIn[1];
}
////////////////////////////////////SETTERS/////////////////////////////////////
