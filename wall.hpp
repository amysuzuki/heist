/************************************************************
** Project: Final
** Author: Amy Suzuki
** Date: March 16, 2019
** Description: This file contains the declaration of
** the class Wall, derived from Space, which doesn’t 
** allow users to enter or pass through. 
************************************************************/
#ifndef WALL_HPP
#define WALL_HPP

#define MAXITEMS 5
#include "space.hpp"

#include "itemlist.hpp"

class Wall: public Space {
	private:
	public:
		Wall();
		Wall(string, string);

		bool canEnter(ItemList* bag);
		Item* getItem(ItemList* bag);
	protected:
	
};

#endif
