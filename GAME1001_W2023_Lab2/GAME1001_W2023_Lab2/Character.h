#pragma once
#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <string>
#include <iostream>
#include <map>
#include "Weapon.h"
#include "Armour.h"


enum SPECIES { CAPYBARA, PLATYPUS, ELDRITCH, BABOON, NOT_FOUND}; // NOT_FOUND is essentially null.

static std::map<SPECIES, std::string> species_list = {
	std::pair<SPECIES, std::string>(CAPYBARA, "Capybara"),
	std::pair<SPECIES, std::string>(PLATYPUS, "Playpus"),
	std::pair<SPECIES, std::string>(ELDRITCH, "Eldritch"),
	std::pair<SPECIES, std::string>(BABOON, "Baboon"),

};

static std::map<SPECIES, std::string> backstory_list = {
	std::pair<SPECIES, std::string>(CAPYBARA, "Hailing from Atlantis, these creatures's laziness knows no bounds.\nThey are uncommon, with not much known about them, and legend says when they appear (also known as 'pulling up', they will cause armageddon."),
	std::pair<SPECIES, std::string>(PLATYPUS, "These ferocious creatures are ready to kill at any moment. When threatened, they will attempt to bite the enemy, and seethe poison into their veins until they are no more.\nThey are rumoured to be at war with the Capybaras."),
	std::pair<SPECIES, std::string>(ELDRITCH,"They tend to enjoy your walls. Once they set their sights on you, might as well just die then and there.\nThey can take the form of the victim's closest friends/family, and has an unsettling smile."),
	std::pair<SPECIES, std::string>(BABOON, "These creatures are typically found in India, where they are preventing trash from being thrown out since it is illegal.\nThey seem to run under a powerful, but unknown leader."),
};

class Character
{
public:
	Character();
	
	// Mutators
	virtual void SetName(std::string nameToSet);
	virtual void SetSpecies(int numOfSpeciesToSet); // Could be an inherited class, but not required for this project
	virtual void SetMaxHealth(int healthToSet);
	virtual void SetWeapon(Weapon weaponToSet);
	virtual void SetArmour(Armour armourToSet);

	// Accessors
	virtual std::string GetName();
	virtual std::string GetSpecies();
	virtual int GetMaxHealth();
	virtual std::string GetBackstory();
	

	// Overloading for comparison
	virtual void operator ==(const Character typeToCompare); 
	friend std::ostream& operator<< (std::ostream &os, const Character &selectedCharacter);
protected: // So these variables can be inheirited for future work
	std::string name;
	SPECIES species; // Agh, both are plural and non-plural words!
	std::string epicBackstory; // I know I know does not have to have "epic" in it, but it's funny.
	int maxHealth;
	Weapon currentWeapon;
	Armour currentArmour;
};

#endif // !__CHARACTER_H__

