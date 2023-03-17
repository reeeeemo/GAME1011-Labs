#include "Messager.h"

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

