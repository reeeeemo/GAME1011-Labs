#pragma once
#ifndef  __PLATFORM_H__
#define __PLATFORM_H__
#include <iostream>
#include <string>
#include <vector>
#include "Game.h"

class Platform {
public:
	Platform(std::string inputName, std::string inputManufacturer);
	void AddGame(Game* input_game); // If there is only one game to be added
	void AddGame(std::vector<Game*> input_games); // Overloading previous function if theres a vector
	void RemoveGame(int index);
	std::string GetName();
	std::string GetManufacturer();
	std::vector<Game*> GetGames();
private:
	std::string name; // Name of the platform
	std::string manufacturer; // Who made this platform
	std::vector<Game*> games; // The games involved with this platform
};

#endif // ! __PLATFORM_H__
