/************************************************************
** Project: Final
** Author: Amy Suzuki
** Date: March 16, 2019
** Description: This file contains the functions used by
** the class type emptySpace that holds no items or 
** restriction to enter. 
************************************************************/
#include "emptyspace.hpp"

emptySpace::emptySpace() : Space() {
}

emptySpace::emptySpace (string givenName, string roomName, string givenPrompt): Space() {
	name = givenName;
	room = roomName;
	prompt = givenPrompt;
}

//No requirements to enter
bool emptySpace::canEnter (ItemList* bag) {
	return true;
}

//No Items stored
Item* emptySpace::getItem(ItemList* bag) {
	return nullptr;
}
