#pragma once
#ifndef __CHALLENGE_MANAGER_H__
#define __CHALLENGE_MANAGER_H__

#include <string>

class ChallengeManager
{
public:
	static bool DeterminePalindrone(std::string possiblePalindrone);
	static void PerformQuicksort(const int arraySize);
	static void ReverseString(std::string stringToReverse);
private:
	static bool IsPalindrone(std::string a, int indexA, int indexB);
	static void QuickSort(int* arr, int start, int end);
	static int Partition(int arr[], int start, int end);
	static std::string InvertString(std::string&, int start, int end);
};

#endif //!__CHALLENGE_MANAGER_H__