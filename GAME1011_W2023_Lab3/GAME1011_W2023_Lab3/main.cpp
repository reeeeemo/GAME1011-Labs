#include <vector>
#include <iostream>

#include "Messager.h"
#include "UnorderedArray.h"
#include "SearchType.h"
#include <string>

int main() {

	// Array of floats 
	UnorderedArray<float> float_array = UnorderedArray<float>(3);
	
	float_array.push_back(3.5f);
	float_array.push_back(1.2f);
	float_array.push_back(7.8f);


	std::cout << "Array of floats: \n";
	Messager::OutputList(float_array);

	std::cout << "\nFinding value '3.5' via Linear search: \n";
	std::cout << float_array.SearchForValue(3.5f, SearchType::LINEAR) << std::endl;

	std::cout << "\nFinding value '1.2' via Binary search: \n";
	std::cout << float_array.SearchForValue(1.2f, SearchType::BINARY) << std::endl;
	

	std::cout << "\nSorted array of floats: \n";
	Messager::OutputList(float_array);

	float_array.clear();
	return 0;
}