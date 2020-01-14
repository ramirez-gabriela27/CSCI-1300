#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player{
private:
    string name;
    double points;
public:
    Player();                               // Default constructor
    Player(string nameIn, double pointsIn); // Parameterized constructor

    string getName();                       // getter
    double getPoints();                     // getter
    void setName(string nameIn);            // setter
    void setPoints(double pointsIn);        // setter
};

#endif
