#pragma once
#ifndef __UNORDEREDARRAY_H__
#define __UNORDEREDARRAY_H__

#include <cstring>
#include <limits>
#include <array>
#include <cassert>
#include <iostream>
#include "SearchType.h"

template<typename DataType> 
class UnorderedArray
{
public:
	/* Constructor for custom array that initializes and sets memory for array. */
	UnorderedArray(int size) : m_maxSize(0), m_array(nullptr), m_numElements(0)
	{
		if (size) { // Is size valid.
			m_maxSize = size;
			m_array = new DataType[m_maxSize];
			memset(m_array, std::numeric_limits<DataType>::lowest(), sizeof(DataType) * m_maxSize); // Sets all pointers in array to lowest # of that datatype
		}
	}

	/* Destructor that deletes array. */
	~UnorderedArray()
	{
		if (m_array != nullptr) {
			delete[] m_array;
			m_array = nullptr; // No fragmentation here!
		}
	}

	/* Push in a new item if possible. */
	void push_back(DataType value)
	{
		assert(m_array != nullptr);
		if (m_numElements >= m_maxSize) { // If data is greater than or equal to max size, stop pushing
			return;
		}

		m_array[m_numElements] = value;
		m_numElements++;
	}

	/* Take out the last item that was inserted. */
	void pop_back()
	{
		if (m_numElements > 0) {
			m_numElements--;
		}
	}

	/* Clearing the array --> ignore all previous elements, */
	void clear()
	{
		m_numElements = 0;
	}

	/* Returning the current size of the array. */
	int size()
	{
		return m_numElements;
	}

	/* Returning the max size of the array. */
	int maxSize()
	{
		return m_maxSize;
	}

	/* Overloading the [] operator to return an index value. */
	DataType& operator[](int index)
	{
		if (index < m_numElements) { // No going outside the bounds of the array.
			return m_array[index];
		}
	}

	DataType& SearchForValue(DataType value, SearchType type) {
		if (type == SearchType::LINEAR) {
			return m_array[LinearSearch(value, 0, m_numElements)];
		}
		else { // if type == SearchType::BINARY
			return m_array[BinarySearch(value, 0, m_numElements)];
		}
	}

	


private:
	int m_maxSize;
	DataType* m_array;
	int m_numElements;

	/* Sorts the data of the array. */
	void Sort()
	{
		for (int i = 0; i < m_numElements; i++) {
			int j = i;
			while (j > 0 && m_array[j - 1] > m_array[j]) {
				std::swap(m_array[j], m_array[j - 1]);
				j = j - 1;
			}
		}
	}

	/* Finds the value in the array by splitting the array in half and checking it's lower and upper bounds. */
	int BinarySearch(DataType value, int first, int last) {
		int middle; // Mid-Point (where we will begin searching)

		Sort(); // Sorting array!

		// Did not find value in array
		if (first > last) {
			return -1;
		}

		middle = (first + last) / 2; // Mid-Point achieved!

		// If the midpoint was the value
		if (m_array[middle] == value) {
			return middle;
		}

		// If we did not find the value, but is still in array
		if (m_array[middle] < value) { // If it is in the upper half of the array
			return BinarySearch(value, middle + 1, last);
		}
		else { // If it is in the lower half of the array
			return BinarySearch(value, first, middle - 1);
		}
	}

	/* Finds the value in the array by simply iterating through the array. */
	int LinearSearch(DataType value, int first, int last) {
		// Did not find value in the array
		if (first >= last) {
			return -1; // In worst case scenario, returns an out of bounds variable.
		}

		// Found the value
		if (m_array[first] == value) {
			return first;
		}
		else { // We have not found value yet, increment.
			return LinearSearch(value, ++first, last);
		}
	}
};

#endif //!__UNORDEREDARRAY__

