/* HEIST
 Author: Amy Suzuki
 Description: The menu class creates a menu and allows user to make
 selections from the menu. The menu class should be used for questions
 with multiple answers. menuYN should be used for Yes/No questions.
 */

#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <string>
#include "inputs.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::string;

class menu {
	private:
		int numOfPrompts;
		string *prompts;

		void printMenu();

	public:
		//Constructor
		menu (int number);

		//Destructor
		~menu();

		void setPrompt(int number, string prompt);
		int makeChoice();
};

class menuYN {
	private:
		string prompt;
	public:
		menuYN(string givenPrompt);
		int makeChoice();
};

#endif
