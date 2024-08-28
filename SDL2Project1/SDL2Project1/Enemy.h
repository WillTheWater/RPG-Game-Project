#pragma once
#include "Character.h"
class Enemy : public Character
{
public:
	Enemy(std::string name, int vita, int maxVita, int str, int dex, int intel);
	~Enemy();

	std::string GetName();
	void MakeNoise();

private:


};