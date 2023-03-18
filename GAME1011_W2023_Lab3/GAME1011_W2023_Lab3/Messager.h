#pragma once
#ifndef __MESSAGER_H__
#define __MESSAGER_H__

#include <vector>
#include "UnorderedArray.h"
#include <iostream>

class Messager
{
public:
	/* Destructor function. */
	virtual ~Messager() = 0;


	// Functions to call and send a vector.
	static void WelcomePlayer();

	template <typename DataType>
	static UnorderedArray<DataType> AskForListInput();


	/* Outputting whatever list of data types it is given. */
	template <typename DataType>
	static void OutputList(UnorderedArray<DataType> &output_array);

private:
	/* Recursive function that asks forand grabs input of player. */
	template <typename DataType>
	static void GetListInput(int numOfInputs)
	{
		if (numOfInputs <= 0) {
			// Break out of recursion
		}
		else {
			DataType n;
			std::cin >> n;

			input.push_back(n);
			GetListInput(numOfInputs - 1);
		}
	}

	template <typename DataType>
	static UnorderedArray<DataType> input;
};

template <typename DataType>
UnorderedArray<DataType> Messager::input;

template <typename DataType>
void Messager::OutputList(UnorderedArray<DataType> &output_array)
{
	for (int i = 0; i < output_array.size(); i++) {
		if (output_array[i] == output_array.size() - 1) {
			std::cout << output_array[i] << std::endl;
		}
		else {
			std::cout << output_array[i] << ", ";
		}
	}
}



/* Asks for list inputand calls recursive function based on how many data types is being entered. */
template <typename DataType>
UnorderedArray<DataType> Messager::AskForListInput()
{
	int numOfTypes;
	std::cout << "Please input the number of data types you will be entering!\n";
	std::cin >> numOfTypes;

	input = UnorderedArray<DataType>(numOfTypes);

	std::cout << "Please input the data types now:\n\n";

	GetListInput(numOfTypes);

	return input;
}






#endif //!__MESSAGER_H__