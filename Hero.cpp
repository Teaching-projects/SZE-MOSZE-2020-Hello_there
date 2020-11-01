#include "Hero.h"
#include <cmath>

Hero::Hero(const Monster &u)
	: Monster(u.getName(), u.getHealthPoints(), u.getDamage(), u.getAttackCoolDown
	()), maxHP(u.getHealthPoints())
{
}

std::string Hero::ToString() const
{
	return Monster::ToString() + "LVL: " + std::to_string(lvl) + " Xp: " + std::to_string(xp) + "\n";
}

int Hero::getXp() const
{
	return xp;
}

int Hero::getMaxHealthPoints() const
{
	return maxHP;
}

void Hero::LvlUp()
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
void Hero::addXp(int number)
{
	xp += number;
}
void Hero::Attack(Monster &attackedMonster)
{
	addXp(attackedMonster.TakeDamage(*this));
	LvlUp();
}

int Hero::getLevel() const
{
	return lvl;
}
