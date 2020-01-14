#include <iostream>
#include <math.h>
#include <string>
#include "planet.h"
using namespace std;

// Default constructor
Planet::Planet(){
    planetName = "";
    planetRadius = 0.0;
}

// Parameterized constructor
Planet::Planet(string name, double radius){
    planetName = name;
    planetRadius = radius;
}

/*
    GET the planet's name
    @param N/A
    @return planetName (string) - the name of the planet
*/
string Planet::getName(){
    return planetName;
}

/*
    SET the planet's name
    @param name (string) - the name input
    @return N/A
*/
void Planet::setName(string name){
    planetName = name;
}

/*
    GET the planet's radius
    @param N/A
    @return planetRadius (double) - the radius of the planet
*/
double Planet::getRadius(){
    return planetRadius;
}

/*
    SET the planet's radius
    @param radius (double) - the radius input
    @return N/A
*/
void Planet::setRadius(double radius){
    planetRadius = radius;
}

/*
    GET the planet's volume
    @param N/A
    @return volume (double) - the volume of the planet
*/
double Planet::getVolume(){
    double volume = 0.0;
    volume = (4.0/3.0) * M_PI * pow(planetRadius,3);
    return volume;
}
