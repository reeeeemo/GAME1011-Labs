#include "DisplayMenu.h"


void DisplayMenu::Init() {
	std::cout << "Welcome to the achievement holder!\n";
}


void DisplayMenu::ChangeMenuState(display_menu menu_choice) {
	previousMenu.push(currentMenu);
	currentMenu = menu_choice;
	DisplayScreen();
}

void DisplayMenu::GoBackMenu() {
	currentMenu = previousMenu.top();
	previousMenu.pop();
	DisplayScreen();
}

void DisplayMenu::DisplayScreen() {
	switch (currentMenu) {
	case CHOOSE_PLATFORM:
		std::cout << "\nWhat would you like to do?\n";
		std::cout << "1. Access Platforms\n" << "2. Add Platform\n" << "3. Remove Platform\n" << "4. Exit Program\n";
		break;
	case ADD_PLATFORM:
		std::cout << "Type the name of the platform you would like to add followed by the manufacturer\n";
		break;
	case DELETE_PLATFORM:
		std::cout << "What platform would you like to delete?\n";
		break;
	case CHOOSE_GAME:
		std::cout << "\nWhat would you like to do?\n";
		std::cout << "1. Access Games\n" << "2. Add Game\n" << "3. Remove Game\n" << "4. Go Back\n";
		break;
	case ADD_GAME:
		std::cout << "Type the name of the game you would like to add followed by the developer and publisher \n";
		break;
	case DELETE_GAME:
		std::cout << "What game would you like to delete? \n";
		break;
	case CHOOSE_ACHIEVEMENT:
		std::cout << "\nWhat would you like to do?\n";
		std::cout << "1. Access Achievements\n" << "2. Add Achievement\n" << "3. Remove Achievements\n" << "4. Go Back\n";
		break;
	case ADD_ACHIEVEMENT:
		std::cout << "Type the name of the achievement you would like to add followed by the description, and the score value (number) \n";
		break;
	case DELETE_ACHIEVEMENT:
		std::cout << "What achievement would you like to delete? \n";
		break;
	case EXIT:
		std::cout << "Goodbye, exiting program...\n";
		break;
	}
}

bool DisplayMenu::isValidInput(int choice) {
	return true;
}

int DisplayMenu::GetUserChoice() {
	return user_choice;
}

bool DisplayMenu::IsExiting()
{
	if (currentMenu == EXIT)
	{
		return true;
	} else
	{
		return false;
	}
}
