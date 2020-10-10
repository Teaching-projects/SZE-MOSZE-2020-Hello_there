#pragma once
#include "Unit.h"
#include <string>
class Player :public Unit {
private:
	int maxHP;
	int xp;
	int lvl;

public:
	Player(std::string name, int hp, int dmg);
	Player(Unit u);
	std::string ToString();
	void LvlUp();
	void addXp(int number);
	int getXp() { return xp; };
	void Attack(Unit&);

};