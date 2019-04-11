/* HEIST
 Author: Amy Suzuki
 Description: lockedRoom is a derived class of Space which
 requires the Item "Key" to be entered. 
 */

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

