#include "Hero.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

Hero::Hero(const std::string& name, int hp, int dmg, double atkCooldown, int defense,const std::string& texture, const int xp_per_lvl, const int hp_per_lvl, const int dmg_per_lvl, const double cdr_per_lvl, const int def_per_lvl, const int light_radius)
	: Monster(name, hp, dmg, atkCooldown, defense,texture),
	maxHP(hp), xp_per_lvl(xp_per_lvl), hp_per_lvl(hp_per_lvl),
	dmg_per_lvl(dmg_per_lvl), cdr_per_lvl(cdr_per_lvl), def_per_lvl(def_per_lvl),
	light_radius(light_radius), light_radius_bonus_per_level(1)
{
}

Hero::Hero(const std::string& name, int hp, int dmg, double atkCooldown, int defense,const std::string& texture, const int xp_per_lvl, const int hp_per_lvl, const int dmg_per_lvl, const double cdr_per_lvl, const int def_per_lvl, const int light_radius, const int light_radius_bonus_per_level)
	: Monster(name, hp, dmg, atkCooldown, defense, texture),
	maxHP(hp), xp_per_lvl(xp_per_lvl), hp_per_lvl(hp_per_lvl),
	dmg_per_lvl(dmg_per_lvl), cdr_per_lvl(cdr_per_lvl), def_per_lvl(def_per_lvl),
	light_radius(light_radius), light_radius_bonus_per_level(light_radius_bonus_per_level)
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
		defense += def_per_lvl;
		light_radius += light_radius_bonus_per_level;
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
Hero* Hero::parse(std::string &fileName)
{
	JSON properties = JSON::parseFromFile("units/" + fileName);

	const std::vector<std::string> expectedProps{"name", "base_health_points", "base_damage", "base_attack_cooldown", "base_defense", "experience_per_level", "health_point_bonus_per_level", "damage_bonus_per_level", "cooldown_multiplier_per_level", "defense_bonus_per_level","light_radius"};
	for (unsigned int i = 0; i < expectedProps.size(); i++)
	{
		if (!properties.count(expectedProps[i]))
		{
			throw std::invalid_argument("Missing monster properties in file: " + fileName + " " + expectedProps[i]);
		}
	}
	if (!properties.count("light_radius_bonus_per_level")) {
		return new Hero(
			properties.get<std::string>("name"),
			properties.get<int>("base_health_points"),
			properties.get<int>("base_damage"),
			properties.get<double>("base_attack_cooldown"),
			properties.get<int>("base_defense"),
			properties.get<std::string>("texture"),
			properties.get<int>("experience_per_level"),
			properties.get<int>("health_point_bonus_per_level"),
			properties.get<int>("damage_bonus_per_level"),
			properties.get<double>("cooldown_multiplier_per_level"),
			properties.get<int>("defense_bonus_per_level"),
			properties.get<int>("light_radius"));
	}
	else {
		return new Hero(
			properties.get<std::string>("name"),
			properties.get<int>("base_health_points"),
			properties.get<int>("base_damage"),
			properties.get<double>("base_attack_cooldown"),
			properties.get<int>("base_defense"),
			properties.get<std::string>("texture"),
			properties.get<int>("experience_per_level"),
			properties.get<int>("health_point_bonus_per_level"),
			properties.get<int>("damage_bonus_per_level"),
			properties.get<double>("cooldown_multiplier_per_level"),
			properties.get<int>("defense_bonus_per_level"),
			properties.get<int>("light_radius"),
			properties.get<int>("light_radius_bonus_per_level"));
	}
}

int Hero::getLightRadius() const
{
	return light_radius;
}
