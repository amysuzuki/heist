/* HEIST
 Author: Amy Suzuki
 Description: Wall is a derived class of Space. Walls can never be entered.
 */

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

