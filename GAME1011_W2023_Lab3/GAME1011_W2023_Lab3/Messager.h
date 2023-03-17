#pragma once
#ifndef __MESSAGER_H__
#define __MESSAGER_H__

#include <vector>
#include "UnorderedArray.h"
#include <iostream>

class Messager
{
public:
	// Functions to call and send a vector.
	static void WelcomePlayer();
	static std::vector<int> AskForListInput();

	/* Outputting whatever list of data types it is given. */
	template <typename DataType>
	static void OutputList(UnorderedArray<DataType> output_array)
	{
		for (int i = 0; i < output_array.size(); i++) {
			if (output_array[i] == output_array.size()) {
				std::cout << output_array[i] << std::endl;
			}
			else {
				std::cout << output_array[i] << ", ";
			}
		}
	}


private:
	// Recursive function to get input of player
	static void GetListInput(int numOfInputs);

	static std::vector<int> input;
};

#endif //!__MESSAGER_H__