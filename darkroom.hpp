/************************************************************
** Project: Final
** Author: Amy Suzuki
** Date: March 16, 2019
** Description: This file contains the declaration of the class
** type darkRoom, a derived Space, that requires a flashlight
** Item to enter. 
************************************************************/
#ifndef DARKROOM_HPP
#define DARKROOM_HPP

#include "space.hpp"

class darkRoom: public Space{
	private:
	public:
		darkRoom();
		darkRoom(string givenName);
		
		bool canEnter(ItemList* bag);
		Item* getItem(ItemList* bag);
};

#endif
