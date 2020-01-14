// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 7 - Problem # 1

#include <iostream>
#include <math.h>
#include <string>
#include "Planet.h"
using namespace std;

int main(){
    Planet test;
    cout << "Please enter the name of the planet: " << endl;
    string name = "";
    getline(cin, name);

    cout << "Please enter the radius of the planet (in Km): " << endl;
    int radius = 0.0;
    cin >> radius;

    test.setName(name);
    test.setRadius(radius);

    cout << "The planet " << test.getName() << " with radius " << test.getRadius() << " Km has volume " << test.getVolume() << " Km^3" << endl;

    cout << endl << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // The planet Mars with radius 3389.5 Km has volume 1.6316*10^11
    Planet testCase1("Mars",3389.5);
    cout << "The planet " << testCase1.getName() << " with radius " << testCase1.getRadius() << " Km has volume " << testCase1.getVolume() << " Km^3" << endl;

    cout << endl;

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // The planet Venus with radius 6051.8 Km has volume 9.28415*10^11
    Planet testCase2("Venus",6051.8);
    cout << "The planet " << testCase2.getName() << " with radius " << testCase2.getRadius() << " Km has volume " << testCase2.getVolume() << " Km^3" << endl;

    return 0;
}
