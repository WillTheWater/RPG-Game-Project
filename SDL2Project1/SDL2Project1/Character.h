#pragma once
#include <iostream>
#include <string>

class Character
{
public:
	Character();
	~Character();
	void SetupStats(std::string name, int vita, int str, int dex, int intel);
	void DisplayStats();
	int GetVita();
	int GetMaxVita();
	int GetDex();
	int GetDamage();
	void TakeDamage(int dmg);
	std::string GetName();

protected:
	std::string m_Name;
	int m_Vita{}, m_Str{}, m_Dex{}, m_Intel{}, m_MaxVita{};
};