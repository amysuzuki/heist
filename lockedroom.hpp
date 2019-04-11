/* HEIST
 Author: Amy Suzuki
 Description: lockedRoom is a derived class of Space which
 requires the Item "Key" to be entered.
 */

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
