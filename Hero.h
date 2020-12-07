#pragma once
#include "Monster.h"
#include <string>
class Hero : public Monster
{
private:
	int maxHP;
	int xp = 0;
	int lvl = 1;
	const int xp_per_lvl;
	const int hp_per_lvl;
	const int dmg_per_lvl;

	const int def_per_lvl;
	const double cdr_per_lvl;

	void LvlUp();
	void addXp(int number);
	int light_radius;
	int light_radius_bonus_per_level;

public:

	Hero(const std::string& name, int hp, int dmg, double atkCooldown, int defense,std::string texture, const int xp_per_lvl, const int hp_per_lvl, const int dmg_per_lvl, const double cdr_per_lvl, const int def_per_lvl, const int light_radius);
	Hero(const std::string& name, int hp, int dmg, double atkCooldown, int defense, std::string texture, const int xp_per_lvl, const int hp_per_lvl, const int dmg_per_lvl, const double cdr_per_lvl, const int def_per_lvl, const int light_radius, const int light_radius_bonus_per_level);
  
	std::string ToString() const override;
	int getXp() const;
	int getMaxHealthPoints() const;
	void Attack(Monster &) override;
	int getLevel() const;
	static Hero* parse(std::string &fileName);
	int getLightRadius() const;
};