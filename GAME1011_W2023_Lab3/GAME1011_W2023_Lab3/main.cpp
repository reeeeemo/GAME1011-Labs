#include <vector>
#include <iostream>

#include "Messager.h"
#include "UnorderedArray.h"


int main() {
	Messager::WelcomePlayer();

	UnorderedArray<int> float_array = UnorderedArray<int>(3);
	
	float_array.push_back(1);
	float_array.push_back(0);
	float_array.push_back(6);
	
	float_array.Sort();

	Messager::OutputList(float_array);
	
	
	float_array.clear();
	return 0;
}