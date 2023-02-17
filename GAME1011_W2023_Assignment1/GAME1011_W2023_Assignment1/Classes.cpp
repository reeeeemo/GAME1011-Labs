#include "Classes.h"

void Player::NormalAttack()
{
	// Do something here.
}

std::string Player::GetName()
{
	return name;
}

int Player::GetHP()
{
	return current_health;
}

void Player::SetName(std::string inputName)
{
	name = inputName;
}

void Player::SetHP(int inputHealth)
{
	current_health = inputHealth;
}

void Enemy::NormalAttack()
{
	// Do something here.
}

int Enemy::GetHP()
{
	return current_health;
}

void Enemy::SetHP(int inputHealth)
{
	current_health = inputHealth;
}

void Wizard::SpecialAttack()
{
	// Special Wizard Attack here.
}

void Knight::SpecialAttack()
{
	// Special Knight Attack here.
}

void Orc::TauntPlayer()
{
	// Special Orc Taunt here.
}

void Undead::TauntPlayer()
{
	// Special Undead Taunt here.
}



