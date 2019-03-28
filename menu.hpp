/**********************************************************
** Project: Final
** Author: Amy Suzuki
** Date: January 19, 2019
** Description: The following function declares the class type
** Menu that allows users to create a menu and make selections.
***********************************************************/
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
