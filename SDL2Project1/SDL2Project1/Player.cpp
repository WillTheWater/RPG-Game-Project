#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

std::string Player::GetName()
{
	return m_Name;
}

void Player::Heal(int heal)
{
	m_Vita += heal;
	if (m_Vita > m_MaxVita) { m_Vita = m_MaxVita; }
}

int Player::SpecialAttack()
{
	return m_Str += 20;
}

void Player::Dodge()
{
	TakeDamage(0);
}