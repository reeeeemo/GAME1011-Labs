#pragma once
#ifndef  __GAME_H__
#define __GAME_H__
#include <iostream>
#include <vector>
#include "Achievement.h"

class Game {
public:
	Game(std::string inputName, std::string inputDeveloper, std::string inputPublisher);

	void AddAchievement(Achievement* achievement); // Adding achievement to the vector
	void AddAchievement(std::vector<Achievement*> input_achievements); // Overload incase there is a vector of achievements needed to be sent
	void RemoveAchievement(int index);
	std::string GetName();
	std::string GetPublisher();
	std::string GetDeveloper();
	std::vector<Achievement*> GetAchievements() {
		return achievements;
	}
private:
	std::string name;
	std::string publisher;
	std::string developer;
	std::vector<Achievement*> achievements;
};

#endif // ! __GAME_H__
