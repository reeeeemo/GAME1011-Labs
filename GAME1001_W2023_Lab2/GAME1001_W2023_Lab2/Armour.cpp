#include "Armour.h"

Armour::Armour()
{
}

Armour::Armour(std::string desc, std::string name, int inputDefense)
{
    description = desc;
    epicArmourName = name;
    defenseValue = inputDefense;
}


std::string Armour::GetName() {
    return epicArmourName;
};

// Overloaded << operator for Armour
std::ostream& operator<<(std::ostream& os, const Armour& armourToPrint)
{
    os << armourToPrint.epicArmourName << "\n" <<
        "Defense Value: " << armourToPrint.defenseValue << "\n" << 
        "Description: " << armourToPrint.description << "\n";
    return os;
}
