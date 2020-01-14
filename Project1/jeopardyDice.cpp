// CS1300 Spring 2019
// Author: Gabriela Tolosa Ramirez
// Recitation: 303 – Karthik Palavalli
// Cloud9 Workspace Editor Link: https://ide.c9.io/gato0186/csci1300_gtr
// Project 1

///////////////////////////////////////////////////////////////////////////////////////////////////
// Step1: Steps to solve this problem
// write an algorithm in pseudocode explaining how you are approaching the problem,
// step by step
///////////////////////////////////////////////////////////////////////////////////////////////////

/*

//function to roll dice (provided)
rollDice(){
	return a random number between 1 and 6
}

//function for the player to continue playing (to return true or false)
keepPlaying{
	initialize variable rollAgain as character
	print("Do you want to roll again (Y/N)?")
	rollAgain = user input
	if rollAgain is equal to 'y' or 'Y'{
		return true
	}
	else if rollAgain is equal to 'n' or 'N'{
		return false
	}
	else{
		print("That is not a valid input, try again: ")
		rollAgain = user input
	}
}

//function for human turn (for actual play) and return turnTotal
turnPlayHuman{
	initialize variable turnTotal and set it to 0
	initialize variable roll as integer
	initialize variable decision as character
	initialize variable rollAgain as boolean
	print("Do you want to roll a dice (Y/N)?")
	decision = user input
	if decision is equal to 'y' or 'Y'{
		rollAgain = true
	}
	else if decision is equal to 'n' or 'N'{
	rollAgain = false
	}
	else{
		print("That is not a valid input, try again: ")
		rollAgain = user input
	}
	while roll again is equal to true{
		roll = value returned form calling function rollDice
		print(value rolled)
		if roll equal to 2 or 5{
			turnTotal = 0
			print (value of turnTotal)
			rollAgain = false
		}
		else if roll equal to 4{
			turnTotal = 15
			print (value of turnTotal)
			rollAgain = false
		}
		else{
			turnTotal = roll + turnTotal
			print (value of turnTotal)
			rollAgain = value returned from calling function keepPlaying
		}
	}
	return turnTotal
}

//function for human turn (to calculate score) and return score
turnHuman{
	initialize turnTotal and set it to 0
	print("It is now human's turn")
	turnTotal  = value returned form calling function turnPlayHuman
	scoreHuman = scoreHuman + turnTotal
	return scoreHuman
}

//function for computer turn (for actual play) and return turnTotal
turnPlayComputer{
	initialize turnTotal and set it to 0
	initialize rollAgain and set it to 1
	initialize variable roll as integer
	while rollAgain is equal to 1{
		roll = value returned form calling function rollDice
		print(value rolled)
		if roll equal to 2 or 5{
			turnTotal = 0
			print (value of turnTotal)
			rollAgain = 0
		}
		else if roll equal to 4{
			turnTotal = 15
			print (value of turnTotal)
			rollAgain = 0
		}
		else{
			turnTotal = roll + turnTotal
			print (value of turnTotal)

			if turnTotal >= 10{
				rollAgain = 0
			}
			else{
				rollAgain = 1
			}
		}
	}
	return turnTotal
}

//function for computer turn (to calculate score) and return score
turnComputer{
	initialize turnTotal and set it to 0
	print("It is now computer's turn")
	turnTotal = value returned form calling function turnPlayComputer
	scoreComputer = scoreComputer + turnTotal
	return scoreComputer
}

//function to display score
scoreDisplay{
	print(scoreComputer)
	print(scoreHuman)
}

//function to run the actual game
void game{
	initialize scoreHuman and set it to 0
	initialize scoreComputer and set it to 0
	initialize turn and set it to human
	print("Welcome to Jeopardy Dice!")
	while turn is eqaul to human{
		scoreHuman = value returned when turnHuman is called
		if scoreHuman is greater than or equal to 80 or scoreComputer  is greater than or equal to 80{
			turn is set to neither
		}
		else{
			turn is set to computer
		}
		print(scoreComputer)
		print(scoreHuman)
		while turn is equal to computer{
			scoreComputer = value returner when turnComputer is called
			if scoreHuman is greater than or equal to 80 or scoreComputer  is greater than or equal to 80{
				turn is set to neither
			}
			else{
				turn is set to human
			}
			print(scoreComputer)
			print(scoreHuman)
		}
	}
	if scoreHuman is greater than scoreComputer{
		print("Congratulations! human won this round of Jeopardy Dice!")
	}
	else if scoreComputer is greater than scoreHuman{
		print("Congratulations! computer won this round of Jeopardy Dice!")
	}
	else{
		print("It's a tie!")
	}
}

//main function(provided)
main{
	call the game to start by calling game function
}

*/

///////////////////////////////////////////////////////////////////////////////////////////////////
// Step2: Code it up!
// After finishing up your pseudocode, translate them into c++
// IMPORTANT: rollDie() and main() are already written for you.
// You need to complete game function as well as at least 3 other
//additional functions
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
using namespace std;

/**
 * rollDie
 * returns a random integer between 1 and 6, works as rolling a dice.
 * return value, int number (1-6)
 */
int rollDie(){
	return rand() % 6 + 1;
}

//function 1 - playOn
/*
    Ask the user if they want to keep playing
    @param N/A
    @return true/false
*/
bool keepPlaying(){

	char rollAgain;

	cout << "Do you want to roll again (Y/N)?:" << endl;
	cin >> rollAgain;

	if (rollAgain == 'y' || rollAgain == 'Y'){
		return true;
	}
	else if (rollAgain == 'n' || rollAgain == 'N'){
		return false;
	}
	else{
		cout << "That is not a valid input, try again: " << endl;
		cin >> rollAgain;
	}
}

//function 2 - turnPlayHuman
/*
    Play the human turn
    @param N/A
    @return turnTotal (int) - calculated based on game rules
*/
int turnPlayHuman(){
	int turnTotal = 0;
	int roll;
	char decision;
	bool rollAgain;

	cout << "Do you want to roll a dice (Y/N)?:" << endl;
	cin >> decision;
	if (decision == 'y' || decision == 'Y'){
		rollAgain = true;
	}
	else if (decision == 'n' || decision == 'N'){
		rollAgain = false;
		turnTotal = 0;

	}
	else{
		cout << "That is not a valid input, try again: " << endl;
		cin >> decision;
	}

	while (rollAgain == true){
		roll = rollDie();
		cout << "You rolled a " << roll << endl;

		if (roll == 2 || roll == 5){
			turnTotal = 0;
			cout << "Your turn total is " << turnTotal << endl;
			rollAgain = false;
		}
		else if (roll == 4){
			turnTotal = 15;
			cout << "Your turn total is " << turnTotal << endl;
			rollAgain = false;
		}
		else{
			turnTotal = turnTotal + roll;
			cout << "Your turn total is " << turnTotal << endl;
			rollAgain = keepPlaying();
		}
	}
	return turnTotal;
}

//function 3 - turnHuman
/*
    Calculate the human's score based on the dice rolls
    @param N/A
    @return turnTotal (int) - the total "points" for the turn
*/
int turnHuman(int scoreHuman){
	cout << endl;
	cout << "It is now human's turn" << endl;
	cout << endl;

	int turnTotal;
	turnTotal = 0;

	turnTotal = turnPlayHuman();

	scoreHuman = scoreHuman + turnTotal;

	return scoreHuman;
}

//function 4 - turnPlayComputer
/*
    Play the computer turn
    @param N/A
    @return turnTotal (int) - calculated based on game rules
*/
int turnPlayComputer(){
	int turnTotal = 0;
	int roll;
	int rollAgain = 1;

	while (rollAgain == 1){
		roll = rollDie();
		cout << "Computer rolled a " << roll << endl;

		if (roll == 2 || roll == 5){
			turnTotal = 0;
			cout << "Computer turn total is " << turnTotal << endl;
			rollAgain = 0;
		}
		else if (roll == 4){
			turnTotal = 15;
			cout << "Computer turn total is " << turnTotal << endl;
			rollAgain = 0;
		}
		else{
			turnTotal = turnTotal + roll;
			cout << "Computer turn total is " << turnTotal << endl;

			if(turnTotal >= 10){
				rollAgain = 0;
			}
			else{
				rollAgain = 1;
			}
		}
	}
	return turnTotal;
}

//function 5 - turnComputer
/*
    Calculate the computer's score based on the dice rolls
	@param N/A
    @return turnTotal (int) - the total "points" for the turn
*/
int turnComputer(int scoreComputer){
	cout << endl;
	cout << "It is now computer's turn" << endl;
	cout << endl;

	int turnTotal;
	turnTotal = 0;

	turnTotal = turnPlayComputer();

	scoreComputer = scoreComputer + turnTotal;

	return scoreComputer;
}

//function 6 - scoreDisplay
/*
    display the score
	@param scoreComputer (int) and scoreHuman (int) - calculated in other functions
    @return N/A
*/
void scoreDisplay(int scoreComputer, int scoreHuman){
	cout << "computer: " << scoreComputer << endl;
	cout << "human: " << scoreHuman << endl;
}

/**
 * game
 * driver function to play the game
 * the function does not return any value
 */
void game(){

	int scoreHuman = 0;
	int scoreComputer = 0;
	string turn = "Human";

	cout << "Welcome to Jeopardy Dice!" << endl;

	while (turn == "Human"){
		scoreHuman = turnHuman(scoreHuman);
		if(scoreHuman >= 80 || scoreComputer >= 80){
			turn = "Neither";
		}
		else{
			turn = "Computer";
		}
		scoreDisplay(scoreComputer,scoreHuman);

		while (turn == "Computer"){
			scoreComputer = turnComputer(scoreComputer);
			if(scoreHuman >= 80 || scoreComputer >= 80){
				turn = "Neither";
			}
			else{
				turn = "Human";
			}
			scoreDisplay(scoreComputer,scoreHuman);
		}
	}

	cout << endl;

	if(scoreHuman > scoreComputer){
		cout << "Congratulations! human won this round of Jeopardy Dice!" << endl;
	}
	else if(scoreComputer > scoreHuman){
		cout << "Congratulations! computer won this round of Jeopardy Dice!" << endl;
	}
	else{
		cout << "It's a tie!" << endl;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// don't change the main.
// Once you finished please paste your code above this line
///////////////////////////////////////////////////////////////////////////////////////////////////

int main(){
	srand(123);
	// start the game!
	game();
	return 0;
}
