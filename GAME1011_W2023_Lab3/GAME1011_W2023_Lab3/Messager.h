#pragma once
#ifndef __MESSAGER_H__
#define __MESSAGER_H__

#include <vector>

class Messager
{
public:
	// Functions to call and send a vector.
	static void WelcomePlayer();
	static std::vector<int> AskForListInput();
	static void OutputList(std::vector<int> input_list);

private:
	// Recursive function to get input of player
	static void GetListInput(int numOfInputs);

	static std::vector<int> input;
};

#endif //!__MESSAGER_H__