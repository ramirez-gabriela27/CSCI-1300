// Player class to create player objects
// with the name, points, and designated hero, during game
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Hero.h"     //player will chose a hero or create one
#include "Warrior.h"  //hero may or may not have warriors
using namespace std;

class Player{
private:
    string name;
    Hero hero;
    double points;
    int turn;

public:
    // constructors
    Player();
    Player(string name, int points, Hero heroIn);

    // getters
    string getName();
    double getPoints();
    int getTurn();
    Hero getHero();

    // setters
    void setName(string nameIn);
    void setPoints(double pointsIn);
    void setTurn();
    void setHero(Hero heroIn);
};

#endif
