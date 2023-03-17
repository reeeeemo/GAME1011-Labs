#include <vector>
#include <iostream>

#include "Messager.h"
#include "UnorderedArray.h"


int main() {
	Messager::WelcomePlayer();

	UnorderedArray<float> float_array = UnorderedArray<float>(3);

	float_array.push_back(0.5f);
	float_array.push_back(0.3f);
	float_array.push_back(0.1f);

	float_array.Sort();

	Messager::OutputList(float_array);

	float_array.clear();
	return 0;
}