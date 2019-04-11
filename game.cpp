/* HEIST
 Author: Amy Suzuki
 Description: The game class connects all spaces together,
 and runs the entire game Heist. Game runs at construction.
 */

#include "game.hpp"

//Consructor
Game::Game() {
    
	//Create Player
	user = new Player();

	//Add and connect all spaces
	addSpaces();
	connectSpaces();

	bool isFinished = false;

	//Only start if there's a space loaded
	if (!house.empty()) {

		//Buffer intro story
		introduction();

		//Set the user to the starting location
		user->setLocation(house.at(0));
		start = house.at(0);

		//Run until limit reached or game ended
		while ((user->getSteps() < MAX_STEPS) && !isFinished) {

			//Offer to show map to User
			showMap();

			//Show where User is and remaining time
			repeatMessage();

			//Move user
			move();
			
			//If user is back to start location, check if win condition met
			if (user->getLocation() == start) {

				//Check for the right painting
				string answer = "Painting: 'La Belle Jardiniere'";
				if (user->findItem(answer)) {
					cout << endl;
					cout << "***" << endl;
					cout << "'YOU GOT IT!'" << endl;	
					cout << "'Hold one; let's get you out of there!'" << endl;
					isFinished = true;
				} else {

					//If user has not won yet
					cout << endl;
					cout << "'Why are you back here?'" << endl;	
					cout << "'Do you have the painting?";
					cout << " Nope doesn't seem like it'" << endl;
				}
			}
		}

		//Game Lost Message
		if (!isFinished) {
			cout << endl;
			cout << "'HEY YOU THERE'" << endl;
			cout << "'WHAT ARE YOU DOING HERE'" << endl;
			cout << endl;
			cout << "HEIST FAILED" << endl;
			cout << "GAME OVER" << endl;
			cout << endl;
		} else {

			//Game Won Message
			cout << endl;
			cout << "HEIST COMPLETED. YOU WIN" << endl;
		}
	}
}

//Deconstructor
Game::~Game(){
	//Set User location to null
	user->setLocation(nullptr);

	//Delete all spaces
	while (!house.empty()) {
		Space *temp = house.back();
		house.pop_back();
		delete temp;
	}

	//Delete player
	delete user;

}

//Add Spaces to game from file
void Game::addSpaces() {
	ifstream inputFile(SPACES_FILE);

	if (!inputFile) {
		cout << "Error uploading spaces" << endl;
	} else {
		string tag;
		string name; 
		string room;
		string prompt;
		string object;

		while (getline(inputFile, tag)) {

			//Each space should start with a tag
			char checkTag = '/';
			if ((tag.length() > 0) && (tag.at(0) == checkTag)) {

				//Space Type
				string empty = "emptySpace";
				string wall = "Wall";
				string hidden = "hiddenObject";
				string dark = "darkRoom";
				string painting = "Painting";
				string locked = "lockedRoom";
				string type;
				getline(inputFile, type);
				Space *temp = nullptr;

				//Check Space type
				//EMPTYSPACE
				if (type == empty) {
					getline(inputFile, name);
					getline(inputFile, room);
					getline(inputFile, prompt);
					temp = makeEmpty(name, room, prompt);	
					house.push_back(temp);

				//WALL
				} else if (type == wall) {
					getline(inputFile, name);
					getline(inputFile, room);
					temp = makeWall(name, room);
					house.push_back(temp);

				//hiddenItem
				} else if (type == hidden) {
					getline(inputFile, name);
					getline(inputFile, room);
					getline(inputFile, object);
					temp = makeHidden(name, room, object);
					house.push_back(temp);

				//darkRoom
				} else if (type == dark) {
					getline(inputFile, name);
					temp = makeDark(name);
					house.push_back(temp);

				//lockedRoom
				} else if (type == locked) {
					getline(inputFile, name);
					temp = makeLocked(name);
					house.push_back(temp);

				//Painting
				} else if (type == painting) {
					getline(inputFile, name);
					getline(inputFile, room);
					temp = makePainting(name, room);
					house.push_back(temp);
				}
			}
		}
		inputFile.close();
	}
}

//Functions to make Spaces
Space* Game::makeEmpty(string& name, string& location, string& prompt){
	Space* temp = new emptySpace(name, location, prompt);
	return temp;
}

Space* Game::makeWall(string& name, string& location) {
	Space *temp = new Wall(name, location);
	return temp;
}

Space* Game::makeHidden(string& name, string& room, string& object) {
	string type = "NORMAL";
	Item *tempItem = new Item(object, type);
	Space *temp = new hiddenObject(name, room, tempItem);
	return temp;
}

Space* Game::makeDark(string& name) {
	Space *temp = new darkRoom(name);
	return temp;
}

Space* Game::makeLocked(string& name) {
	Space *temp = new lockedRoom(name);
	return temp;
}

Space* Game::makePainting(string& name, string& room) {
	string type = "PAINTING";
	Item *tempItem = new Item(name, type);
	Space *temp = new Painting(name, room, tempItem);
	return temp;
}

//Connect all spaces uploaded from file
void Game::connectSpaces() {
	ifstream inputFile(CONNECT_FILE);
	if (!inputFile) {
		cout << "Error connecting spaces from file" << endl;
	} else {
		string space1;
		string command;
		string space2;

		//Get information from file
		while (getline(inputFile, space1)) {
			bool isNumber = true;

			//Make sure the first line is a space
			if (space1.length() > 0 ) {
				for (int i = 0; i < space1.length(); i++) {
					if (!isdigit(space1.at(i))) {
						isNumber = false;
					}
				}
				
				//Read in the other space and the relation
				if (isNumber) {
					getline(inputFile, command);
					getline(inputFile, space2);
					connectRooms(space1, command, space2);
				}
			}
		}
	}
}

//Connect two rooms together
void Game::connectRooms(string &space1, string &location, string &space2) {

	//All possible space relations
	string up = "UP";
	string down = "DOWN";
	string front = "FRONT";
	string back = "BACK";
	string right = "RIGHT";
	string left = "LEFT";

	int room1 = std::stoi(space1);
	int room2 = std::stoi(space2);

	if (location == up) {
		house[room1]->setUp(house[room2]);
	} else if (location == down) {
		house[room1]->setDown(house[room2]);
	} else if (location == front) {
		house[room1]->setFront(house[room2]);
	} else if (location == back) {
		house[room1]->setBack(house[room2]);
	} else if (location == right) {
		house[room1]->setRight(house[room2]);
	} else if (location == left) {
		house[room1]->setLeft(house[room2]);
	} else {
		cout << "ERROR connecting " << space1 << " and " << space2 << endl;
	}

}

//Displays a menu of possible options to move toward. Returns a new location
Space* Game::moveMenu() {

	Space *currentLocation = user->getLocation();
	Space *newLocation = nullptr;

	//If the room is connected to another space	
	if (currentLocation->getChoice() > 0 ) {

		Space **locations = new Space*[currentLocation->getChoice()];
		menu options(currentLocation->getChoice());
		
		//Check all possible choices
		int i = 0;
		if (currentLocation->getFront() != nullptr) {
			locations[i] = currentLocation->getFront();
			i++;
		}
		
		if (currentLocation->getBack() != nullptr) {
			locations[i] = currentLocation->getBack();
			i++;
		}
	
		if (currentLocation->getRight() != nullptr) {
			locations[i] = currentLocation->getRight();
			i++;
		}
	
		if (currentLocation->getLeft() != nullptr) {
			locations[i] = currentLocation->getLeft();
			i++;
		}
	
		if (currentLocation->getUp() != nullptr) {
			locations[i] = currentLocation->getUp();
			i++;
		}

		if (currentLocation->getDown() != nullptr) {
			locations[i] = currentLocation->getDown();
			i++;
		}

		//Create menu
		for (int j = 0; j < i; j++) {
			options.setPrompt(j, (locations[j])->getPrompt());
		}	
		cout << endl;	
		int selection = options.makeChoice();
	
		newLocation = locations[selection];
		delete [] locations;

	//If space is not connected, move back to start location
	} else {
		cout << endl;
		cout << "Oops! No where to go from here." << endl;
		cout << "Lets go back to where we started. " << endl;
		newLocation = start;
	}
	return newLocation;

}

//Move User to a new location. 
void Game::move() {
	bool canEnter = false;
	do {
		//Let user select a new location
		Space *newLocation = moveMenu();
		if (newLocation != nullptr) {

			//Check if user can enter the new room
			canEnter = newLocation->canEnter(user->getBag());

			if (canEnter) {
				user->move(newLocation);

				//Check and exchange items as neccessary
				Item* temp = newLocation->getItem(user->getBag());
				if (temp != nullptr) {
					Item* playerTemp = user->addItem(temp);
					newLocation->setItem(playerTemp);	
				} 

			//User is missing requirements to enter room
			} else {
				user->incSteps();
			}

		//No place to move
		} else {
			cout << "Error in move()" << endl;
			canEnter = true;
		}
	} while (!canEnter);

}

//Upload Introduction story and show to user
void Game::introduction() {
	ifstream inputFile(INTRO_FILE);
	if (!inputFile) {
		cout << "Error Uploading File" << endl;
	} else {
		string newline;
		while (getline(inputFile, newline)) {
			if (newline.length() > 0) {
				intro.push_back(newline);
			}
		}
		cout << endl;
		bufferStory(intro);
	inputFile.close();
	}
}

//Display a story to user. 
void Game::bufferStory(vector <string> story) {
	string prompt = "PROMPT";
	string response; 
	cin.ignore(100, '\n');
	for (int i = 0; i < story.size(); i++) {
		if (story.at(i) != prompt) {
			cout << story.at(i) << endl;
		} else {
			cout << "Press enter to continue" << endl;
			getline(cin, response);
		}
	}
}

//Show User status at the beginning of each move
void Game::repeatMessage() {
	cout << endl;
	cout << "***" << endl;
	cout << MAX_STEPS - user->getSteps();
	cout << " minutes left until the guards make their rounds" << endl;
	cout << "You're in ";
	cout << (user->getLocation())->getRoom() << endl;
}

//Give option to use to see map with location
void Game::showMap() {
	cout << endl;
	string prompt = "See map? (y/n)";
	menuYN map(prompt);
	int choice = map.makeChoice();

	//Upload map from file
	if (choice == 1) {
		ifstream inputFile(MAP_FILE);

		if (!inputFile) {
			cout << "Error uploading spaces" << endl;
		} else {
			//Display Map
			string line;
			while (getline(inputFile, line)) {
				cout << line << endl;
			}
			cout << endl;

			//Tell user current location
			cout << "You are at the ";
			cout << user->getLocation()->getName();
			cout << " in ";
			cout << user->getLocation()->getRoom() << endl;
			inputFile.close();
		}
	}
}
