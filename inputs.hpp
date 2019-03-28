/**********************************************************
** Project: Final
** Author: Amy Suzuki
** Date: January 25, 2019
** Description: This header file holds the declaration for 
** input validators
**********************************************************/

#ifndef INPUTS_HPP
#define INPUTS_HPP

#include <iostream>
#include <string>
#include <ctype.h>

using std::cout;
using std::cin;
using std::string;
using std::stoi;
using std::stof;
using std::endl;

int getInt (int min, int max);
float getFloat (float min, float max);
string getString ();
#endif
