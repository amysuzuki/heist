/* HEIST
 Author: Amy Suzuki
 Description: Wall is a derived class of Space. Walls can never be entered.
 */

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
