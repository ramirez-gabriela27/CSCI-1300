#include <iostream>
#include <string>
#include "User.h"
using namespace std;

// Default constructor
User::User(){
    username = "";
    numRatings = 0;
    size = 50;
    for(int i = 0; i < size; i++){
        ratings[i] = 0;
    }
}

// Parameterized constructor
User::User(string userIn, int rateIn[], int numRateIn){
    size = 50;
    username = userIn;
    for(int i = 0; i < size; i++){
        ratings[i] = 0;
    }
    for(int i = 0; i < numRateIn; i++){
        ratings[i] = rateIn[i];
    }
    if(numRateIn <= size){
        numRatings = numRateIn;
    }
}

/*
    GET the username
    @param N/A
    @return username (string) - the username
*/
string User::getUsername(){
    return username;
}

/*
    SET the username
    @param userIn (string) - the username
    @return N/A
*/
void User::setUsername(string userIn){
    username = userIn;
}

/*
    GET the rating at a specific index
    @param index (int) - index of where to find rating
    @return ratings[index] (int) - the rating at a specific index
*/
int User::getRatingAt(int index){
    if(index >= size){
        return -1;
    }
    else{
        return ratings[index];
    }
}

/*
    SET the rating at a specific index
    @param index (int) - index of where to set rating
    @param value (int) - value of the rating
    @return N/A
*/
bool User::setRatingAt(int index, int value){
    if(index < 50 && (value >=0 && value <= 5)){
        ratings[index] = value;
        return true;
    }
    else{
        return false;
    }
}

/*
    GET the rating numbers
    @param N/A
    @return numRatings (int) - the number of ratings
*/
int User::getNumRatings(){
    return numRatings;
}

/*
    SET the rating numbers
    @param numRateIn (int) - the number of ratings
    @return N/A
*/
void User::setNumRatings(int numRateIn){
    numRatings = numRateIn;
}

/*
    GET the size of the array
    @param N/A
    @retunr size (int) - the size of the array
*/
int User::getSize(){
    return size;
}
