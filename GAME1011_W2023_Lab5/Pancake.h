#pragma once
#ifndef __PANCAKE_H__
#define __PANCAKE_H__

#include <iostream>
#include "Customer.h"

// VERY important class, that has SO many uses
struct Pancake
{
	Pancake();
	~Pancake();
	void OutputPancake();
	void PourSyrup();
	void AddButter();
private:
	bool hasSyrup;
	bool hasButter;
};

#endif // __PANCAKE_H__