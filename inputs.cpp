/**********************************************************
** Project: Final`
** Author: Amy Suzuki
** Date: January 19, 2019
** Description: The following file holds the function(s)
** used for input validation.
***********************************************************/

#include "inputs.hpp"


//Input validation for integers within a user defined range
int getInt (int min, int max) {

	string inputString;
	bool isInt = false;
	bool isValid = false;
	int outputInt;

	
	while ((isInt == false) || (isValid == false)) {
		//Get Input
		cin >> inputString;

		//Check to see if input is a number
		int i = 0;

		if (inputString[i] == '-' ) {
			i = 1;
		}

		while (isdigit(inputString[i])) {
			i++;
		}

		//If input is a number, check to see if in range
		if (i == inputString.length()) {
			isInt = true;
			outputInt = stoi(inputString);
			if ((outputInt >= min) && (outputInt <= max)) {
				isValid = true;

			//Input is not in range
			} else {
				isValid = false;
				cout << "Number not within range. Input new number: ";
			}		

		//input is not a number
		 } else {
			isInt = false;
			cout << "Not a valid number. Input new number: ";
		}
	}

	return outputInt;
}

//Input validator for floats within a given range
float getFloat (float min, float max) {
	string inputString;
	float outputFloat;
	bool isFloat = false;
	bool isValid = false;
	int point = 0;
	int counter = 0;

	while ((isFloat == false) || (isValid == false)) {
		cin >> inputString;

		//Check to see that all inputs are numbers and no more than 1 point
		for (int i = 0; i < inputString.length(); i++) {
			if ((i == 0) && (inputString[i] == '-')) {
				counter++;
			}
			if (isdigit(inputString[i]) || (inputString[i] == '.')) {
				counter++;
			}
			if (inputString[i] == '.') {
				point++;
			}
		}

		//If all inputs are numbers or a point
		if ((counter == inputString.length()) && (point < 2)) {
			isFloat = true;
			outputFloat = stof(inputString);

			//Check to see that number is in range
			if ((outputFloat >= min) && (outputFloat <= max)) {
				isValid = true;
			} else {
				isValid = false;
				cout << "Number not within range. Input new float: ";
				cin.clear();
			}
		} else {
			isFloat = false;
			cout << "Not a float. Input a new number: ";
			cin.clear();
		}
		counter = 0;
		point = 0;
	}
	return outputFloat;	
}	

//Input Validator for strings. Reprompt for blank string
string getString() {
	string input;
	bool isValid;
	do {
		cin.clear();
		getline(cin, input);
		int numOfBlanks = 0;
		for (int i = 0; i < input.length(); i++) {
			if ((input[i] == ' ') || (input[i] == '\n')) {
				numOfBlanks++;
			}
		}
		if (numOfBlanks == input.length()) {
			isValid = false;
		} else {
			isValid = true;
		}
	} while (!isValid);
	return input;
}

