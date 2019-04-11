/* HEIST
 Author: Amy Suzuki
 Description: Functions used to validate user input
 */

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
