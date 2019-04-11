/* HEIST
 Author: Amy Suzuki
 Description: The Item class creates an Object with a name and type.
 Items can be carried by a player or stored in particular Spaces.
 */

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
