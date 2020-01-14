// Warrior class to create player objects
// with the name, strength, loyalty, morale, freedom status, ship status, dragonglass status
#ifndef WARRIOR_H
#define WARRIOR_H

#include <string>
using namespace std;

class Warrior{
private:
    string name;
    int strength;
    int loyalty;
    int morale;
    bool free;
    bool ship;
    bool dragonglass;
    int locationRow;
    int locationColumn;

public:
    // constructors
    Warrior();
    Warrior(string nameIn, int strengthIn, int loyaltyIn, int moraleIn, bool freeIn, bool shipIn, bool dragonglassIn);

    // getters
    string getName();
    int getStrenght();
    int getLoyalty();
    int getMorale();
    bool getFreeYN();
    bool getShipYN();
    bool getDragonglassYN();
    int getLocationRow();
    int getLocationColumn();

    // setters
    void setName(string nameIn);
    void setStrenght(int strengthIn);
    void setLoyalty(int loyaltyIn);
    void setMorale(int moraleIn);
    void setFreeYN(bool freeIn);
    void setShipYN(bool shipIn);
    void setDragonglassYN(bool dragonglassIn);
    void setLocation(int locationIn[2]);
};

#endif
