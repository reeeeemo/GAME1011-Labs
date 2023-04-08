#include "Pancake.h"

Pancake::Pancake()
{
	hasSyrup = false;
	hasButter = false;
}

Pancake::~Pancake()
{ }

// Fun little output class :)
void Pancake::OutputPancake()
{
	std::cout << "Pancake has been eaten!\n";
	if (hasSyrup)
	{
		std::cout << "Wow, it was sticky!\n";
	}
	if (hasButter)
	{
		std::cout << "Wow, it was super buttery!\n";
	}
}

void Pancake::PourSyrup()
{
	hasSyrup = true;
}

void Pancake::AddButter()
{
	hasButter = true;
}

