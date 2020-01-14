#ifndef PLANET_H
#define PLANET_H

#include <string>
using namespace std;

class Planet{
private:
    string planetName;
    double planetRadius;

public:
    Planet();                                // Default constructor
    Planet(string name, double radius);      // Parameterized constructor

    string getName();                        // getter
    void setName(string name);               // setter
    double getRadius();                      // getter
    void setRadius(double radius);           // setter
    double getVolume();                      // getter
};

#endif
