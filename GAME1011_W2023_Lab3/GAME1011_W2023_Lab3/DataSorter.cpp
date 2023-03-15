#include "DataSorter.h"

/* Sorts the data and then returns the same vector. */
std::vector<int> DataSorter::Sort(std::vector<int> input_list)
{
	int vectorSize = input_list.size();
	for (int i = 0; i < vectorSize; i++) {
		int j = i;
		while (j > 0 && input_list[j - 1] > input_list[j]) {
			std::swap(input_list[j], input_list[j - 1]);
			j = j - 1;
		}
	}

	return input_list;
}
