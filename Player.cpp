#include "Player.h"
#include <math.h>

Player::Player(std::string name,int hp,int dmg) 
	: Unit(name, hp, dmg ),maxHP(hp)
{
}
Player::Player(Unit u)
	: Unit(u.GetName(), u.GetHp(), u.GetDmg()),maxHP(u.GetHp())
{
}

std::string Player::ToString()
{
	return "asd";
}

void Player::LvlUp()
{
	if (xp >= 100) {
		maxHP =nearbyint(maxHP*1.1);
		hp = maxHP;
		dmg = nearbyint(dmg * 1.1);
		lvl++;
		xp -= 100;
		LvlUp();
	}
}
void Player::addXp(int number) {
	xp += number;
}
void Player::Attack(Unit& attackedUnit) {
	addXp(attackedUnit.Defend(this->GetDmg()));
	LvlUp();
}