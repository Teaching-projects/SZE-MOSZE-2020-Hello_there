#pragma once
#include "Unit.h"
#include <string>
class Player :public Unit {
private:
	int maxHP;
	int xp=0;
	int lvl=1;

public:
	Player(std::string &name, int hp, int dmg);
	Player(Unit u);
	std::string ToString() const override;
	void LvlUp();
	void addXp(int number);
	int getXp() { return xp; };
	void Attack(Unit&) override;
	int getLvl() { return lvl; }

};