// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 3 - Problem # 4

#include <iostream>
#include <math.h>
using namespace std;

int main(){
    cout << "Enter a radius: " << endl;
    //radius is initialized and set to the user input
    double radius;
    cin >> radius;
    //volume is initialized and calculated
    double volume;
    volume = (4.0/3.0) * M_PI * pow(radius, 3);
    cout << "volume: " << volume << endl;
    //surfaceArea is initialized and calculated
    double surfaceArea;
    surfaceArea = 4.0 * M_PI * pow(radius, 2);
    cout << "Surface Area: " << surfaceArea << endl;
    return 0;
}
