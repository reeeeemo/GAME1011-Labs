#include "Messager.h"
#include "ChallengeManager.h"

#include <string>


int main()
{

	Messager::WelcomePlayer();

	std::string input;
	bool exitProgram = false;
	
	do {
		int choice = Messager::GetChoiceInput();

		switch (choice)
		{
		case 1:
			if (ChallengeManager::DeterminePalindrone(Messager::GetStringInput())) {
				Messager::OutputString("This input is a palindrone!");
			}
			else {
				Messager::OutputString("This input is not a palindrone.");
			}
			break;
		case 2:
			Messager::OutputString("Please select a size of array to quicksort.");
			ChallengeManager::PerformQuicksort(Messager::GetIntInput());
			break;
		case 3:
			Messager::OutputString("Please type a string to reverse.");
			ChallengeManager::ReverseString(Messager::GetStringInput());
			break;
		case 4:
			exitProgram = true;
			break;
		}
	} while (!exitProgram);

	
	return 0;
}