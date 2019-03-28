/************************************************************
** Project: Final
** Author: Amy Suzuki
** Date: March 16, 2019
** Description: This file contains the functions used in
** the class lockedRoom, derived from Space, which
** requires a key Item to enter. 
************************************************************/
#include "lockedroom.hpp"
//Constructors

lockedRoom::lockedRoom() : Space() {
	//lockedRooms only need to be opened once.
	isOpen = false;
}

lockedRoom::lockedRoom(string givenName): Space() {
	name = givenName;
	room = givenName;
	string setPrompt = "Check " + givenName;
	prompt = setPrompt;
	isOpen = false;
}

//Return true if user can ener the room.
bool lockedRoom::canEnter(ItemList* bag) {

	string requisite = "Key";
	if (!isOpen) {

		//Check to see if user has "key" item in bag
		ItemList *temp = bag;
		while (((temp->object)->getName() != requisite) 
			&& (temp->nextObject != nullptr)) {
			temp = temp->nextObject;
		}

		if ((temp->object)->getName() == requisite) {
			isOpen = true;
			return true;

		//If user does not have key, return false
		} else {
			cout << "The Door is locked!" << endl;
			return false;
		}

	//If room has been opened once, return true
	} else {
		return true;
	}
}

//No items stored at lockedRoom.
Item* lockedRoom::getItem(ItemList* bag) {
	return nullptr;
}

