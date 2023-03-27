#include "ChallengeManager.h"
#include "Messager.h"

#include <iostream>
#include <array>

bool ChallengeManager::DeterminePalindrone(std::string possiblePalindrone)
{
	return IsPalindrone(possiblePalindrone, 0, possiblePalindrone.size() - 1);
}

void ChallengeManager::PerformQuicksort(const int arraySize)
{
	// Create a new variable array.
	int* randomArray = new int[arraySize];

	// Randomizing the array from 0-200.
	for (int i = 0; i < arraySize; i++) {
		randomArray[i] = rand() % 200 + 1 ;
	}

	QuickSort(randomArray, 0, arraySize - 1);

	Messager::OutputArray(randomArray, arraySize);

	// Destroying the variable array....
	delete[] randomArray;
	randomArray = nullptr; // Like always... NO. HEAP. FRAG. :DDDD
}

void ChallengeManager::ReverseString(std::string stringToReverse)
{
	Messager::OutputString(InvertString(stringToReverse, 0, stringToReverse.length() - 1));
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

/* Gonna be honest still quite confused about how the quicksort works, I understand the concept though. Most of the code is from https://www.geeksforgeeks.org/cpp-program-for-quicksort/ */
void ChallengeManager::QuickSort(int* arr, int start, int end)
{
	if (start >= end) {
		return;
	}

	int partitionIndex = Partition(arr, start, end); // Partioning the array (dividing into numerically sorted parts)

	// Sortiong the left part of array
	QuickSort(arr, start, partitionIndex - 1);

	// Sorting the right part of array
	QuickSort(arr, partitionIndex + 1, end);

}

int ChallengeManager::Partition(int arr[], int start, int end)
{
	int pivot = arr[start];

	int count = 0;

	for (int i = start + 1; i <= end; i++) { // Finding how many are smaller than pivot.
		if (arr[i] <= pivot) {
			count++;
		}
	}

	// Swapping the pivot index and however many are smaller than it.
	int pivotIndex = start + count;
	std::swap(arr[pivotIndex], arr[start]);

	// Sorting the left and right parts of the pivot.
	int i = start;
	int j = end;

	while (i < pivotIndex && j > pivotIndex) {
		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			std::swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

std::string ChallengeManager::InvertString(std::string& input, int start, int end)
{
	if (start >= end) {
		return input;
	}

	std::swap(input[start], input[end]);

	return InvertString(input, ++start, --end);
}

