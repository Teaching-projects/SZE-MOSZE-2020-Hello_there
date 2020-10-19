#pragma once
#include "Unit.h"
#include <string>
class Player : public Unit
{
private:
	int maxHP;
	int xp = 0;
	int lvl = 1;
	void LvlUp();
	void addXp(int number);

public:
	Player(const Unit &u);
	std::string ToString() const override;
	int getXp() const;
	void Attack(Unit &) override;
	int getLvl() const;
};