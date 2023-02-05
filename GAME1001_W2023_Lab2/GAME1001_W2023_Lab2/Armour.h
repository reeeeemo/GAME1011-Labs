#pragma once
#ifndef __ARMOUR_H__
#define __ARMOUR_H__

#include <string>
#include <vector>
#include <iostream>

class Armour
{
public:
	Armour(); // Default Constructor
	Armour(std::string desc, std::string name, int inputDefense);

	// Accessors
	virtual std::string GetName();

	// Operator Overloads
	friend std::ostream& operator<<(std::ostream& os, const Armour& weaponToPrint);
protected:
	std::string epicArmourName;
	std::string description;
	int defenseValue;
};

#endif // !__ARMOUR_H__

