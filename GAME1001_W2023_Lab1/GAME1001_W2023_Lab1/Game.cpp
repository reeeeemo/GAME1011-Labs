#include "Game.h"

Game::Game(std::string inputName, std::string inputDeveloper, std::string inputPublisher) {
	name = inputName;
	publisher = inputPublisher;
	developer = inputDeveloper;
}

void Game::AddAchievement(Achievement* achievement) {
	achievements.push_back(achievement);
}


void Game::AddAchievement(std::vector<Achievement*> input_achievements) {
	for (Achievement* achievement : input_achievements) {
		achievements.push_back(achievement);
	}
}

std::string Game::GetName() {
	return name;
}

void Game::RemoveAchievement(int index)
{
	delete achievements[index];
	achievements[index] = nullptr;
	achievements.erase(achievements.begin() + (index));
	achievements.shrink_to_fit();
}


std::string Game::GetDeveloper() {
	return developer;
}

std::string Game::GetPublisher() {
	return publisher;
}