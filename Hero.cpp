#include "Hero.h"
#include <iostream>
#include <cmath>

Hero::Hero(const std::string &name, int hp, int dmg, float atkCooldown, const int xp_per_lvl, const int hp_per_lvl, const int dmg_per_lvl, const float cdr_per_lvl)
	: Monster(name, hp, dmg, atkCooldown),
	  maxHP(hp), xp_per_lvl(xp_per_lvl), hp_per_lvl(hp_per_lvl),
	  dmg_per_lvl(dmg_per_lvl), cdr_per_lvl(cdr_per_lvl)
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
	if (xp >= xp_per_lvl)
	{
		maxHP += hp_per_lvl;
		hp = maxHP;
		dmg += dmg_per_lvl;
		atkCooldown *= cdr_per_lvl;
		lvl++;
		xp -= xp_per_lvl;
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
Hero Hero::parse(std::string &fileName)
{
	std::ifstream inputFile("units/" + fileName);
	if (inputFile.is_open())
	{
		JSON HeroValues = JSON::parseFromStream(inputFile);

		std::string name = HeroValues.get<std::string>("name");
		int hp = HeroValues.get<int>("base_health_points");
		int dmg = HeroValues.get<int>("base_damage");
		float atkCooldown = HeroValues.get<float>("base_attack_cooldown");

		int xp_per_lvl = HeroValues.get<int>("experience_per_level");
		int hp_per_lvl = HeroValues.get<int>("health_point_bonus_per_level");
		int dmg_per_lvl = HeroValues.get<int>("damage_bonus_per_level");
		float cdr_per_lvl = HeroValues.get<float>("cooldown_multiplier_per_level");

		return Hero(name, hp, dmg, atkCooldown, xp_per_lvl, hp_per_lvl, dmg_per_lvl, cdr_per_lvl);
	}
	else
		throw fileName;
}
