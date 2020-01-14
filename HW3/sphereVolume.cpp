// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 3 - Problem # 5


#include <iostream>
#include <math.h>
using namespace std;
/*
    Calculate the volume of a sphere
    @param radius (double) - input radius
    @return N/A
*/
 void sphereVolume (double radius)
{
    double volume;
    volume = (4.0/3.0) * M_PI * pow(radius, 3);
    cout << "volume: " << volume << endl;
}

int main()
{
    cout << "Enter a radius: " << endl;
    //radius is initialized and set to user input
    double radius;
    cin >> radius;
    //call sphereVolume function and use radius as param
    sphereVolume(radius);

    cout << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // volume: 82.448
    sphereVolume(2.7);

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // volume: 113.097
    sphereVolume(3.0);
    return 0;
}
