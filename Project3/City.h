// City class to create class objects
// with the letter, name, money, army size, the points it's worth
#ifndef CITY_H
#define CITY_H

#include <string>
using namespace std;

class City{
private:
    string letter;
    string name;
    int money;
    int armySize;
    int points;

public:
    //constructors
    City();
    City(string letterIn, string nameIn, int moneyIn, int armySizeIn, int pointsIn, bool dragonglassIn);

    // getters
    string getLetter();
    string getName();
    int getMoney();
    int getArmySize();
    int getPoints();

    // setters
    void setLetter(string letterIn);
    void setName(string nameIn);
    void setMoney(int moneyIn);
    void setArmySize(int armySizeIn);
    void setPoints(int pointsIn);
};

#endif
