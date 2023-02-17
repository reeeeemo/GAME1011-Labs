#pragma once
#ifndef __CLASSES_H__
#define __CLASSES_H__

#include <string>
#include <vector>
#include "GameObject.h"

// Abstract Player class.
class Player : public GameObject
{
public:
	// Abstract functions.
	void NormalAttack() override;
	virtual void SpecialAttack();

	// Accessors
	std::string GetName();
	int GetHP();

	// Mutators
	void SetName(std::string inputName);
	void SetHP(int inputHealth);
protected:
	std::string name;
	int current_health;
	int max_health;
};

// Abstract Enemy class.
class Enemy : public GameObject
{
public:
	// Abstract Functions.
	void NormalAttack() override;
	virtual void TauntPlayer();

	// Accessors.
	int GetHP();
	// Mutators.
	void SetHP(int inputHealth);

protected:
	int current_health;
	int max_health;
};

// Wizard Class
class Wizard final : Player
{
public:
	void SpecialAttack() override;
private:
	static std::string specialAttackName;
	int specialAttackAmount;
};
// Knight Class
class Knight final : Player
{
public:
	void SpecialAttack() override;
private:
	static std::string specialAttackName;
	int specialAttackAmount;
};
// Orc Class
class Orc final : Enemy
{
public:
	void TauntPlayer() override;
private:
	static std::string species_name;
	std::vector<std::string> taunts;
};
// Undead Class
class Undead final : Enemy
{
public:
	void TauntPlayer() override;
private:
	static std::string species_name;
	std::vector<std::string> taunts;
};

#endif // !__CLASSES_H__
