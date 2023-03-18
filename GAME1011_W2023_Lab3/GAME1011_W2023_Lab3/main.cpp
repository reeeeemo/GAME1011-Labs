#include <vector>
#include <iostream>

#include "Messager.h"
#include "UnorderedArray.h"
#include "SearchType.h"
#include <string>

int main() {
	Messager::WelcomePlayer();

	UnorderedArray<int> float_array = Messager::AskForListInput<int>();
	
	
	Messager::OutputList(float_array);
	
	std::cout << float_array.SearchForValue(6, SearchType::BINARY);

	float_array.clear();
	return 0;
}