#pragma once
#ifndef __DISPLAYMENU_H__
#define __DISPLAYMENU_H__

#include <stack>
#include <iostream>
#include <map>
#include <vector>

enum display_menu { // enums for all the menus going to be displayed
	CHOOSE_PLATFORM, ADD_PLATFORM, DELETE_PLATFORM, 
	CHOOSE_GAME, ADD_GAME, DELETE_GAME,
	CHOOSE_ACHIEVEMENT, ADD_ACHIEVEMENT, DELETE_ACHIEVEMENT,
	EXIT
};


class DisplayMenu {
public:
	void Init();
	void ChangeMenuState(display_menu menu_choice);
	void GoBackMenu();
	void DisplayScreen();
	int GetUserChoice();
	bool IsExiting();
private:
	bool isValidInput(int choice);
	display_menu currentMenu;
	std::stack<display_menu> previousMenu;
	int user_choice;
};

#endif // ! __DISPLAYMENU_H__