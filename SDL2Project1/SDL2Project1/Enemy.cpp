#include "Enemy.h"


Enemy::Enemy(std::string name, int vita, int maxVita, int str, int dex, int intel)
{
	m_Name = name;
	m_Vita = vita;
	m_MaxVita = maxVita;
	m_Str = str;
	m_Dex = dex;
	m_Intel = intel;
}


Enemy::~Enemy()
{
}

std::string Enemy::GetName()
{
	return m_Name;
}

void Enemy::MakeNoise()
{
	std::cout << GetName() << " grumbles loudly!" << std::endl;
}