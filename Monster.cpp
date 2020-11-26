#include "Monster.h"
#include <algorithm>
#include <iostream>

Monster::Monster(const std::string& name, int hp, int dmg, float atkCooldown, int defense)
	: name(name), hp(hp), dmg(dmg), atkCooldown(atkCooldown), defense(defense)
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

int Monster::getDefense() const
{
	return defense;
}

float Monster::getAttackCoolDown() const
{
	return atkCooldown;
}

int Monster::TakeDamage(const Monster &atkMonster)
{
	int dmgInflected = atkMonster.getDamage()-defense;
	if (dmgInflected < 0) dmgInflected = 0;
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
	std::string s = name + ": HP: " + std::to_string(hp) + ", DMG: " + std::to_string(dmg) +"AtkCD: "+std::to_string(atkCooldown)+"Defense: "+std::to_string(defense)+"\n";
	return s;
}

Monster Monster::parse(const std::string &fileName)
{
	std::ifstream inputFile("units/" + fileName);
	if (inputFile.is_open())
	{
		JSON MonsterValues = JSON::parseFromStream(inputFile);
		std::string name = MonsterValues.get<std::string>("name");
		int hp = MonsterValues.get<int>("health_points");
		int dmg = MonsterValues.get<int>("damage");
		float atkCooldown = MonsterValues.get<float>("attack_cooldown");
		int def = MonsterValues.get<int>("defense");

		return Monster(name, hp, dmg, atkCooldown,def);
	}
	else
		throw fileName;
}

void Monster::Attack(Monster &targetMonster)
{
	targetMonster.TakeDamage(*this);
}

void Monster::fightTilDeath(Monster &m)
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

	for (slowerMonsterTimer += fasterMonster->getAttackCoolDown(); fasterMonster->isAlive() && slowerMonster->isAlive(); slowerMonsterTimer += fasterMonster->getAttackCoolDown())
	{
		if (slowerMonsterTimer > slowerMonster->getAttackCoolDown())
		{
			fasterMonster->Attack(*slowerMonster);
			if (slowerMonster->isAlive())
				slowerMonster->Attack(*fasterMonster);
			slowerMonsterTimer += slowerMonster->getAttackCoolDown();
		}
		else if (slowerMonsterTimer == slowerMonster->getAttackCoolDown())
		{
			slowerMonster->Attack(*fasterMonster);
			if (fasterMonster->isAlive())
				fasterMonster->Attack(*slowerMonster);
			slowerMonsterTimer = 0.0;
		}
		else
		{
			slowerMonster->Attack(*fasterMonster);
		}
	}
}