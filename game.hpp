/************************************************************
** Project: Final
** Author: Amy Suzuki
** Date: March 16, 2019
** Description: This file contains the declaration of the 
** of the game class that will hold all data and run
** the HEIST game. 
************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <queue>

#include "player.hpp"

//All space types
#include "space.hpp"
#include "wall.hpp"
#include "darkroom.hpp"
#include "painting.hpp"
#include "lockedroom.hpp"
#include "hiddenobject.hpp"
#include "emptyspace.hpp"

#include "inputs.hpp"
#include "menu.hpp"

//Import game data from file
#define SPACES_FILE "space.txt"
#define CONNECT_FILE "connect.txt"
#define INTRO_FILE "intro.txt"
#define MAP_FILE "map.txt"
#define MAX_STEPS 30

using std::string;
using std::vector;
using std::queue;
using std::ifstream;

class Game{
	private:
		Player* user;
		vector <Space*> house;
		vector <string> intro;
		queue <string> plot;

		//Store the starting location of game
		Space* start;

		Space* moveMenu();

		//Add all spaces to house
		void addSpaces();
		void connectSpaces();
		void connectRooms(string&, string&, string&);

		//Show story to user
		void introduction();
		void bufferStory(vector <string> story);

		//Update User on location
		void repeatMessage();
		void showMap();

		//Make Space Objects
		Space* makeEmpty(string&, string&, string&);
		Space* makeWall(string&, string&);
		Space* makeHidden(string&, string&, string&);
		Space* makeDark(string&);
		Space* makePainting(string&, string&);
		Space* makeLocked(string&);

	public:

		Game();
		~Game();
		void move();

	protected:

};
#endif
