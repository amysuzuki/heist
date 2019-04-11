/* HEIST
 Author: Amy Suzuki
 Description: Painting is a derived class from Space which begins
 the game with an Item of type Painting. Players can only retrieve
 paintings if they carry a "Screwdriver" Item. Players can then replace
 paiting with any other Item in the game (if their bag is full).
 */

#ifndef PAINTING_HPP
#define PAINTING_HPP

#define MAXITEMS 5
#include "space.hpp"

class Painting: public Space{
	private:
		Item* painting;
		Item* getPainting(ItemList* bag);
	public:
		Painting();
		Painting(string, string, Item*);
		~Painting();

		bool canEnter(ItemList* bag);
		Item* getItem(ItemList* bag);
		void setItem(Item *newItem);
		
	protected:
};

#endif
