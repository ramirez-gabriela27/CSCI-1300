#include <string>
#include "Tile.h"
using namespace std;

// Default constructor
Tile::Tile(){
    type = "";
    letter = "";
    name = "";
    money = 0;
    armySize = 0;
    points = 0;
    locationRow = -1;
    locationColumn = -1;
    dragonglass = false;
}

// Parameterized constructor
Tile::Tile(string typeIn, string letterIn, string nameIn, int moneyIn, int armySizeIn, int pointsIn, int locationRowIn, int locationColumnIn, bool dragonglassIn){
    type = typeIn;
    letter = letterIn;
    name = nameIn;
    money = moneyIn;
    armySize = armySizeIn;
    points = pointsIn;
    locationRow = locationRowIn;
    locationColumn = locationColumnIn;
    dragonglass = dragonglassIn;
}

////////////////////////////////////GETTERS/////////////////////////////////////
/*
    GET the type of tile
    @param N/A
    @return type (string) - type of tile
*/
string Tile::getType(){
    return type;
}
/*
    GET the designated letter
    @param N/A
    @return letter (string) - letter belonging to the Tile
*/
string Tile::getLetter(){
    return letter;
}
/*
    GET the name of the Tile
    @param N/A
    @return name (string) - name of the Tile
*/
string Tile::getName(){
    return name;
}
/*
    GET the amount of money
    @param N/A
    @return money (int) - amount of money of the Tile
*/
int Tile::getMoney(){
    return money;
}
/*
    GET the size of the army
    @param N/A
    @return armySize (int) - amount size of the army
*/
int Tile::getArmySize(){
    return armySize;
}
/*
    GET the points
    @param N/A
    @return money (int) - amount of points the Tile is worth
*/
int Tile::getPoints(){
    return points;
}
/*
    GET the row of the location of the tile
    @param N/A
    @return locationRow(int) - row
*/
int Tile::getLocationRow(){
    return locationRow;
}
/*
    GET the column of the location of the tile
    @param N/A
    @return locationColumn(int) - column
*/
int Tile::getLocationColumn(){
    return locationColumn;
}
/*
    GET the dragonglass status of the tile
    @param N/A
    @return dragonglass (bool) - is there dragonglass there or not
*/
bool Tile::getDragonglassYN(){
    return dragonglass;
}
////////////////////////////////////GETTERS/////////////////////////////////////

////////////////////////////////////SETTERS/////////////////////////////////////
/*
    SET the Tile's type
    @param typeIn (string) - the Tile's type
    @return N/A
*/
void Tile::setType(string typeIn){
    type = typeIn;
}
/*
    SET the Tile's letter
    @param letterIn (string) - the Tile's letter
    @return N/A
*/
void Tile::setLetter(string letterIn){
    letter = letterIn;
}
/*
    SET the Tile's name
    @param nameIn (string) - the Tile's name
    @return N/A
*/
void Tile::setName(string nameIn){
    name = nameIn;
}
/*
    SET the tile's money
    @param moneyIn (int) - the Tile's money
    @return N/A
*/
void Tile::setMoney(int moneyIn){
    money = moneyIn;
}
/*
    SET the Tile's army size
    @param armySizeIn (int) - the Tile's army size
    @return N/A
*/
void Tile::setArmySize(int armySizeIn){
    armySize = armySizeIn;
}
/*
    SET the Tile's points
    @param pointsIn (int) - the amount of points the Tile is worth
    @return N/A
*/
void Tile::setPoints(int pointsIn){
    points = pointsIn;
}
/*
    SET the Tile's location
    @param locationIn (int array) - (row, column)
    @return N/A
*/
void Tile::setLocation(int locationIn[2]){
    locationRow = locationIn[0];
    locationColumn = locationIn[1];
}
/*
    SET the Tile's dragonglass status
    @param dragonglassIn(bool) - is it there or not
    @return N/A
*/
void Tile::setDragonglassYN(bool dragonglassIn){
    dragonglass = dragonglassIn;
}
////////////////////////////////////SETTERS/////////////////////////////////////
