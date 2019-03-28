/************************************************************
** Project: Final
** Author: Amy Suzuki
** Date: March 16, 2019
** Description: ItemList is a struct that stores Item
** class objects in a linked list. 
************************************************************/
#ifndef ITEMLIST_HPP
#define ITEMLIST_HPP

#include "item.hpp"

struct ItemList {
	Item* object;
	ItemList* nextObject;
};

#endif
