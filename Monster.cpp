#include "Monster.h"
#include <algorithm>
#include <iostream>
#include <vector>


Monster::Monster(const std::string &name, int hp, int dmg, double atkCooldown, int defense)
	: name(name), hp(hp), dmg(dmg), atkCooldown(atkCooldown), defense(defense), x(-1), y(-1)
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

int Monster::GetXCoo() const
{
	return x;
}

int Monster::GetYCoo() const
{
	return y;
}
int Monster::getDefense() const
{
	return defense;
}


double Monster::getAttackCoolDown() const
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

void Monster::SetCoordinates(int x, int y)
{
	this->x = x;
	this->y = y;
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
	JSON properties = JSON::parseFromFile("units/"+fileName);

	const std::vector<std::string> expectedProps{ "name", "health_points", "damage", "attack_cooldown", "defense" };
	for (unsigned int i = 0; i < expectedProps.size(); i++)
	{
		if (!properties.count(expectedProps[i]))
		{
			throw std::invalid_argument("Missing monster properties in file: " + fileName + " " + expectedProps[i]);
		}
	}

	return Monster(
		properties.get<std::string>("name"),
		properties.get<int>("health_points"),
		properties.get<int>("damage"),
		properties.get<double>("attack_cooldown"),
    properties.get<int>("defense"));
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
	double slowerMonsterTimer = 0.0;

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