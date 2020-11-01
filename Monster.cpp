#include "Monster.h"
#include <algorithm>
#include <iostream>

Monster::Monster(std::string name, int hp, int dmg, float atkCooldown)
	: name(name), hp(hp), dmg(dmg), atkCooldown(atkCooldown)
{
}

bool Monster::isAlive() const
{
	return hp;
}

int Monster::getDamage() const
{
	return dmg;
}

float Monster::getAttackCoolDown() const
{
	return atkCooldown;
}

int Monster::TakeDamage(const Monster &atkMonster)
{
	int dmgInflected = atkMonster.getDamage();
	if (dmgInflected > hp)
	{
		hp -= dmgInflected;
		dmgInflected += hp;
		hp = 0;
	}
	else
		hp -= dmgInflected;

	return dmgInflected;
}

std::string Monster::getName() const
{
	return name;
}

int Monster::getHealthPoints() const
{
	return hp;
}

std::string Monster::ToString() const
{
	std::string s = name + ": HP: " + std::to_string(hp) + ", DMG: " + std::to_string(dmg) + "\n";
	return s;
}

Monster Monster::ParseMonster(std::string &fileName)
{
	std::ifstream inputFile("Monsters/" + fileName);
	if (inputFile.is_open())
	{
		std::map<std::string, std::string> MonsterValues;
		MonsterValues = JSON::Parse(inputFile);

		std::string name = MonsterValues["name"];
		int hp = std::stoi(MonsterValues["hp"]);
		int dmg = std::stoi(MonsterValues["dmg"]);
		float atkCooldown = std::stof(MonsterValues["attackcooldown"]);
		return Monster(name, hp, dmg, atkCooldown);
	}
	else
		throw fileName;
}

void Monster::Attack(Monster &targetMonster)
{
	targetMonster.TakeDamage(*this);
}

void Monster::fightTilDeath(Monster& m)
{
	Monster *slowerMonster;
	Monster *fasterMonster;

	if (this->getAttackCoolDown() < m.getAttackCoolDown())
	{
		fasterMonster = this;
		slowerMonster = &m;
	}
	else
	{
		fasterMonster = &m;
		slowerMonster = this;
	}

	this->Attack(m);
	m.Attack(*this);
	float slowerMonsterTimer = 0.0;

	for (slowerMonsterTimer += fasterMonster->getAttackCoolDown(); !fasterMonster->isAlive() && !slowerMonster->isAlive(); slowerMonsterTimer += fasterMonster->getAttackCoolDown())
	{
		if (slowerMonsterTimer > slowerMonster->getAttackCoolDown())
		{
			fasterMonster->Attack(*slowerMonster);
			if (!fasterMonster->isAlive())
				slowerMonster->Attack(*fasterMonster);
			slowerMonsterTimer -= slowerMonster->getAttackCoolDown();
		}
		else if (slowerMonsterTimer == slowerMonster->getAttackCoolDown())
		{
			slowerMonster->Attack(*fasterMonster);
			if (!slowerMonster->isAlive())
				fasterMonster->Attack(*slowerMonster);
			slowerMonsterTimer = 0.0;
		}
		else
		{
			slowerMonster->Attack(*fasterMonster);
		}
	}

	if (fasterMonster->isAlive())
		std::cout << slowerMonster->getName() << " wins. Remaining HP: " << slowerMonster->getHealthPoints() << std::endl;
	else
		std::cout << fasterMonster->getName() << " wins. Remaining HP: " << fasterMonster->getHealthPoints() << std::endl;
}
