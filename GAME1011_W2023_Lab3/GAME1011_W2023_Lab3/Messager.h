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


	/* Outputting whatever list of data types it is given. */
	template <typename DataType>
	static void OutputList(UnorderedArray<DataType> &output_array);

private:
};

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

#endif //!__MESSAGER_H__