#pragma once
#include "Monster.h"
#include <string>
class Hero : public Monster
{
private:
	int maxHP;
	int xp = 0;
	int lvl = 1;
	void LvlUp();
	void addXp(int number);

public:
	Hero(const Monster &u);
	std::string ToString() const override;
	int getXp() const;
	int getMaxHealthPoints() const;
	void Attack(Monster &) override;
	int getLevel() const;
};