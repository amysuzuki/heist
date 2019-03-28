/************************************************************
** Project: Final
** Author: Amy Suzuki
** Date: March 16, 2019
** Description: This file contains the declaration of
** the class lockedRoom, derived from Space, which
** requires a key Item to enter. 
************************************************************/
#ifndef LOCKEDROOM_HPP
#define LOCKEDROOM_HPP

#include "space.hpp"
#define MAXITEMS 5

class lockedRoom: public Space{
	private:
		bool isOpen;
	public:
		lockedRoom();
		lockedRoom(string givenName);

		bool canEnter(ItemList* bag);
		Item* getItem(ItemList* bag);
	protected:

};

#endif
