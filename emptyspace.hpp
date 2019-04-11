/* HEIST
 Author: Amy Suzuki
 Description: emptySpace is a derived Class of Space; no requirements
 to be entered, used to connect difference Spaces to each other.
 */

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
