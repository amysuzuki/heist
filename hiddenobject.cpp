/************************************************************
** Project: Final
** Author: Amy Suzuki
** Date: March 16, 2019
** Description: This file contains the functions of the 
** of the hiddenObject class, a derived object from Space,
** that contains a hidden Item at the space. 
************************************************************/
#include "hiddenobject.hpp"

//Constructors
hiddenObject::hiddenObject(): Space() {
}

hiddenObject::hiddenObject(string givenName, string roomName, Item* givenObject) : Space() {
	name = givenName;
	room = roomName;
	string setPrompt = "Check out the " + givenName;
	prompt = setPrompt;
	storedObject = givenObject;
}

//No requirements to enter this space
bool hiddenObject::canEnter(ItemList* bag) {
	return true;
}

//Allow user to take new item
Item* hiddenObject::getItem(ItemList *bag) {

	//Check to make sure item is still there
	if (storedObject != nullptr) {
		cout << endl;
		cout << "You found a " << storedObject->getName() << "!" << endl;

		//Allow user to take item
		string question = "Take it with you? (y/n)";
		menuYN askQuestion(question);
		int answer = askQuestion.makeChoice();
		if (answer == 1) {
			Item* temp = storedObject;
		
			//Remove item from class object
			storedObject = nullptr;
			return temp;

		} else {
			return nullptr;
		}
	} else {
		return nullptr;
	}
}

//Replace item if user has to switch items
void hiddenObject::setItem(Item *newItem) {

	//Error: Two items stored in same space
	if (storedObject != nullptr) {
		cout << "ERROR; No space to store Item" << endl;
	} else {
		storedObject = newItem;
	}
}

//Delete Item 
hiddenObject::~hiddenObject() {
	if (storedObject != nullptr) {
		delete storedObject;
	}
}
