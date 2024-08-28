#pragma once
#include <iostream>
#include <string>
#include "Character.h"

class Player : public Character
{
public:
	Player();
	~Player();

	std::string GetName();

	//--------Skills----------
	void Heal(int heal);
	int SpecialAttack();
	void Dodge();

private:

};