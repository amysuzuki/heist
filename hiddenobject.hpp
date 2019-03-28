/************************************************************
** Project: Final
** Author: Amy Suzuki
** Date: March 16, 2019
** Description: This file contains the declaration of the 
** of the hiddenObject class, a derived object from Space,
** that contains a hidden Item at the space. 
************************************************************/
#ifndef HIDDENOBJECT_HPP
#define HIDDENOBJECT_HPP

#define MAXITEMS 5
#include "space.hpp"

class hiddenObject: public Space{
	private:
		Item* storedObject;
	public:
		hiddenObject();
		hiddenObject(string givenName, string roomName, Item* givenObject);
		~hiddenObject();
	
		bool canEnter(ItemList* bag);
		Item* getItem(ItemList* bag);
		void setItem(Item *newItem);		
};

#endif
