#include <iostream>
#include <vector>
#include <stack>
#include "Achievement.h"
#include "Game.h"
#include "Platform.h"
#include "DisplayMenu.h"

void ChoosePlatform();
void ShowPlatforms();
void ShowGames(Platform* platformToCheck);
void ChooseGame(Platform* currentPlatform);
void ChooseAchievement(Game* currentGame, Platform* currentPlatform);
void ShowAchievements(Game* gameToCheck);
void CleanupAndExit();
void UserSelectChoice();

std::vector<Platform*> platforms;
int choice;
DisplayMenu display_screen;

int main() {
	display_screen.Init();
	ChoosePlatform();
	return 0;
}

void ChoosePlatform() { // Platform Menu 
	bool isLeaving = false; // Checks to see if player is leaving the menu screen.
	std::string nameChoice, manuChoice; // Variables for naming the platform and it's manufacturer

	display_screen.ChangeMenuState(CHOOSE_PLATFORM);

	do // Loop until we want to exit the platform menu
	{
		UserSelectChoice();
		switch (choice)
		{
		case 1: // Choosing Platform
			if (platforms.empty())
			{
				std::cout << "There is nothing to access! Going back...\n\n";
				display_screen.ChangeMenuState(CHOOSE_PLATFORM);
				break;
			}
			std::cout << "\n Which platform would you like to access?\n";
			ShowPlatforms();
			do // loop until player selects a valid choice
			{
				UserSelectChoice();
				if (choice == (platforms.size() + 1)) // If we want to go back to the previous menu
				{
					std::cout << "Going back...\n";
					display_screen.GoBackMenu();
					break;
				}
				if (choice > platforms.size())
				{
					std::cout << "Error, number out of range, try again.\n";
				}
			} while (choice > platforms.size() || choice == 0);

			if (choice != (platforms.size() + 1)) // If we are not going back to the previous menu
			{
				choice -= 1; 
				isLeaving = true;
				std::cout << "Selected platform: " << platforms[choice]->GetName() << std::endl;
				std::cout << "Manufacturer: " << platforms[choice]->GetManufacturer() << std::endl;
				ChooseGame(platforms[choice]);
			}
			break;
		case 2: // Adding Platform
			display_screen.ChangeMenuState(ADD_PLATFORM);
			std::cin >> nameChoice >> manuChoice;
			platforms.push_back(new Platform(nameChoice, manuChoice));
			display_screen.GoBackMenu();
			break;
		case 3: // Deleting Platform
			if (platforms.empty())
			{
				std::cout << "There is nothing to delete! Going back...\n\n";
				display_screen.GoBackMenu();
				break;
			}
			display_screen.ChangeMenuState(DELETE_PLATFORM);
			ShowPlatforms();
			do // loop until player selects a valid choice
			{
				UserSelectChoice();
				if (choice == (platforms.size() + 1)) // If we want to go back to the previous menu
				{
					std::cout << "Going back...\n";
					break;
				}
				if (choice > platforms.size())
				{
					std::cout << "Error, number out of range, try again.\n";
				}
			} while (choice > platforms.size() || choice == 0);

			if (choice != (platforms.size() + 1)) // If we are not going back to the previous menu
			{
				choice -= 1; // To fit it in the vector subscript (no errors :) )

				std::cout << "Deleting " << platforms[choice]->GetName() << std::endl;

				// Deleting said platform, and resizing accordingly
				delete platforms[choice];
				platforms[choice] = nullptr;
				platforms.erase(platforms.begin() + (choice));
				platforms.shrink_to_fit();
			}

			display_screen.GoBackMenu();
			break;
		case 4: // Exiting Program
			CleanupAndExit();
			isLeaving = true;
			break;
		default:
			break;
		}
	} while (!isLeaving); // While we are not exiting
}

void ShowPlatforms()
{
	int choiceCounter = 1;
	for (Platform* platform : platforms)
	{
		std::cout << choiceCounter << ": " << platform->GetName() << std::endl;
		choiceCounter++;
	}
	std::cout << choiceCounter++ << ". Go Back\n";
}

void ShowGames(Platform* platformToCheck)
{
	int choiceCounter = 1;
	for (Game* game : platformToCheck->GetGames())
	{
		std::cout << choiceCounter << ": " << game->GetName() << std::endl;
		choiceCounter++;
	}
	std::cout << choiceCounter++ << ". Go Back\n";
}

void ShowAchievements(Game* gameToCheck)
{
	int choiceCounter = 1;
	for (Achievement* achievement : gameToCheck->GetAchievements())
	{
		std::cout << choiceCounter << ": " << achievement->GetTitle() << std::endl;
		std::cout << "    " << "Score Value: " << achievement->GetScoreValue() << std::endl;
		choiceCounter++;
	}
	std::cout << choiceCounter++ << ". Go Back\n";
}

void ChooseGame(Platform* currentPlatform) // Game Menu
{
	bool isLeaving = false; // Checks to see if player is leaving the menu screen.
	std::string nameChoice, publisherChoice, developerChoice; // Variables for naming the platform and it's manufacturer

	display_screen.ChangeMenuState(CHOOSE_GAME);

	do // Loop until we want to exit the game menu
	{
		UserSelectChoice();
		switch (choice)
		{
		case 1: // Choosing Game
			if (currentPlatform->GetGames().empty())
			{
				std::cout << "There is nothing to access! Going back...\n\n";
				display_screen.ChangeMenuState(CHOOSE_GAME);
				break;
			}
			std::cout << "\n Which game would you like to access?\n";
			ShowGames(currentPlatform);
			do // loop until player selects a valid choice
			{
				UserSelectChoice();
				if (choice == (currentPlatform->GetGames().size() + 1)) // If we want to go back to the previous menu
				{
					std::cout << "Going back...\n";
					display_screen.GoBackMenu();
					break;
				}
				if (choice > currentPlatform->GetGames().size())
				{
					std::cout << "Error, number out of range, try again.\n";
				}
			} while (choice > currentPlatform->GetGames().size() || choice == 0);

			if (choice != (currentPlatform->GetGames().size() + 1)) // If we are not going back to the previous menu
			{
				choice -= 1;
				isLeaving = true;
				std::cout << "Selected Game: " << currentPlatform->GetGames()[choice]->GetName() << std::endl;
				std::cout << "Developer: " << currentPlatform->GetGames()[choice]->GetDeveloper() << std::endl;
				std::cout << "Publisher: " << currentPlatform->GetGames()[choice]->GetPublisher() << std::endl;
				ChooseAchievement(currentPlatform->GetGames()[choice], currentPlatform);
			}
			break;
		case 2: // Adding Game
			display_screen.ChangeMenuState(ADD_GAME);
			std::cin >> nameChoice >> developerChoice >> publisherChoice;
			currentPlatform->AddGame(new Game(nameChoice, developerChoice, publisherChoice));
			display_screen.GoBackMenu();
			break;
		case 3: // Deleting Game
			if (currentPlatform->GetGames().empty())
			{
				std::cout << "There is nothing to delete! Going back...\n\n";
				display_screen.GoBackMenu();
				break;
			}
			display_screen.ChangeMenuState(DELETE_GAME);
			ShowGames(currentPlatform);
			do // loop until player selects a valid choice
			{
				UserSelectChoice();
				if (choice == (currentPlatform->GetGames().size() + 1)) // If we want to go back to the previous menu
				{
					std::cout << "Going back...\n";
					break;
				}
				if (choice > currentPlatform->GetGames().size())
				{
					std::cout << "Error, number out of range, try again.\n";
				}
			} while (choice > currentPlatform->GetGames().size() || choice == 0);

			if (choice != (currentPlatform->GetGames().size() + 1)) // If we are not going back to the previous menu
			{
				choice -= 1; // To fit it in the vector subscript (no errors :) )

				std::cout << "Deleting " << currentPlatform->GetGames()[choice]->GetName() << std::endl;

				// Deleting said game, and resizing accordingly
				currentPlatform->RemoveGame(choice);
			}

			display_screen.GoBackMenu();
			break;
		case 4: // Exiting Program
			ChoosePlatform();
			isLeaving = true;
			break;
		default:
			break;
		}
	} while (!isLeaving); // While we are not exiting
}

void ChooseAchievement(Game* currentGame, Platform* currentPlatform)
{
	bool isLeaving = false; // Checks to see if player is leaving the menu screen.
	std::string titleChoice, descriptionChoice; // Variables for naming the platform and it's manufacturer
	double scoreValueChoice;

	display_screen.ChangeMenuState(CHOOSE_ACHIEVEMENT);

	do // Loop until we want to exit the game menu
	{
		UserSelectChoice();
		switch (choice)
		{
		case 1: // Choosing Achievement
			if (currentGame->GetAchievements().empty())
			{
				std::cout << "There is nothing to access! Going back...\n\n";
				display_screen.ChangeMenuState(CHOOSE_ACHIEVEMENT);
				break;
			}
			std::cout << "\n Which game would you like to access?\n";
			ShowAchievements(currentGame);
			do // loop until player selects a valid choice
			{
				UserSelectChoice();
				if (choice == (currentGame->GetAchievements().size() + 1)) // If we want to go back to the previous menu
				{
					std::cout << "Going back...\n";
					display_screen.GoBackMenu();
					break;
				}
				if (choice > currentGame->GetAchievements().size())
				{
					std::cout << "Error, number out of range, try again.\n";
				}
			} while (choice > currentGame->GetAchievements().size() || choice == 0);

			if (choice != (currentGame->GetAchievements().size() + 1)) // If we are not going back to the previous menu
			{
				choice -= 1;
				isLeaving = true;
				std::cout << "Selected Achievement: " << currentGame->GetAchievements()[choice]->GetTitle() << std::endl;
				std::cout << "Description: " << currentGame->GetAchievements()[choice]->GetDescription() << std::endl;
				std::cout << "Score Value: " << currentGame->GetAchievements()[choice]->GetScoreValue() << std::endl;
				ChooseAchievement(currentGame, currentPlatform);
			}
			break;
		case 2: // Adding Achievement
			display_screen.ChangeMenuState(ADD_ACHIEVEMENT);
			std::cin >> titleChoice >> descriptionChoice >> scoreValueChoice;
			currentGame->AddAchievement(new Achievement(titleChoice, descriptionChoice, scoreValueChoice));
			display_screen.GoBackMenu();
			break;
		case 3: // Deleting Achievement
			if (currentGame->GetAchievements().empty())
			{
				std::cout << "There is nothing to delete! Going back...\n\n";
				display_screen.GoBackMenu();
				break;
			}
			display_screen.ChangeMenuState(DELETE_ACHIEVEMENT);
			ShowAchievements(currentGame);
			do // loop until player selects a valid choice
			{
				UserSelectChoice();
				if (choice == (currentGame->GetAchievements().size() + 1)) // If we want to go back to the previous menu
				{
					std::cout << "Going back...\n";
					break;
				}
				if (choice > currentGame->GetAchievements().size())
				{
					std::cout << "Error, number out of range, try again.\n";
				}
			} while (choice > currentGame->GetAchievements().size() || choice == 0);

			if (choice != (currentGame->GetAchievements().size() + 1)) // If we are not going back to the previous menu
			{
				choice -= 1; // To fit it in the vector subscript (no errors :) )

				std::cout << "Deleting " << currentGame->GetAchievements()[choice]->GetTitle() << std::endl;

				// Deleting said achievement, and resizing accordingly
				currentGame->RemoveAchievement(choice);
			}

			display_screen.GoBackMenu();
			break;
		case 4: // Exiting Program
			ChooseGame(currentPlatform);
			isLeaving = true;
			break;
		default:
			break;
		}
	} while (!isLeaving); // While we are not exiting
}

void UserSelectChoice() // Selects choice and places it in the global choice variable
{
	do
	{
		std::cin.clear();
		std::cin >> choice;
	} while (std::cin.fail());
}


void CleanupAndExit() // Cleaning up and deleting everything 
{
	for (int i = 0; i < platforms.size(); i++)
	{
		for(int j = 0; j < platforms[i]->GetGames().size(); j++)
		{
			for (int k = 0; k < platforms[i]->GetGames()[j]->GetAchievements().size(); k++)
			{
				platforms[i]->GetGames()[j]->RemoveAchievement(k);
			}
			platforms[i]->RemoveGame(j);
		}
		delete platforms[i];
		platforms[i] = nullptr;
		platforms.erase(platforms.begin() + (i));
		platforms.shrink_to_fit();
	}
}