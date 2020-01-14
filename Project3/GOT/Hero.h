// Warrior class to create player objects
// with the name, strength, loyalty, morale, freedom status, ship status, dragonglass status
#ifndef HERO_H
#define HERO_H

#include <string>
#include <vector>
#include "Warrior.h"
using namespace std;

class Hero{
private:
    string name;
    int money;
    int influence;
    int armySize;
    vector<Warrior> warriors;
    string row;
    string column;
    bool ship;
    bool dragonglass;

public:
    // constructors
    Hero();
    Hero(string nameIn, int moneyIn, int influenceIn, int armySizeIn, vector<Warrior>warriors, string rowIn, string columnIn, bool shipIn, bool dragonglassIn);

    // getters
    string getName();
    int getMoney();
    int getInfluence();
    int getArmySize();
    vector<Warrior> getWarriors();
    string getLocationRow();
    string getLocationColumn();
    bool getShipYN();
    bool getDragonglassYN();

    //setters
    void setName(string nameIn);
    void setMoney(int moneyIn);
    void setArmySize(int armySizeIn);
    void assignWarriors(vector<Warrior> warriors);
    void setLocationRow(string rowIn);
    void setLocationColumn(string columnIn);
    void setShipYN(bool shipIn);
    void setDragonglassYN(bool dragonglassIn);
};

#endif
