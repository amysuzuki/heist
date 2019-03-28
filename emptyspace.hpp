/************************************************************
** Project: Final
** Author: Amy Suzuki
** Date: March 16, 2019
** Description: This file contains the declaration of the 
** class type emptySpace, derived from Space
**  that holds no items or restriction to enter. 
************************************************************/
#ifndef EMPTYSPACE_HPP
#define EMPTYSPACE_HPP

#include "space.hpp"

class emptySpace: public Space{
	private:
	public:
		emptySpace();
		emptySpace(string giveName, string roomName, string givenPrompt);

		bool canEnter(ItemList* bag);
		Item* getItem(ItemList* bag);
	protected:
};
#endif
