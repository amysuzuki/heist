/* HEIST
 Author: Amy Suzuki
 Description: emptySpace is a derived Class of Space; no requirements
 to be entered, used to connect difference Spaces to each other.
 */

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
