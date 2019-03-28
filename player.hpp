/************************************************************
** Project: Final
** Author: Amy Suzuki
** Date: March 16, 2019
** Description: This file contains the declaration of
** the Player class that tracks all player location, steps
** and ItemList (bag)
************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "space.hpp"
#include "item.hpp"
#include "menu.hpp"
#include "itemlist.hpp"
#include <vector>

using std::vector;

#define MAXITEMS 5

class Player {
	private:
		Space *location;
		int steps;
		ItemList* bag;

		Item* replaceItem(Item* newItem);

	public:
		Player();
		~Player();

		//Functions for location
		void setLocation(Space* newLocation);
		Space* getLocation();
		void move(Space *newLocation);

		//Function to track steps
		void incSteps();
		int getSteps();

		//Functions for Items
		Item* addItem(Item *newItem);
		bool findItem(string name);
		ItemList* getBag();

	protected:
};
#endif
