#pragma once
#ifndef __UNORDEREDARRAY_H__
#define __ORDEREDARRAY_H__

template<typename DataType> 
struct UnorderedArray
{
public:
	UnorderedArray(int size);
	~UnorderedArray();
private:
	int m_maxSize;
};

#endif //!__UNORDEREDARRAY__