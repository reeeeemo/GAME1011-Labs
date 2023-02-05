#include "Character.h"

Character::Character() : name("N/A"), species(NOT_FOUND), maxHealth(0) // Initializing variables
{ 
}

void Character::SetName(std::string nameToSet) 
{
	name = nameToSet;
}


void Character::SetSpecies(int numOfSpeciesToSet) 
{
	// Could be done better.
	switch (numOfSpeciesToSet) {
	case 0:
		species = CAPYBARA;
		break;
	case 1:
		species = PLATYPUS;
		break;
	case 2:
		species = ELDRITCH;
		break;
	case 3:
		species = BABOON;
		break;
	default:
		species = NOT_FOUND;
		break;
	}
	epicBackstory = backstory_list[species]; // Setting backstory in here since we change Species here as well.
}


void Character::SetMaxHealth(int healthToSet) 
{
	maxHealth = healthToSet;
}

void Character::SetWeapon(Weapon weaponToSet)
{
	currentWeapon = weaponToSet;
}

void Character::SetArmour(Armour armourToSet)
{
	currentArmour = armourToSet;	
}

std::string Character::GetName()
{
	return name;
}

std::string Character::GetSpecies()
{
	if (species == NOT_FOUND) { // If null basically.
		return "not found";
	}
	return species_list[species]; // Sends back our string.
}

int Character::GetMaxHealth()
{
	return maxHealth;
}

std::string Character::GetBackstory()
{
	return epicBackstory;
}

void Character::operator==(const Character typeToCompare) // Compares two character by simply printing both of their stats.
{
	std::cout << name + "'s Max Health: " << maxHealth << "\n";
	std::cout << typeToCompare.name + "'s Max Health: " << typeToCompare.maxHealth << "\n\n";

	std::cout << name + "'s Species: " << species << "\n";
	std::cout << typeToCompare.name + "'s Species: " << typeToCompare.species << "\n\n";

	std::cout << name + "'s Weapon: " << currentWeapon << "\n";
	std::cout << typeToCompare.name + "'s Weapon: " << typeToCompare.currentWeapon << "\n";

	std::cout << "\n";

	std::cout << name + "'s Armour: " << currentArmour << "\n";
	std::cout << typeToCompare.name + "'s Armour: " << typeToCompare.currentArmour << "\n";

}

std::ostream& operator<<(std::ostream &os, const Character &selectedCharacter)
{
	os << "\nName: " << selectedCharacter.name << "\n";
	os << "\nSpecies: " << selectedCharacter.species << "\n";
	os << "\nStory: " << selectedCharacter.epicBackstory << "\n";
	os << "\n\nCurrent Weapon: " << selectedCharacter.currentWeapon << "\n";
	os << "\n\nCurrent Armour: " << selectedCharacter.currentArmour << "\n";
	return os;
}

