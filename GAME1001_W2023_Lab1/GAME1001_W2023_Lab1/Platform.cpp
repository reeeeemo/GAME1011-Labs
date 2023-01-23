#include "Platform.h"


Platform::Platform(std::string input_name, std::string input_manufacturer) {
	name = input_name;
	manufacturer = input_manufacturer;
}

void Platform::AddGame(Game* input_game) {
	games.push_back(input_game);
}

void Platform::AddGame(std::vector<Game*> input_games) {
	for (Game* game : input_games) {
		games.push_back(game);
	}
}

std::string Platform::GetName() {
	return name;
}

std::string Platform::GetManufacturer() {
	return manufacturer;
}

std::vector<Game*> Platform::GetGames()
{
	return games;
}

void Platform::RemoveGame(int index)
{
	delete games[index];
	games[index] = nullptr;
	games.erase(games.begin() + (index));
	games.shrink_to_fit();
}



