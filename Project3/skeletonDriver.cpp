// to test out classes created
// to create template of the driver for the game

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

// #include "City.h"
#include "Warrior.h"
#include "Hero.h"
#include "Player.h"

// #include "City.cpp"
#include "Warrior.cpp"
#include "Hero.cpp"
#include "Player.cpp"

using namespace std;

// HELPER FUNCTIONS //
/*
    split a message based on a delimiter and put it in a two dimensional array
    @param message (string) - message input by user
    @param delimiter (char) - delimiter (place of division) input by the user
    @param messageSubstrings (array) - array of substrings
    @param size (int) - size of the array
    @return substringNums (int) - the number of substrings
*/
int split (string message, char delimiter, string messageSubstrings[], int size){
    if (message.length() == 0) {
        return 0;
    }

    string temp = "";
    int substringNums = 0;

    message += delimiter;

    for (int i = 0; i < message.length(); i++)
    {
        if(message[i]==delimiter){
            if(temp.length() == 0) continue;
            messageSubstrings[substringNums] = temp;
            substringNums ++;
            temp = "";
        }
        else{
            temp = temp + message[i];
        }
    }

    if(size<substringNums){
        return -1;
    }
    else{
        return substringNums;
    }
}
// HELPER FUNCTIONS //

// vector<City> initializeCities(string fileName){
//     vector <City> cities;
//     //open file to read
//     ifstream inFile;
//     inFile.open(fileName);
//
//     string line;
//     string msgsub[5];
//
//     while(getline(inFile,line)){
//         split(line, ',', msgsub, 5);
//         // create variables for input from substrings
//         string letterIn = msgsub[0];
//         string nameIn = msgsub[1];
//         int moneyIn = stoi(msgsub[2]);
//         int armySizeIn = stoi(msgsub[3]);
//         int pointsIn = stoi(msgsub[4]);
//
//         // create city object and assign corresponding values
//         City cityIn = City(letterIn, nameIn, moneyIn, armySizeIn, pointsIn);
//         // add to the City vector
//         cities.push_back(cityIn);
//     }
//     return cities;
// }
//
// void displayCityList(vector<City> cities){
//     for(int i = 0; i < cities.size(); i++){
//         cout << "Letter: " << cities[i].getLetter() << endl;
//         cout << "Name: " << cities[i].getName() << endl;
//         cout << "Money: $" << cities[i].getMoney() << endl;
//         cout << "Army Size: " << cities[i].getArmySize() << endl;
//         cout << "Points: " << cities[i].getPoints() << endl;
//         cout << "==================" << endl;
//     }
// }


vector<Warrior> initializeWarriors(string fileName){
    vector<Warrior> warriors;
    //open file to read
    ifstream inFile;
    inFile.open(fileName);

    string line;
    string msgsub[7];

    while(getline(inFile,line)){
        split(line, ',', msgsub, 7);
        // create variables for input from substrings
        string nameIn = msgsub[0];
        int strengthIn = stoi(msgsub[1]);
        int loyaltyIn = stoi(msgsub[2]);
        int moraleIn = stoi(msgsub[3]);

        bool freeIn = false;
        bool shipIn = false;
        bool dragonglassIn = false;

        if(msgsub[4] == "yes"){
            freeIn = true;
        }
        if(msgsub[5] == "yes"){
            shipIn = true;
        }
        if(msgsub[6] == "yes"){
            dragonglassIn = true;
        }
        // create warrior objects and assign corresponding values
        Warrior warriorIn = Warrior(nameIn, strengthIn, loyaltyIn, moraleIn,freeIn, shipIn, dragonglassIn);
        // add them to the warrior vector
        warriors.push_back(warriorIn);
    }
    return warriors;
}

void displayWarriorStats(vector<Warrior> warriors){
    for(int i = 0; i < warriors.size(); i++){
        cout << "Name: " << warriors[i].getName() << endl;
        cout << "strength: " << warriors[i].getStrenght() << endl;
        cout << "Loyalty: " << warriors[i].getLoyalty() << endl;
        cout << "Morale: " << warriors[i].getMorale() << endl;
        cout << "Warrior is free: " << warriors[i].getFreeYN() << endl;
        cout << "Warrior has ship: " << warriors[i].getShipYN() << endl;
        cout << "Warrior has dragonglass: " << warriors[i].getDragonglassYN() << endl;
        cout << "==================" << endl;
    }
}


vector<Hero> initializeHeroes(string fileName){
    vector<Hero> heroes;
    //open file to read
    ifstream inFile;
    inFile.open(fileName);

    string line;
    string msgsub[11];

    while(getline(inFile,line)){
        split(line, ',', msgsub, 11);
        // create variables for input from substrings
        string nameIn = msgsub[0];
        int moneyIn = stoi(msgsub[1]);
        int influenceIn = stoi(msgsub[2]);
        int armySizeIn = stoi(msgsub[3]);

        string warriorTest1 = msgsub[4];
        string warriorTest2 = msgsub[5];
        string warriorTest3 = msgsub[6];
        string warriorTest4 = msgsub[7];

        vector<Warrior> warriors;

        string rowIn = msgsub[8];
        string columnIn = msgsub[9];

        bool shipIn = false;
        bool dragonglassIn = false;

        if(msgsub[10] == "yes"){
            shipIn = true;
        }

        // create warrior objects and assign corresponding values
        Hero heroIn = Hero(nameIn, moneyIn, influenceIn, armySizeIn, warriors, rowIn, columnIn, shipIn, dragonglassIn);
        // add them to the warrior vector
        heroes.push_back(heroIn);
    }
    return heroes;
}

void displayHeroes(vector<Hero> heroes){
    for(int i = 0; i < heroes.size(); i++){
        cout << "Name: " << heroes[i].getName() << endl;
        cout << "Money: $" << heroes[i].getMoney() << endl;
        cout << "Influence: " << heroes[i].getInfluence() << endl;
        cout << "Army Size: " << heroes[i].getArmySize() << endl;
        cout << "Location (row,column): (" << heroes[i].getLocationRow() << "," << heroes[i].getLocationColumn() << ")" << endl;
        cout << "Hero has ship: " << heroes[i].getShipYN() << endl;
        cout << "Hero has dragonglass: " << heroes[i].getDragonglassYN() << endl;
        cout << "Here is a list of their warriors: " << endl;
        vector<Warrior>warriorsForHero;
        warriorsForHero = heroes[i].getWarriors();
        for(int i = 0; i < warriorsForHero.size(); i++){
            cout << warriorsForHero[i].getName() << endl;
        }
        cout << "==================" << endl;
    }
}

// cerate display map function ! called after every turn
    // maybe hace a mapTile class?




main(){
////////////////////////////////////// TESTING /////////////////////////////////

/* INITIALIZE THE WARRIORS (and put them in a vector) */
// for test cases
vector <Warrior> warriors;
warriors = initializeWarriors("warriorsGOT.txt");
displayWarriorStats(warriors);

// vector <City> cities;
// cities = initializeCities("citiesGOT.txt");
// displayCityList(cities);

vector<Hero> heroes;
heroes = initializeHeroes("heroesGOT.txt");
displayHeroes(heroes);


//
// string playerName;
// cout << "Plese enter your name, player: "<<endl;
// getline(cin, playerName);
//
// double playerPoints = 0.0;
//
// string option;
// cout << "Would you like to select a hero? or create on? (1/2): " << endl;
// cin >> option;
//
// if(option == "1"){
//     string heroOption = 0;
//     cout << "Which hero would you like to chose? " << endl;
//     for(int i = 0; i < heroes.size(); i++){
//         cout << i+1 << "Name: " << heroes[i].getName() << endl;
//     }
//
//     cin >> heroOption;
// }
////////////////////////////////////////////////////////////////////////////////



///////////////////////////// CODE SKELETON ////////////////////////////////////
/*


RULES TO THINK ABOUT
1.) Here



****PROCESS****

1) initialize game (warriors, heors, cities, map, player etc...)
    put into one function calling other functions in order to make it one step
    and make the main function less cluttered

2) as the user for their name and if they want to choose or create a hero
    - create player object, which then has a corresponding hero object attached
      to it, form there the hero also has warriors (if it has been designated them)
    - if the player choses to create a hero, go with that process and then create
      player object.

3) begin game!
    - display the map
    - break down options in each turn:
        * Here

4) end the game
    - go through logistics here!!!


5) save the player to the roster (as an object)
    - make txt file, with each player's name, hero, and points per line divided
      by commas.
6) put the roster in order by score and display it

7) quit the game// kill the program

*/
///////////////////////////// CODE SKELETON ////////////////////////////////////

return 0;

}
