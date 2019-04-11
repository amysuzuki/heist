/* HEIST
 Author: Amy Suzuki
 Description: The Player Class stores information of the single player
 in the game, including their location, total steps they have taken, and
 Item linked List (bag).
 */

#include "player.hpp"

//Constructor
Player::Player() {
	bag = new ItemList;
	bag->object = nullptr;
	bag->nextObject = nullptr;
	steps = 0;
}

//Destructor
Player::~Player() {
	if (bag->object != nullptr) {
		ItemList* temp = bag;
		while (temp->nextObject != nullptr) {
			bag = bag->nextObject;
			delete temp->object;
			delete temp;
			temp = bag;
		}
		delete bag->object;
	}
	delete bag;
}

ItemList* Player::getBag() {
	return bag;
}

void Player::setLocation(Space* newLocation) {
	location = newLocation;
}

//Change locatio of User
void Player::move(Space* newLocation) {
	location = newLocation;
	steps++;
}

//Increment steps during failed moves
void Player::incSteps() {
	steps++;
}

int Player::getSteps() {
	return steps;
}


Space* Player::getLocation() {
	return location;
}

//Return nullptr if item added. Return Item if replaced or not added
Item* Player::addItem(Item *newItem) {
	int i = 1;
	ItemList* temp = bag;

	//Check to see first ItemList is open
	if (temp->object == nullptr) {
		temp->object = newItem;
		return nullptr;	
	} else {

		//Check to see if space in bag
		while ((temp->nextObject != nullptr) && (i < MAXITEMS)) {
			temp = temp->nextObject;
			i++;
		}

		//If there is space in bag, create node and add to linked list 
		if ((temp->nextObject == nullptr) && (i < MAXITEMS))  {
			ItemList *newNode = new ItemList;
			newNode->object = newItem;
			newNode->nextObject = nullptr;
			temp->nextObject = newNode;
			return nullptr;

		//If there is no bag, replace or return Item
		} else {
			cout << "Your bag is full." << endl;
			string prompt = "Would you like to replace an item? (y/n) ";
			menuYN replace(prompt);
			int choice = replace.makeChoice(); 
			if (choice == 1) {
				Item *sendback = replaceItem(newItem);
				return sendback;
			} else {
				return newItem;
			}
		}
	}
	return nullptr;
}

//Return true if item found in linked list. False if not
bool Player::findItem(string item) {
	ItemList* temp = bag;
	bool foundItem = false;
	if (temp->object != nullptr) {

		//Traverse linked list to find Item
		if ((temp->object)->getName() == item) {
			foundItem = true;
		}
		while ((temp->nextObject != nullptr) && !foundItem) {
			temp = temp->nextObject;
			if ((temp->object)->getName() == item){
				foundItem = true;
			} 
		}
		return foundItem;
	} else {
		return false;
	}
}

//Replace objects in list and return Item getting removed from bag
Item* Player::replaceItem(Item *newItem) {
	vector <string> choices;
	ItemList *temp = bag;
	Item *removeItem;

	//Create a menu of current items
	while (temp->nextObject != nullptr) {
		choices.push_back((temp->object)->getName());
		temp = temp->nextObject;
	}
	choices.push_back((temp->object)->getName());
	menu replace(choices.size());
	for (int i = 0; i < choices.size(); i++) {
		replace.setPrompt(i, choices.at(i));
	}
	int choice = replace.makeChoice();

	//Replace items
	temp = bag;
	while ((temp->object)->getName() != choices.at(choice)) {
		temp = temp->nextObject;
	}
	removeItem = temp->object;
	temp->object = newItem;

	//Return removed item.
	return removeItem;
}
