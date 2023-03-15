#include "Messager.h"
#include "DataSorter.h"

#include <vector>
#include <iostream>

int main() {
	Messager::WelcomePlayer();

	std::vector<int> temp =  Messager::AskForListInput();

	Messager::OutputList(temp);
	return 0;
}