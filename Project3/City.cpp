#include <string>
#include "City.h"
using namespace std;

// Default constructor
City::City(){
    letter = ' ';
    name = "";
    money = 0;
    armySize = 0;
    points = 0;
}

// Parameterized constructor
City::City(string letterIn, string nameIn, int moneyIn, int armySizeIn, int pointsIn){
    letter = letterIn;
    name = nameIn;
    money = moneyIn;
    armySize = armySizeIn;
    points = pointsIn;
}

/*
    GET the designated letter
    @param N/A
    @return letter (string) - letter belonging to the city
*/
string City::getLetter(){
    return letter;
}

/*
    GET the name of the city
    @param N/A
    @return name (string) - name of the city
*/
string City::getName(){
    return name;
}

/*
    GET the amount of money
    @param N/A
    @return money (int) - amount of money of the city
*/
int City::getMoney(){
    return money;
}

/*
    GET the size of the army
    @param N/A
    @return armySize (int) - amount size of the army
*/
int City::getArmySize(){
    return armySize;
}

/*
    GET the points
    @param N/A
    @return money (int) - amount of points the city is worth
*/
int City::getPoints(){
    return points;
}

/*
    SET the city's letter
    @param letterIn (string) - the city's letter
    @return N/A
*/
void City::setLetter(string letterIn){
    letter = letterIn;
}

/*
    SET the city's name
    @param nameIn (string) - the city's name
    @return N/A
*/
void City::setName(string nameIn){
    name = nameIn;
}

/*
    SET the citiy's money
    @param moneyIn (int) - the city's money
    @return N/A
*/
void City::setMoney(int moneyIn){
    money = moneyIn;
}

/*
    SET the city's army size
    @param armySizeIn (int) - the city's army size
    @return N/A
*/
void City::setArmySize(int armySizeIn){
    armySize = armySizeIn;
}

/*
    SET the city's points
    @param pointsIn (int) - the amount of points the city is worth
    @return N/A
*/
void City::setPoints(int pointsIn){
    points = pointsIn;
}
