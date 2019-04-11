/* HEIST
 Author: Amy Suzuki
 Description: darkRoom is a derived Class of Space that requires the
 item "Flashlight" to be entered
 */

#include "darkroom.hpp"

darkRoom::darkRoom() {
}

darkRoom::darkRoom(string givenName): Space() {
	name = givenName;
	room = givenName;
	string roomPrompt = "Walk into " + givenName;
	prompt = roomPrompt;
}

//DarkRoom requires a "Flashlight" in user bag to enter
bool darkRoom::canEnter(ItemList* bag) {
	string requisite = "Flashlight";
	ItemList *temp = bag;
	if (temp->object != nullptr) {
		while (((temp->object)->getName() != requisite) 
			&& (temp->nextObject != nullptr)) {
			temp = temp->nextObject;
		}
		if ((temp->object)->getName() == requisite) {
			return true;
		} else {
			cout << "It's too dark to step inside!" << endl;
			return false;
		}
	} else {
		cout << "It's too dark to step inside!" << endl;
		return false;
	}	
}

//No Item returned from darkRoom
Item* darkRoom::getItem(ItemList *bag) {
	return nullptr;
}

