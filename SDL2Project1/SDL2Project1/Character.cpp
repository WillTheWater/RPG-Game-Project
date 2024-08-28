#include "Character.h"

Character::Character()
{
}

Character::~Character()
{
}

void Character::SetupStats(std::string name, int vita, int str, int dex, int intel)
{
	m_Name = name;
	m_Vita = vita;
	m_Str = str;
	m_Dex = dex;
	m_Intel = intel;
}

void Character::DisplayStats()
{
	std::cout << "    *     Character Name: " << m_Name << std::endl;
	std::cout << "    *           Vitality: " << m_Vita << std::endl;
	std::cout << "    *           Strength: " << m_Str << std::endl;
	std::cout << "    *          Dexterity: " << m_Dex << std::endl;
	std::cout << "    *       Intelligence: " << m_Intel << std::endl;
}

int Character::GetVita()
{
	return m_Vita;
}

int Character::GetMaxVita()
{
	return m_MaxVita;
}

int Character::GetDex()
{
	return m_Dex;
}

int Character::GetDamage()
{
	return m_Str;
}

void Character::TakeDamage(int dmg)
{
	m_Vita -= dmg;
}

std::string Character::GetName()
{
	return m_Name;
}