#pragma once
#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

class GameObject // Pure abstract class, only meant for objects to derive from.
{
public:
	// Abstract functions.
	virtual void NormalAttack() = 0;
};

#endif // !__GAMEOBJECT_H__

