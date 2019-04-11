/* HEIST
 Author: Amy Suzuki
 Description: The hiddenObject class is a derived class from
 Space. hiddenObjects can hold anItem object that a player
 can retrieve or replace.
 */

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
