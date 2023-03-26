#include "Messager.h"

#include <iostream>
#include <string>

void Messager::WelcomePlayer()
{
	std::cout << "Welcome to the recursive calculator!\n";
}

int Messager::GetChoiceInput()
{
	std::cout << "Please select an option from the following\n\n";
	std::cout << "1. Determine whether input is a palindrome.\n"
		<< "2. Perform the quicksort algorithm on a randomly generated list of integers.\n"
		<< "3. Reverse a given string.\n";

	return GetInput();
}

int Messager::GetInput()
{
	int input;
	bool validInput = false;
	do
	{
		std::cin >> input;

		if (!std::cin.fail())
		{
			if (input == 1 || input == 2 || input == 3) // Prolly a better way of doing this. but good for the project.
			{
				validInput = true;
			}

		} else
		{
			std::cin.clear();
			std::cin.ignore();

		}

	} while (!validInput);

	return input;
}
