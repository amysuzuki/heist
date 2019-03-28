/************************************************************
** Project: Final
** Author: Amy Suzuki
** Date: March 16, 2019
** Description: This file contains the declaration of the 
** of the Item class that stores the name and type of 
** an Item used in the game. 
************************************************************/
#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
using std::string;

class Item {
	private:
		string name;
		string type;
	public:
		Item(string givenName, string typeName);
		string getName();
		string getType();	
	protected:
};

#endif
