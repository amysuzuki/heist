/************************************************************
** Project: Final
** Author: Amy Suzuki
** Date: March 16, 2019
** Description: This file contains the function of
** the class Painting, derived from Space, which
** holds a Painting Item in its space. 
************************************************************/
#include "painting.hpp"

//Constructors
Painting::Painting() {
}

//Painting Saces hold a Painting Item in its place
Painting::Painting(string givenName, 
				string givenRoom,
				Item* givenPainting): Space() {
	name = givenName;
	room = givenRoom;
	string wallPrompt = "Check the painting";
	prompt = wallPrompt;
	painting = givenPainting;
}

//Always return true; no restrictions on Painting space
bool Painting::canEnter(ItemList* bag) {
	return true;
}

//To replace the item stored at the painting space
void Painting::setItem(Item *newItem) {
	painting = newItem;
}

//Allow user to take painting if with you
Item* Painting::getItem(ItemList *bag) {
	if (painting != nullptr) { 
		cout << endl;
		cout << "You've found a " << painting->getName() << "!" << endl;
		string type = "PAINTING"; 

		//If a painting is stored in the space
		if (painting->getType() == type) {
			Item *temp = getPainting(bag);
			return temp;

		//If the painting has been replace with a regular item
		} else {
			string question = "Take it with you? (y/n)";
			menuYN askQuestion(question);
			int answer = askQuestion.makeChoice();
			if (answer == 1) {
				return painting;
			} else {
				return nullptr;
			}
		}
	}
}

//Checks and returns painting Item to user if requirements are met
Item* Painting::getPainting(ItemList *bag) {
	string question = "Remove Painting? (y/n)";
	menuYN askQuestion(question);
	int answer = askQuestion.makeChoice();

	if (answer == 1) {

		//Check for requirement
		string requisite = "Screwdriver";
		ItemList *temp = bag;

		//Look for "screwdriver" Item
		while (((temp->object)->getName() != requisite) 
			&& (temp->nextObject != nullptr)) {
			temp = temp->nextObject;
		}

		if ((temp->object)->getName() == requisite) {
			Item *temp = painting;
			painting = nullptr;
			return temp;
		} else {
			cout << "You can't get it off the wall!" << endl;
			return nullptr;
		}
	} else {

		//Answer No
		return nullptr;
	}
}

//Deconstructor. Delete painting if it remains in the space
Painting::~Painting() {
	if (painting != nullptr) {
		delete painting;
	}
}
