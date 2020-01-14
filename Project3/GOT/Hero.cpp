#include <string>
#include <vector>
#include "Warrior.h"
using namespace std;


// Default constructor
Hero::Hero(){
    name = "";
    money = 0;
    influence = 0;
    armySize = 0;
    row = "";
    column = "";
    ship = false;
    dragonglass = false;
}

// Parameterized constructor
Hero::Hero(string nameIn, int moneyIn, int influenceIn, int armySizeIn, vector<Warrior>warriorsIn, string rowIn, string columnIn, bool shipIn, bool dragonglassIn){
    name = nameIn;
    money = moneyIn;
    influence = influenceIn;
    armySize = armySizeIn;
    warriors = warriorsIn;
    row = rowIn;
    column = columnIn;
    ship = shipIn;
    dragonglass = dragonglassIn;
}

////////////////////////////////////GETTERS/////////////////////////////////////
/*
    GET the name of the hero
    @param N/A
    @return name (string) - name of hero
*/
string Hero::getName(){
    return name;
}
/*
    GET the hero's money
    @param N/A
    @return money (int) - hero's money
*/
int Hero::getMoney(){
    return money;
}
/*
    GET the hero's influence
    @param N/A
    @return influence (int) - hero's influence
*/
int Hero::getInfluence(){
    return influence;
}
/*
    GET the hero's army's size
    @param N/A
    @return armySize (int) - hero's army's size
*/
int Hero::getArmySize(){
    return armySize;
}
/*
    GET the hero's warriors
    @param N/A
    @return warriors (vector) - hero's warriors
*/
vector<Warrior> Hero::getWarriors(){
    return warriors;
}
/*
    GET the hero's location(row)
    @param N/A
    @return row (string) - hero's location(row)
*/
string Hero::getLocationRow(){
    return row;
}
/*
    GET the hero's location(column)
    @param N/A
    @return column (string) - hero's location(column)
*/
string Hero::getLocationColumn(){
    return column;
}
/*
    GET the ship "status" of the hero
    @param N/A
    @return ship (bool) - does the hero have a ship or not
*/
bool Hero::getShipYN(){
    return ship;
}
/*
    GET the dragonglass "status" of the hero
    @param N/A
    @return dragonglass (bool) - does the hero have it or not
*/
bool Hero::getDragonglassYN(){
    return dragonglass;
}
////////////////////////////////////GETTERS/////////////////////////////////////

////////////////////////////////////SETTERS/////////////////////////////////////
/*
    SET the hero's name
    @param nameIn (string) - the hero's name
    @return N/A
*/
void Hero::setName(string nameIn){
    name = nameIn;
}
/*
    SET the hero's money
    @param moneyIn (int) - the hero's money
    @return N/A
*/
void Hero::setMoney(int moneyIn){
    money = moneyIn;
}
/*
    SET the hero's army's size
    @param armySizeIn (int) - the hero's army's size
    @return N/A
*/
void Hero::setArmySize(int armySizeIn){
    armySize = armySizeIn;
}
/*
    SET the hero's warriors
    @param warriorsIn (vector) - hero's warriors
    @return N/A
*/
void Hero::assignWarriors(vector<Warrior> warriorsIn){
    warriors = warriorsIn;
}
/*
    SET the hero's location(row)
    @param rowIn (string) - hero's location(row)
    @return N/A
*/
void Hero::setLocationRow(string rowIn){
    row = rowIn;
}
/*
    SET the hero's location(column)
    @param columnIn (string) - hero's location(column)
    @return N/A
*/
void Hero::setLocationColumn(string columnIn){
    column = columnIn;
}
/*
    SET the hero's ship"status"
    @param shipIn (bool) - does the hero have it or not
    @return N/A
*/
void Hero::setShipYN(bool shipIn){
    ship = shipIn;
}
/*
    SET the hero's dragonglass "status"
    @param dragonglassIn (bool) - does the hero have it or not
    @return N/A
*/
void Hero::setDragonglassYN(bool dragonglassIn){
    dragonglass = dragonglassIn;
}
////////////////////////////////////SETTERS/////////////////////////////////////
