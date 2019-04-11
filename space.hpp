/* HEIST
 Author: Amy Suzuki
 Description: The Space class is an abstract class used to navigate
 through the game. Each space can be connected to other spaces; each derived
 space vary in the Items they hold (if any) and their accessibility requirements.
 */

#ifndef SPACE_HPP
#define SPACE_HPP

#define MAXITEMS 5

#include <string>
#include "item.hpp"
using std::string;

#include "itemlist.hpp"
#include "menu.hpp"
#include "inputs.hpp"

class Space {
	private:
	public:

		//Constructor
		Space();

		//Destructor(derived Spaces that contain Items use their own destructor) 
		virtual ~Space();
		Space(string, string, string);

		string getName();
		string getRoom();
		string getPrompt();


		void setFront (Space*);
		void setBack (Space*);
		void setRight (Space*);
		void setLeft (Space*);
		void setUp (Space*);
		void setDown (Space*);	

		Space* getFront();
		Space* getBack();
		Space* getRight();
		Space* getLeft();
		Space* getUp();
		Space* getDown();

		

		virtual bool canEnter(ItemList *bag) = 0;
		virtual Item* getItem(ItemList *bag) = 0;
		virtual void setItem(Item* object);
		int getChoice(); 

	protected:
		string name;
		string room;
		string prompt;

		Space *front;
		Space *back;
		Space *right;
		Space *left;
		Space *up;
		Space *down;
};


#endif
