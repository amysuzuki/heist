/************************************************************
** Project: Final
** Author: Amy Suzuki
** Date: March 16, 2019
** Description: This file contains the declaration of
** the class Painting, derived from Space, which
** holds a Painting Item in its space. 
************************************************************/

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
