// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 6 - Problem # 2

#include <iostream>
using namespace std;

/*
    Create a map indicating the areas floded based on the water level and the input terrain values
    @param map (array of doubles) - pass the array as given by the number of columns predetermined
    @param rows (int) - the number of rows in the array
    @param waterLevel (double) - input waterLevel
    @return N/A
*/
void floodMap(double map[][4], int rows, double waterLevel){
    int COLUMNS =4;
    string mapOfFlood [rows][COLUMNS];

    for (int i = 0; i<rows; i++){
        for (int j = 0; j<COLUMNS; j++){
            if(map[i][j] == waterLevel || map[i][j] <= waterLevel){
                mapOfFlood[i][j] = "*";
            }
            else{
                mapOfFlood[i][j] = "_";
            }
        }
    }

    for (int i = 0; i<rows; i++){
        for (int j = 0; j<COLUMNS; j++){
            cout << mapOfFlood[i][j];
        }
        cout << endl;
    }
}

main(){
    const int COLUMNS = 4;
    int rows = 0;

    cout << "How many rows will there be in the 4 column array? " << endl;
    cin >> rows;

    double map[rows][COLUMNS];

    double waterLevel = 0;
    cout << "Please enter the water level: " << endl;
    cin >> waterLevel;

    cout << "In order to fill out the map " << endl;

    for(int i = 0; i<rows; i++){
        for (int j = 0; j<COLUMNS; j++){
            cout << "Please input a value: " << endl;
            cin >> map[i][j];
        }
    }

    cout << endl;

    floodMap(map, rows, waterLevel);

    cout << endl;

    cout << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // *_*_
    // _*_*
    rows = 2;
    double map1[rows][COLUMNS] ={{5.9064, 15.7541, 6.11483, 11.3928},{16.8498, 5.736, 9.33342, 6.36095}};
    floodMap(map1, 2, 9.3);
    cout << endl;

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // ____
    rows = 1;
    double map2[rows][COLUMNS] ={{4.6,3.8,9.9,5.5}};
    floodMap(map2, 1, 0.0);

    return 0;
}
