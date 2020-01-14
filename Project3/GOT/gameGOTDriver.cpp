#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>

#include "Tile.h"
#include "Warrior.h"
#include "Hero.h"
#include "Player.h"

#include "Tile.cpp"
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

//////////////////////INITIALIZING FUNCTIONS ///////////////////////////////////
/*
    Create a random location
    @param locationsRandom array of integers
    @return N/A
*/
void randomLocation(int locationRandom[2]){
    int randomRow = rand() % 16 + 1;
    int randomColumn = rand() % 25 +1;
    locationRandom[0] = randomRow;
    locationRandom[1] = randomColumn;
}

    ///create the map here///
/*
    create an array of city Tiles
    @param cities array
    @return N/A
*/
void initializeCities(Tile cities[26]){
    // open file to read
    ifstream inFile;
    inFile.open("citiesGOT.txt");

    string line = "";
    string msgsub[5];
    int i = 0;

    while(getline(inFile,line) && i < 26){
        split(line,',',msgsub,5);
        string typeIn = "City";
        string letterIn = msgsub[0];
        string nameIn = msgsub[1];
        int moneyIn = stoi(msgsub[2]);
        int armySizeIn = stoi(msgsub[3]);
        int pointsIn = stoi(msgsub[4]);
        int locationRowIn = -1;
        int locationColumnIn = -1;
        bool dragonglassIn = false;

        Tile tileIn = Tile(typeIn, letterIn, nameIn, moneyIn, armySizeIn, pointsIn, locationRowIn, locationColumnIn, dragonglassIn);
        cities[i]= tileIn;

        i++;
    }
    inFile.close();
}
/*
    create a map with a 2D array of Tiles
    @param 2D array of tiles
    @return N/A
*/
void initializeMap(Tile map[25][16]){
    ifstream inFile;
    inFile.open("mapGOT.txt");

    string line = "";
    string msgsub2[16];
    int citiesCounter = 0;

    // array of city objects to be initialized
    Tile cities[26];
    initializeCities(cities);
    int i = 0;

    while(getline(inFile,line)){
        split(line, ',', msgsub2, 16);
        //map is 16x25
        for(int j = 0; j < 16; j++){
            if(msgsub2[j] == "p"){
                Tile tileIn = Tile("Land","*","p",0,0,2,i,j,false);
                map[i][j] = tileIn;
            }
            else if(msgsub2[j] == "w"){
                Tile tileIn = Tile("Water","~","w",0,0,1,i,j,false);
                map[i][j] = tileIn;
            }
            else{
                if(cities[citiesCounter].getLetter() == msgsub2[j]){
                    Tile tileIn = cities[citiesCounter];
                    int location[2] = {i,j};
                    tileIn.setLocation(location);
                    map[i][j] = tileIn;
                    citiesCounter++;
                }
            }
        }
        i++;
    }
    inFile.close();


    /////////////////////Place dragonglass in random locations//////////////////
    int dgLocationCounter = 0;

    while(dgLocationCounter <= 5){
        int dglocationRandom[2] = {-1,-1};
        randomLocation(dglocationRandom);

        if(map[dglocationRandom[0]][dglocationRandom[1]].getName() == "p"){
            map[dglocationRandom[0]][dglocationRandom[1]].setDragonglassYN(true);
            dgLocationCounter++;
        }
    }
    /////////////////////Place dragonglass in random locations//////////////////
}
/*
    display the entirety of the map
    @param 2D array of tiles
    @return N/A
*/
void displayMapWhole(Tile map[25][16]){
    for(int i = 0; i < 25; i++){
        for(int j = 0; j < 16; j++){
            cout << " " << map[i][j].getLetter() << " ";
        }
        cout << endl;
    }
}
/*
    display a 7x7 map based on the heroes location
    @param 2D array of tiles, Hero heroChosen
    @param heroChosen (Hero) - the hero chosen for the game
    @return N/A
*/
void displayMapHero(Tile map[25][16], Hero heroChosen){
    int rowHero = stoi(heroChosen.getLocationRow())-1;
    int columnHero = stoi(heroChosen.getLocationColumn())-1;

    int startRow = rowHero - 3;
    int startColumn = columnHero - 3;
    int endRow = rowHero + 4;
    int endColumn = columnHero + 4;

    // if at the edge of the map, start at the nearest edge
    if(startRow <= 0){
        startRow = 0;
    }else;
    if(startColumn <= 0){
        startColumn = 0;
    }else;
    if(endRow >= 25){
        endRow = 25;
    }else;
    if(endColumn >= 16){
        endColumn = 16;
    }else;

    string tileLetter = map[rowHero][columnHero].getLetter();

    map[rowHero][columnHero].setLetter("&");

    for(int i = startRow; i < endRow; i++){
        for(int j = startColumn; j < endColumn; j++){
            cout << " " << map[i][j].getLetter() << " ";
        }
        cout << endl;
    }
    map[rowHero][columnHero].setLetter(tileLetter);
}

    ///create all the heroes and warriors here///
/*
    initialize the array of warriors
    @param map 2D array of Tiles
    @return vector<Warrior> - vector of warrior objects
*/
vector<Warrior> initializeWarriors(Tile map[25][16]){
    vector<Warrior> warriors;
    //open file to read
    ifstream inFile;
    inFile.open("warriorsGOT.txt");

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
    inFile.close();

    ///////////////////Place free warriors in random locations//////////////////
    for(int i = 0; i < warriors.size(); i++){
        if(warriors[i].getFreeYN() == true){
            int warriorLocationRandom[2] = {-1,-1};
            randomLocation(warriorLocationRandom);

            if(map[warriorLocationRandom[0]][warriorLocationRandom[1]].getName() == "p"){
                warriors[i].setLocation(warriorLocationRandom);
            }
            else if(map[warriorLocationRandom[0]][warriorLocationRandom[1]].getName() == "w"){
                if(warriors[i].getShipYN() == true){
                    warriors[i].setLocation(warriorLocationRandom);
                }else;
            }else;
        }
    }
    ///////////////////Place free warriors in random locations//////////////////

    return warriors;
}
/*
    display the stats for each warrior
    @param vector<Warrior> warriors - vector of warrior objects
    @return N/A
*/
void displayWarriorsStats(vector<Warrior> warriors){
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
/*
    initialize the array of warriors
    @param warriorTest1(str) - string of warriors names
    @return vector<Warrior> - vector of warriors for the heroes
*/
vector<Warrior> assignWarriors(vector<Warrior> warriors, string warriorTest1, string warriorTest2, string warriorTest3, string warriorTest4){
    vector<Warrior> warriorsHero;

    string warriorsTests[4] = {warriorTest1,warriorTest2,warriorTest3,warriorTest4};

    for(int j = 0; j < warriors.size(); j++){
        string test = warriors[j].getName();
            for(int i = 0; i < 4; i++){
            if (warriorsTests[i] != "NULL" && warriorsTests[i] == test){
                warriorsHero.push_back(warriors[j]);
                break;
            }
        }
    }

    return warriorsHero;
}
/*
    initialize the array of warriors
    @param map 2D array of Tiles
    @return vector<Hero> - vector of Hero objects
*/
vector<Hero> initializeHeroes(Tile map[25][16]){
    vector <Warrior> warriors;
    warriors = initializeWarriors(map);

    vector<Hero> heroes;
    //open file to read
    ifstream inFile;
    inFile.open("heroesGOT.txt");

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

        vector<Warrior> warriorHero;

        warriorHero = assignWarriors(warriors, warriorTest1,warriorTest2,warriorTest3,warriorTest4);

        string rowIn = msgsub[8];
        string columnIn = msgsub[9];

        bool shipIn = false;
        bool dragonglassIn = false;

        if(msgsub[10] == "yes"){
            shipIn = true;
        }

        // create warrior objects and assign corresponding values
        Hero heroIn = Hero(nameIn, moneyIn, influenceIn, armySizeIn, warriorHero, rowIn, columnIn, shipIn, dragonglassIn);
        // add them to the warrior vector
        heroes.push_back(heroIn);
    }
    return heroes;
}
/*
    display the stats for each Hero
    @param vector<Hero> heroes - vector of Hero objects
    @return N/A
*/
void displayHeroesStats(vector<Hero> heroes){
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

void displayHero (Hero hero){
    cout << "Name: " << hero.getName() << endl;
    cout << "Money: $" << hero.getMoney() << endl;
    cout << "Influence: " << hero.getInfluence() << endl;
    cout << "Army Size: " << hero.getArmySize() << endl;
    cout << "Location (row,column): (" << hero.getLocationRow() << "," << hero.getLocationColumn() << ")" << endl;
    cout << "Hero has ship: " << hero.getShipYN() << endl;
    cout << "Hero has dragonglass: " << hero.getDragonglassYN() << endl;
    cout << "Here is a list of their warriors: " << endl;
    vector<Warrior>warriorsForHero;
    warriorsForHero = hero.getWarriors();
    for(int i = 0; i < warriorsForHero.size(); i++){
        cout << warriorsForHero[i].getName() << endl;
    }
    cout << "==================" << endl;
}

    ///Initalize the Players and their decisions///
/*
    Initalize the Player
    @param vector<Warrior> warriors - vector of Warrior objects
    @param vector<Hero> heroes - vector of Hero objects
    @param map[25][16] (Tile) - map
    @return N/A
*/
Player initializePlayer(vector <Warrior> warriors,vector<Hero> heroes, Tile map[25][16]){
    string playerName;
    double playerPoints = 0.0;
    cout << "State your name, Your Grace: "<<endl;
    getline(cin, playerName);

    string optionStart;
    cout << "Would you like to choose a hero, " << playerName << ", Your Grace? (Y/N): ";
    cin >> optionStart;

    if(optionStart == "Y" || optionStart == "y"){
        cout << "Pleae chose from the following heroes: " <<endl << endl;
        for(int i = 0; i < heroes.size(); i++){
            cout << i+1 << " " << heroes[i].getName() << endl;
        }

        string heroChoice;
        cout << endl << "Which hero would you like, Your Grace: ";
        cin >> heroChoice;

        Hero playerHero;

        switch(stoi(heroChoice)){
            case 1:
            playerHero = heroes[0];
            break;

            case 2:
            playerHero = heroes[1];
            break;

            case 3:
            playerHero = heroes[2];
            break;

            case 4:
            playerHero = heroes[3];
            break;

            case 5:
            playerHero = heroes[4];
            break;

            case 6:
            playerHero = heroes[5];
            break;

            default:
            cout << "invalid input" << endl << endl;
        }

        Player playerGame = Player(playerName, playerPoints, playerHero);
        return playerGame;
    }
    else if(optionStart == "N" || optionStart == "n"){
        cout << "Your Grace " << playerName << " you have chosen to go on this journey alone.";
        cout << endl << "Please provide starting values for your adventurer." << endl;

        cout << endl << "Please, Your Grace, no values bigger than 10000." << endl;
        string moneyIn;
        cout << endl << "Money: ";
        cin >> moneyIn;

        string influenceIn;
        cout << "Influence: ";
        cin >> influenceIn;

        string armySizeIn;
        cout << "Army Size: ";
        cin >> armySizeIn;

        string rowIn;
        string columnIn;
        cout << "Starting Row: ";
        cin >> rowIn;
        cout << "Starting Column: ";
        cin >> columnIn;

        bool shipIn = false;
        bool dragonglassIn = false;
        vector<Warrior> heroWarriorsIn;

        Hero playerHero(playerName, stoi(moneyIn), stoi(influenceIn), stoi(armySizeIn), heroWarriorsIn, rowIn, columnIn, shipIn, dragonglassIn);
        Player playerGame = Player(playerName, playerPoints, playerHero);
        return playerGame;
    }else;
    /* NEED TO TEST FOR STUFF THAT COULD GO WRONG IF HERO IS CREATED */
}

        ///Display the choices every turn///
/*
    display the meny for each turn
    @param N/A
    @return N/A
*/
void displayMenu(){
	cout << "Select a numerical option, Your Grace:" << endl;
	cout << "======== Menu =======" << endl;
	cout << "1. Travel North" << endl;
    cout << "2. Travel South" << endl;
    cout << "3. Travel East" << endl;
    cout << "4. Travel West" << endl;
	cout << "5. Rest" << endl;
	cout << "6. Consult with the gods" << endl;
    cout << "7. Display the whole map" << endl;
	cout << "8. Quit" << endl;
}
//////////////////////INITIALIZING FUNCTIONS ///////////////////////////////////

main(){
    // call everything to intialize the game!

    Tile map[25][16];
    initializeMap(map);

    vector <Warrior> warriors;
    warriors = initializeWarriors(map);
    //displayWarriorStats(warriors); make member function of Warrior

    vector<Hero> heroes;
    heroes = initializeHeroes(map);
    //displayHeroesStats(heroes); make member function of Hero

    Player playerGame;
    playerGame = initializePlayer(warriors, heroes, map);

    ///////////////////////////start the game! /////////////////////////////////
    Hero playerHero = playerGame.getHero();

    vector <Warrior> heroWarriors;
    heroWarriors = playerHero.getWarriors();

    string choice;
    int rowMove = 0;
    int columnMove = 0;

    while(choice != "8"){
        displayHero(playerHero);
        displayMapHero(map, playerHero);
        displayMenu();
        cin >> choice;
        int menuChoice = stoi(choice);

        switch(menuChoice){
            // travel north // test for ship!!
            case 1:
                rowMove = stoi(playerHero.getLocationRow());
                if(rowMove - 1 > 0){
                    string tileKind = map[rowMove -1][stoi(playerHero.getLocationColumn())].getLetter();
                    if(tileKind == "~"){
                        if(playerHero.getShipYN() == true){
                            rowMove -= 1;
                            playerHero.setLocationRow(to_string(rowMove));

                            playerGame.setTurn();
                        }else{
                            cout << "Sorry, Your Grace, but you can't to this tile." << endl;
                            cout << endl;
                        }
                    }
                }else{
                    cout << "Sorry, Your Grace, but you can't travel further north." << endl;
                    cout << endl;
                }
                break;

            // travel south // test for ship!!
            case 2:
                rowMove = stoi(playerHero.getLocationRow());
                if(rowMove + 1 <= 25){
                    rowMove += 1;
                    playerHero.setLocationRow(to_string(rowMove));

                    playerGame.setTurn();
                }else{
                    cout << "Sorry, Your Grace, but you can't travel further south." << endl;
                    cout << endl;
                }
                break;

            // travel east // test for ship!!
            case 3:
                columnMove = stoi(playerHero.getLocationColumn());
                if(columnMove + 1 <= 16){
                    columnMove += 1;
                    playerHero.setLocationColumn(to_string(columnMove));

                    playerGame.setTurn();
                }else{
                    cout << "Sorry, Your Grace, but you can't travel further east." << endl;
                    cout << endl;
                }
                break;

            // travel west // test for ship!!
            case 4:
                columnMove = stoi(playerHero.getLocationColumn());
                if(columnMove - 1 > 0){
                    columnMove -= 1;
                    playerHero.setLocationColumn(to_string(columnMove));

                    playerGame.setTurn();
                }else{
                    cout << "Sorry, Your Grace, but you can't travel further west." << endl;
                    cout << endl;
                }
                break;

            // rest
            case 5:
                for(int i = 0; i < heroWarriors.size(); i++){
                    int strength = heroWarriors[i].getStrenght();
                    heroWarriors[i].setStrenght(strength + 1);
                }
                cout << "You and your warriors are rested." << endl;
                cout << endl;
                break;

            // consult with the gods
            case 6:
                for(int i = 0; i < heroWarriors.size(); i++){
                    int morale = heroWarriors[i].getMorale();
                    heroWarriors[i].setMorale(morale + 1);
                }
                cout << "You and your warriors are hyped up." << endl;
                cout << endl;
                break;

            //display the whole map (without the location of the hero)
            case 7:
                displayMapWhole(map);
                cout << endl << "Your location is not displayed." << endl;

                cout << endl;
                break;

            // quit the game and write to results file, then display the file
            case 8:
                // ofstream outFile;
                // outFile.open("resultsGOT.txt");
                // outFile << playerGame.getName() << " , " << playerGame.getPoints() << " , Hero: " << playerHero.getName() << endl;

                cout << "Good game, Your Grace." << endl;
                break;

            default:
                cout << "invalid input" << endl << endl;
        }
    }
    return 0;
}
