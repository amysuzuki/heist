/* HEIST
 Author: Amy Suzuki
 Description: ItemList is a structure used to form a
 linked list of Items.
 */

#ifndef ITEMLIST_HPP
#define ITEMLIST_HPP

#include "item.hpp"

struct ItemList {
	Item* object;
	ItemList* nextObject;
};

#endif
