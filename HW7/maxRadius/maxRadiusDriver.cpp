// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 7 - Problem # 2

#include <iostream>
#include <math.h>
#include <string>
#include "Planet.h"
using namespace std;

int maxRadius(Planet planets[], int size){
   int idx = -1;
   int maxRadTest = 0;

   for (int i = 0; i<size; i++){
       if (planets[i].getRadius() > maxRadTest){
              idx = i;
              maxRadTest = planets[i].getRadius();
       }
       else{
           continue;
       }
   }
   return idx;
}

int main(){
    cout << endl << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // Bird World \n 4321 \n 3.37941e+11
    Planet planets1[5];
    planets1[0] = Planet("On A Cob Planet",1234);
    planets1[1] = Planet("Bird World",4321);
    int idx = maxRadius(planets1, 2);
    cout << planets1[idx].getName() << endl;
    cout << planets1[idx].getRadius() << endl;
    cout << planets1[idx].getVolume() << endl;

    cout << endl;

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // -1
    Planet planets2[3];
    idx = maxRadius(planets2, 0);
    cout << idx << endl;

    return 0;
}
