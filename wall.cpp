/************************************************************
** Project: Final
** Author: Amy Suzuki
** Date: March 16, 2019
** Description: This file contains the functions of
** the class Wall, derived from Space, which doesn’t 
** allow users to enter or pass through. 
************************************************************/
#include "wall.hpp"

Wall::Wall() {
}

Wall::Wall(string givenName, string givenRoom): Space() {
	name = givenName;
	room = givenRoom;
	string wallPrompt = "Check the " + givenName;
	prompt = wallPrompt;
}

//Always return false; cannot be entered
bool Wall::canEnter(ItemList* bag) {
	cout << "It's just an empty wall..." << endl;
	return false;
}

//Always return nullptr (no Item stored at wall)
Item* Wall::getItem(ItemList* bag) {
	return nullptr;
}

