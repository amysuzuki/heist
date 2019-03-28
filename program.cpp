/************************************************************
** Project: Final
** Author: Amy Suzuki
** Date: March 16, 2019
** Description: This file contains the main function that 
** outputs the game objective and menu to start the game.
************************************************************/
#include "game.hpp"
#include "inputs.hpp"
#include "menu.hpp"

#include <string>
using std::string;

int main() {

	//Introduction to game
	cout << "For answers, check answer.txt" << endl;
	cout << endl;
	cout << "GAME OBJECTIVE" << endl;
	cout << "Obtain the right painting and bring it back to the widow" << endl;
	cout << "to escape in time." << endl;
	cout << endl;
	cout << "Note: Every move (including failed moves) will take a minute" << endl;
	cout << "off your in game time.";
	cout << endl;


	//Create Menu
	menu choice(2);
	choice.setPrompt(0, "Start Game");
	choice.setPrompt(1, "Quit");

	//Allow user to start game
	int answer = choice.makeChoice();
	if (answer == 0) {
		Game example;
	} else {
		cout << "Goodbye." << endl;
	}
}

