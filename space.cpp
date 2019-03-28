/************************************************************
** Project: Final
** Author: Amy Suzuki
** Date: March 16, 2019
** Description: This file contains the functions of
** the abstract class Space, which other objects are
** derived off of to create the game environment. 
************************************************************/
#include "space.hpp"
#include <iostream>
using std::cout;
using std::endl;

//Base constructor. Set all connections to null
Space::Space() {
	front = nullptr;
	back = nullptr;
	right = nullptr;
	left = nullptr;
	up = nullptr;
	down = nullptr;
}


Space::~Space() {
}

Space::Space (string givenName, string givenRoom, string givenPrompt) {
	name = givenName;
	room = givenRoom;
	prompt = givenPrompt;
	front = nullptr;
	back = nullptr;
	right = nullptr;
	left = nullptr;
	up = nullptr;
	down = nullptr;
}

//Return the amount of spaces the Space object is conencted to
int Space::getChoice() {
	int i = 0;
	if (front != nullptr) {
		i++;
	}
	if (back != nullptr) {
		i++;
	}
	if (right != nullptr) {
		i++;
	}
	if (left != nullptr) {
		i++;
	}
	if (up != nullptr) {
		i++;
	}
	if (down != nullptr) {
		i++;
	}
	return i;
}

//Getters and Setters
void Space::setItem(Item *object) {
}

string Space::getName() {
	return name;
}

string Space::getRoom() {
	return room;
}

string Space::getPrompt() {
	return prompt;
}

void Space::setFront (Space *area) {
	front = area;
}

void Space::setBack (Space *area) {
	back = area;
}

void Space::setRight (Space *area) {
	right = area;
}

void Space::setLeft (Space *area) {
	left = area;
}

void Space::setUp (Space *area) {
	up = area;
}

void Space::setDown (Space *area) {
	down = area;
}

Space* Space::getFront() {
	return front;
}

Space* Space::getBack() {
	return back;
}

Space* Space::getRight() {
	return right;
}

Space* Space::getLeft() {
	return left;
}

Space* Space::getUp() {
	return up;
}

Space* Space::getDown() {
	return down;
}

