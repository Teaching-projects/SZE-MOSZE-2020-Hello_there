#include "Player.h"
#include <math.h>

Player::Player(const Unit &u)
	: Unit(u.GetName(), u.GetHp(), u.GetDmg(), u.GetAtkCoolDown()), maxHP(u.GetHp())
{
}

std::string Player::ToString() const
{
	return Unit::ToString() + "LVL: " + std::to_string(lvl) + " Xp: " + std::to_string(xp) + "\n";
}

int Player::getXp() const
{
	return xp;
}

void Player::LvlUp()
{
	if (xp >= 100)
	{
		maxHP = nearbyint(maxHP * 1.1);
		hp = maxHP;
		dmg = nearbyint(dmg * 1.1);
		lvl++;
		xp -= 100;
		LvlUp();
	}
}
void Player::addXp(int number)
{
	xp += number;
}
void Player::Attack(Unit &attackedUnit)
{
	addXp(attackedUnit.TakeDamage(*this));
	LvlUp();
}

int Player::getLvl() const
{
	return lvl;
}
