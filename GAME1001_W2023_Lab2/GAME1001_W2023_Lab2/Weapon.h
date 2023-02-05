#pragma once
#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <string>
#include <vector>
#include <iostream>

class Weapon
{
public:
	Weapon(); // Default constructor
	Weapon(std::vector<std::string> abilities, std::string name, int inputDamage);

	// Accessors
	virtual std::string GetName();

	// Operator Overloads
	friend std::ostream& operator<<(std::ostream& os, const Weapon& weaponToPrint);
protected:
	std::string epicWeaponName;
	int damage;
	std::vector<std::string> special_abilities;
};

#endif // !__WEAPON_H__

