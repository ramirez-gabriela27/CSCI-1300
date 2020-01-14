// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 3 - Problem # 8

#include <iostream>
using namespace std;

/*
    Determine the population in the U.S. after a year based on a given initial population
    @param initialPopulation (int) - input initial population in the U.S.
    @return finalPopulation (int) - rounded to the nearest whole number
*/
int population (int initialPopulation)
{
    int people = initialPopulation;
    int finalPopulation;
    int day = 0;
    int seconds;
    while (day < 365)
    {
        day += 1;
        seconds = 0;
        while (seconds <= 86400)
        {
            seconds += 1;
            //Every 8 seconds a person is born
            if (seconds % 8 == 0)
            {
                people += 1;
            }
            //Every 12 seconds a person dies
            if (seconds % 12 == 0)
            {
                people -= 1;
            }
            //Every 27 seconds there is an immigrant arriving
            if (seconds % 27 == 0)
            {
                people += 1;
            }
        }
    }
    finalPopulation = people;
    return finalPopulation;
}

main()
{
    //initialize initialPopulation and set to user input
    int initialPopulation;
    cout << "Please input the initial population of the U.S. : " << endl;
    cin >> initialPopulation;
    //initialize finalPopulation and calculate it by calling population function
    int finalPopulation = population (initialPopulation);
    cout << "The population after 365 days is: " << finalPopulation << endl;

    cout << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // The population after 365 days is: 2482000
    finalPopulation = population (0);
    cout << "The population after 365 days is: " << finalPopulation << endl;

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // The population after 365 days is: 14847478
    finalPopulation = population (12365478);
    cout << "The population after 365 days is: " << finalPopulation << endl;
    return 0;

}
