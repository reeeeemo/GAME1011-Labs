#pragma once
#ifndef __CUSTOM_EXCEPTIONS_H__
#define __CUSTOM_EXCEPTIONS_H__
#include <exception>

class OutOfPancake : public std::exception
{
public:
	OutOfPancake() noexcept : exception("WE NEED MORE PANCAKES JOHN!!!! COOK MORE!", 1) {}
};

#endif //!__CUSTOM_EXCEPTIONS_H__