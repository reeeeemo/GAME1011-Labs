#pragma once
#ifndef __CHALLENGE_MANAGER_H__
#define __CHALLENGE_MANAGER_H__

#include <string>

class ChallengeManager
{
public:
	static bool DeterminePalindrone(std::string possiblePalindrone);
	static void PerformQuicksort(int arraySize);
	static void ReverseString();
private:
	static bool IsPalindrone(std::string a, int indexA, int indexB);
};

#endif //!__CHALLENGE_MANAGER_H__