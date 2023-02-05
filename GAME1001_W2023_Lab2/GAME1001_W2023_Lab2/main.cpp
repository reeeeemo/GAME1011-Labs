#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Character.h"
#include "Weapon.h"
#include "Armour.h"

// Functions created/used in this .cpp file.
bool IsInputOkay(std::vector<char> validInputs, std::string currentChoice);
void SetChoicesAllowed(int numOfOptions);
void CreateCharacter();
void InspectCharacter();
void CompareCharacters();


// Global variables.
static std::vector<Weapon> createdWeapons = {
	Weapon({"Lightning Strike", "Odin's Justice", "Power Outage"}, "Mjolnir", 15), 
	Weapon({ "Banana-SPLIT", "Rotate", "Mold...?" }, "Banana", 45),
	Weapon({"Hack", "Slash", "Why am I using a crowbar?"}, "Crowbar", 5)
};
static std::vector<Armour> createdArmour = {
	Armour("Just some plain 'ol starter armour", "Leather Garments", 2),
	Armour("Forged from the scales of a dragon.... It's a little chewed up though", "Chewed-up Dragon Armour", 25),
	Armour("...They never stop staring, watching, with that creepy smile that never leaves. Wake up.", "Human Skin", 0)
};

static std::vector<Character> createdCharacters;
static std::vector<char> choices = { '1', '2', '3', '4' };
static std::vector<char> choicesAllowed;

int main() {
	std::string choice;

	// Welcome message
	std::cout << "Welcome to the one-stop shop for customizing your character!\n\n";

	do {
		std::cout << "What would you like to do?\n";
		std::cout << "1. Create new Character\n2. Inspect a Character\n3. Compare 2 Characters\n4. Exit\n\n";


		// Just checking to ensure input is okay and won't crash program
		do { 
			std::cin >> choice;

			if (!std::cin.good()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\nPlease enter a valid number.\n";
			}

		} while (!IsInputOkay(choices, choice));


		// Which option should we choose.
		switch (choice[0]) {
		case '1': // 1. Create new Character
			if (createdCharacters.size() >= 3) {
				std::cout << "\nMax characters created has been made!\n";
				break;
			}
			CreateCharacter();
			break;
		case '2': // 2. Inspect a Character
			InspectCharacter();
			break;
		case '3': // 3. Compare 2 Characters
			CompareCharacters();
			break;
		default: // 4. Exit (or if somehow input slips past)
			break;
		}

	} while (choice[0] != '4');


	return 0;
}


// Input checker, ensuring that input is valid.
bool IsInputOkay(std::vector<char> choices, std::string currentChoice)
{
	// Checking size here so no error-checking is needing everytime in the for loop.
	if (currentChoice.size() > 1) { 
		std::cout << "\nError, input choice too long. Please try again.\n";
		return false;
	}

	// Checking all valid inputs
	for (char choice : choices) {
		if (currentChoice[0] == choice) { // If input is valid
			return true;
		}
	}

	// If the for loop found no valid input.
	std::cout << "\nError, invalid input choice. Please try again.\n";
	return false;
}

void SetChoicesAllowed(int numOfOptions) {
	std::vector<char> tempChoices;
	for (; numOfOptions >= 0; numOfOptions--) {
		tempChoices.push_back(choices[numOfOptions]);
	}
	choicesAllowed = tempChoices;
}


void CreateCharacter() {
	Character character;
	std::string input = "";
	double healthInput = 0.0;

	std::cout << "\nLets get started... What is your name?\n";
	std::cin >> input;

	character.SetName(input);

	// Checks to ensure health in between 1-100.
	do {
		std::cout << "\nHow much health do you have? (Between 1-100). Note that health will be rounded if decimal.\n";
		std::cin >> healthInput;

		if (!std::cin.good()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nPlease enter a valid number.\n";
		}
		else {
			healthInput = round(healthInput); // Rounding health so no errors are given if its a decimal, but we don't want maxHP to be a decimal.
		}
	} while (!(healthInput <= 100.0 && healthInput > 0.0));

	character.SetMaxHealth(healthInput);

	do {
		std::cout << "\nWhat is your species? Choose a number from this list:\n";
		
		// Could be made better, for now will work.
		std::cout << "\n1. Capybara\n2. Platypus\n3. Eldritch\n4. Baboon\n";

		std::cin >> input;
	} while (!IsInputOkay(choices,input));

	character.SetSpecies(std::stoi(input) - 1); // Also sets backstory :)

	do {
		std::cout << "\nChoose your starting weapon. Choose a number from this list:\n";

		// Could be made better, for now will work.
		std::cout << "\n1. " << createdWeapons[0].GetName() << 
			"\n2. " << createdWeapons[1].GetName() << 
			"\n3. " << createdWeapons[2].GetName() << "\n";

		std::cin >> input;
	} while (!IsInputOkay({'1','2','3'}, input));

	character.SetWeapon(createdWeapons[std::stoi(input) - 1]);

	do {
		std::cout << "\nChoose your starting armour. Choose a number from this list:\n";

		// Could be made better, for now will work.
		std::cout << "\n1. " << createdArmour[0].GetName() <<
			"\n2. " << createdArmour[1].GetName() <<
			"\n3. " << createdArmour[2].GetName() << "\n";

		std::cin >> input;
	} while (!IsInputOkay({ '1','2','3' }, input));

	character.SetArmour(createdArmour[std::stoi(input) - 1]);

	createdCharacters.push_back(character); // Finally, putting character in global vector.
}

void InspectCharacter() {
	std::string choice;
	int counter;
	
	do {
		counter = 1;
		std::cout << "Which character would you like to inspect?\n";

		for (Character character: createdCharacters) {
			std::cout << counter << ". " + character.GetName() << "\n";
			counter++;
		}

		std::cout << counter << ". Back\n";

		counter -= 1; // Putting the index back in bounds.

		// Choices currently allowed depedant on how many characters there are (extra is included for exit protocol)
		SetChoicesAllowed(counter);

		// Ensuring choice input is valid.
		do { 
			std::cin >> choice;
		} while (!IsInputOkay(choicesAllowed, choice));

		if (choice[0] != choicesAllowed.front()) { // counter goes backwards, therefore making Exit the first variable
			int index = (std::stoi(choice)) - 1; // So index does not go out of bounds.

			Character selectedCharacter = createdCharacters.at(index);
			do {
				std::cout << selectedCharacter;
				/*std::cout << "\nName: " << selectedCharacter->GetName() << "\n";
				std::cout << "\nSpecies: " << selectedCharacter->GetSpecies() << "\n";
				std::cout << "\nStory: " << selectedCharacter->GetBackstory() << "\n";
				std::cout << "\n\nCurrent Weapon: " << selectedCharacter.*/
				// Armour
				std::cout << "\n\nType '1' to go back.\n";
				std::cin >> choice;
			} while (!IsInputOkay({ '1' }, choice));
		}

	} while (choice[0] != choicesAllowed.front()); 

	std::cout << "\nGoing back to main menu...\n";
}

// Only compares once, before sending to the main menu.
void CompareCharacters() {
	int counter;
	std::string choice;
	Character character1;
	Character character2;
	do {
		counter = 1;
		std::cout << "Welcome to the character comparer! Please pick the first character to compare.\n";

		// Displays Characters
		for (Character character : createdCharacters) {
			std::cout << counter << ". " + character.GetName() << "\n";
			counter++;
		}

		counter -= 1; // There is no back button here.

		SetChoicesAllowed(counter); // Sets amount of choices allowed

		// Ensuring choice input is valid.
		do {
			std::cin >> choice;
		} while (!IsInputOkay(choicesAllowed, choice));

		// Picks character 1.
		character1 = createdCharacters[std::stoi(choice) - 1];

		std::cout << "Please pick the second character to compare!\n";
			
		// Displays Characters
		for (Character character : createdCharacters) {
			std::cout << counter << ". " + character.GetName() << "\n";
			counter++;
		}

		do {
			std::cin >> choice;
		} while (!IsInputOkay(choicesAllowed, choice));

		// Picks character 2.
		character2 = createdCharacters[std::stoi(choice) - 1];
		
		character1 == character2;

		break; 

	} while (choice[0] != choicesAllowed.front());

	std::cout << "\nGoing back to main menu...\n";
}