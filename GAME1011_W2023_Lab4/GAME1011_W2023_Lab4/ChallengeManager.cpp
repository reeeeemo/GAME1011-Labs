#include "ChallengeManager.h"

#include <iostream>

bool ChallengeManager::DeterminePalindrone(std::string possiblePalindrone)
{
	return IsPalindrone(possiblePalindrone, 0, possiblePalindrone.size() - 1);
}

void ChallengeManager::PerformQuicksort(int arraySize)
{

}

void ChallengeManager::ReverseString()
{
}

bool ChallengeManager::IsPalindrone(std::string a, int indexA, int indexB)
{
	if (a[indexA] == ' ') {
		++indexA;
	}
	else if (a[indexB] == ' ') {
		--indexB;
	}

	if (a[indexA] != a[indexB]) {
		return false;
	}
	else if (a[indexA] == a.back() || a[indexB] == a.front()) {
		return true;
	}
	else {
		return IsPalindrone(a, indexA++, indexB--);
	}
}

