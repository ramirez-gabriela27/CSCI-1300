// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 3 - Problem # 6


#include <iostream>
#include <math.h>
using namespace std;
/*
    Calculate the surface area of a sphere
    @param radius (double) - input radius
    @return N/A
*/
 void sphereSurfaceArea (double radius)
{
    double surfaceArea;
    surfaceArea = 4.0 * M_PI * pow(radius, 2);
    cout << "Surface Area: " << surfaceArea << endl;
}

int main()
{
    cout << "Enter a radius: " << endl;
    //radius is initialized and set to user input
    double radius;
    cin >> radius;
    //call sphereSurfaceArea function and use radius as param
    sphereSurfaceArea(radius);

    cout << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // Surface Area: 91.609
    sphereSurfaceArea(2.7);

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // Surface Area: 113.097
    sphereSurfaceArea(3.0);
    return 0;
}
