/************************************************************
** Project: Final
** Author: Amy Suzuki
** Date: March 16, 2019
** Description: This file contains the function of the 
** of the Item class that stores the name and type of 
** an Item used in the game. 
************************************************************/
#include "item.hpp"

//Constructor. Name and type must be set during construction
Item::Item(string givenName, string givenType) {
	name = givenName;
	type = givenType;
}

//Getters
string Item::getName() {
	return name;
}

string Item::getType() {
	return type;
}
