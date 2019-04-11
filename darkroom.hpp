/* HEIST
 Author: Amy Suzuki
 Description: darkRoom is a derived Class of Space that requires the
 item "Flashlight" to be entered
 */

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
