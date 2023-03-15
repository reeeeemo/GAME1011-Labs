#include "Messager.h"
#include <iostream>

/* Static variable initializers. */
std::vector<int> Messager::input;

/* Welcoming player! */
void Messager::WelcomePlayer()
{
	std::cout << "Welcome to the the data type sorter!\n\n";
}

/* Asks for list inputand calls recursive function based on how many data types is being entered. */
std::vector<int> Messager::AskForListInput()
{
	int numOfTypes;
	std::cout << "Please input the number of data types you will be entering!\n";
	std::cin >> numOfTypes;

	std::cout << "Please input the data types now:\n\n";

	GetListInput(numOfTypes);

	return input;
}

/* Recursive function that asks forand grabs input of player. */
void Messager::GetListInput(int numOfInputs)
{
	if (numOfInputs <= 0) {
		// Break out of recursion
	}
	else {
		int n;
		std::cin >> n;

		input.push_back(n);
		GetListInput(numOfInputs - 1);
	}
}

/* Outputting whatever list of data types it is given. */
void Messager::OutputList(std::vector<int> input_list)
{
	for (int i = 0; i < input_list.size(); i++) {
		if (input_list[i] == input_list.back()) {
			std::cout << input_list[i] << std::endl;
		}
		else {
			std::cout << input_list[i] << ", ";
		}
	}
}
