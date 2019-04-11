/* HEIST
 Author: Amy Suzuki
 Description: The menu class creates a menu and allows user to make
 selections from the menu. The menu class should be used for questions
 with multiple answers. menuYN should be used for Yes/No questions. 
 */

#include "menu.hpp"

//Constructor: Creates a menu and sets the number of Prompts

menu::menu (int num) {
	numOfPrompts = num;
	prompts = new string[num];
}

//Destructor
menu::~menu () {
	delete [] prompts;
}

//Sets the prompt for the given number. Incremented from 0
void menu::setPrompt(int number, string prompt) {
	if ((number < 0) || (number > numOfPrompts)) {
		cout << "ERROR: Number not in menu" << endl;
	} else {
		prompts[number] = prompt;
	}
}

//Prints the Menu
void menu::printMenu() {
	cout << "CHOOSE FROM MENU: " << endl;
	for (int i = 0; i < numOfPrompts; i++) {
		cout << i + 1 << ":";
		cout << prompts[i] << endl;
	}
}

//Allows user to see and choose from menu. Returns user's choice.
int menu::makeChoice() {
	int choice;
	printMenu();
	cout << "Make choice: ";
	choice = getInt(1, numOfPrompts);	
	return (choice - 1);

}


menuYN::menuYN(string givenPrompt) {
	prompt = givenPrompt;
}

int menuYN::makeChoice() {
	cout << prompt << endl;
	string input;
	int answer = -1;
	bool isValid = false;
	do {
		input = getString();
		string answery = "y";
		string answerY = "Y";
		string answerYes = "Yes";
		string answerYES = "YES";
		string answeryes = "yes";

		string answern = "n";
		string answerN = "N";
		string answerNo = "No";
		string answerNO = "NO";
		string answerno = "no";

		if ((input == answery) ||
			(input == answerY) ||
			(input == answerYes) ||
			(input == answerYES) ||
			(input == answeryes)) {
			answer = 1;
			isValid = true;
		} else if ((input == answern) ||
				(input == answerN) ||
				(input == answerNo) ||
				(input == answerNO) ||
				(input == answerno)) {
			answer = 0;
			isValid = true;
		}
		if (!isValid) {
			cout << "Invalid Input. Enter 'y' or 'n'" << endl;
		}
	} while (!isValid);

	return answer;
}
