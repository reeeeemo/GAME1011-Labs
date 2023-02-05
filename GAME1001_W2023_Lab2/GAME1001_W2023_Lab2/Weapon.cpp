#include "Weapon.h"

Weapon::Weapon() 
{
}

Weapon::Weapon(std::vector<std::string> abilities, std::string name, int inputDamage)
{
    special_abilities = abilities;
    epicWeaponName = name;
    damage = inputDamage;
}

std::string Weapon::GetName()
{
    return epicWeaponName;
}



// Overloaded << operator for Weapons
std::ostream& operator<<(std::ostream& os, const Weapon & weaponToPrint)
{
    os << weaponToPrint.epicWeaponName << "\n" <<
        "Damage: " << weaponToPrint.damage << "\n" << "Abilities: " << "\n";

    for (std::string ability : weaponToPrint.special_abilities) {
        os << ability << "\n";
    }
    return os;
}
