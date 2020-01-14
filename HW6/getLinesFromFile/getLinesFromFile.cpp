// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Homework 6 - Problem # 4

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
    Read the lines in an input text and place them in an array. return the number of integers
    @param fileName (string) - The name of the file being read
    @param arr (array) - Array of integer values
    @param length (int) - Desired length of the array
    @return numberOfIntegers (int) - The number of integers read in a file.
*/
int getLinesFromFile(string fileName, int arr[], int length){
    ifstream inFile;
    inFile.open(fileName);

    if (inFile.fail()) {
        return -1;
    }

    string line;
    int numberOfIntegers = 0;

    while(getline(inFile,line)){
        if (line != ""){
            if (numberOfIntegers >= length){
                inFile.close();
            }
            else{
                arr[numberOfIntegers] = stoi(line);
                numberOfIntegers ++;
            }
        }
        else;
    }
    return numberOfIntegers;
}


int main(){
    string fileName;
    cout << "Please insert the name of the file: " << endl;
    cin >> fileName;

    int length;
    cout << "Please insert the length of the array: " << endl;
    cin >> length;
    int arr[length];

    int numberOfIntegers = getLinesFromFile(fileName, arr, length);

    cout << "There are " << numberOfIntegers << " integers in the file " << fileName << endl;
    cout << endl;
    for (int i = 0; i <length; i++){
        cout << arr[i] << endl;
    }

    cout << endl;

    cout << "================================" << endl;
    cout << "Test Case 1" << endl;
    // test 1
    // expected output
    // There are 3 integers in the file nums1.txt
    numberOfIntegers = getLinesFromFile("nums1.txt", arr, length);
    cout << "There are " << numberOfIntegers << " integers in the file nums1.txt" << endl;

    cout << endl;

    cout << "Test Case 2" << endl;
    // test 2
    // expected output
    // There are 2 digits in the file nums1.txt
    numberOfIntegers = getLinesFromFile("nums2.txt", arr, length);

    cout << "There are " << numberOfIntegers << " integers in the file nums2.txt" << endl;

    return 0;
}
