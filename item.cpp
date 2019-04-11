/* HEIST
 Author: Amy Suzuki
 Description: The Item class creates an Object with a name and type.
 Items can be carried by a player or stored in particular Spaces.
 */

#include "item.hpp"

//Constructor. Name and type must be set during construction
Item::Item(string givenName, string givenType) {
	name = givenName;
	type = givenType;
}

//Getters
string Item::getName() {
	return name;
}

string Item::getType() {
	return type;
}
