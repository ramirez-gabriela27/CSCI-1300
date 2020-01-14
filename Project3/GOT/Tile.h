/*
    class for tiles on the map (Cities, Land, Water)
    makes displaying the map a lot easier
    also makes it easier for the driver to keep track of points and who conquers
    what.
*/

#ifndef TILE_H
#define TILE_H

#include <string>
using namespace std;

class Tile{
private:
    // is it water, land or a city
    string type;
    // the character by which it is identified
    string letter;
    // if its a city, has actual name
    // else, it has a blank string for the name
    string name;
    int money;
    int armySize;
    int points;
    int locationRow;
    int locationColumn;
    // the tile can have the dragonglass hidden in it
    bool dragonglass;

public:
    // constructors
    Tile();
    Tile(string typeIn, string letterIn, string nameIn, int moneyIn, int armySizeIn, int pointsIn, int locationRowIn, int locationColumnIn, bool dragonglassIn);

    // getters
    string getType();
    string getLetter();
    string getName();
    int getMoney();
    int getArmySize();
    int getPoints();
    int getLocationRow();
    int getLocationColumn();
    bool getDragonglassYN();

    // setters
    void setType(string typeIn);
    void setLetter(string letterIn);
    void setName(string nameIn);
    void setMoney(int moneyIn);
    void setArmySize(int armySizeIn);
    void setPoints(int pointsIn);
    void setLocation(int locationIn[2]);
    void setDragonglassYN(bool dragonglassIn);
};

#endif
