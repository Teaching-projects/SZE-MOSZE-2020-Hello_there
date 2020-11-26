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
	const float cdr_per_lvl;
	void LvlUp();
	void addXp(int number);


public:
	Hero(const std::string& name, int hp, int dmg, float atkCooldown,int defense, const int xp_per_lvl, const int hp_per_lvl, const int dmg_per_lvl, const float cdr_per_lvl,const int def_per_lvl);
	std::string ToString() const override;
	int getXp() const;
	int getMaxHealthPoints() const;
	void Attack(Monster &) override;
	int getLevel() const;
	static Hero parse(std::string& fileName);
};