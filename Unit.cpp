#include "Unit.h"
#include <algorithm>
#include <iostream>

Unit::Unit(std::string name, int hp, int dmg, float atkCooldown)
	: name(name), hp(hp), dmg(dmg), atkCooldown(atkCooldown)
{
}

bool Unit::IsDead() const
{
	return !hp;
}

int Unit::GetDmg() const
{
	return dmg;
}

float Unit::GetAtkCoolDown() const
{
	return atkCooldown;
}

int Unit::TakeDamage(const Unit &atkUnit)
{
	int dmgInflected = atkUnit.GetDmg();
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

std::string Unit::GetName() const
{
	return name;
}

int Unit::GetHp() const
{
	return hp;
}

std::string Unit::ToString() const
{
	std::string s = name + ": HP: " + std::to_string(hp) + ", DMG: " + std::to_string(dmg) + "\n";
	return s;
}

Unit Unit::ParseUnit(std::string &fileName)
{
	std::ifstream inputFile("units/" + fileName);
	if (inputFile.is_open())
	{
		std::map<std::string, std::string> unitValues;
		unitValues = JsonParser::Parse(inputFile);

		std::string name = unitValues["name"];
		int hp = std::stoi(unitValues["hp"]);
		int dmg = std::stoi(unitValues["dmg"]);
		float atkCooldown = std::stof(unitValues["attackcooldown"]);
		return Unit(name, hp, dmg, atkCooldown);
	}
	else
		throw fileName;
}

void Unit::Attack(Unit &targetUnit)
{
	targetUnit.TakeDamage(*this);
}

void Unit::Fight(Unit &first, Unit &second)
{
	Unit *slowerUnit;
	Unit *fasterUnit;

	if (first.GetAtkCoolDown() < second.GetAtkCoolDown())
	{
		fasterUnit = &first;
		slowerUnit = &second;
	}
	else
	{
		fasterUnit = &second;
		slowerUnit = &first;
	}

	first.Attack(second);
	second.Attack(first);
	float slowerUnitTimer = 0.0;

	for (slowerUnitTimer += fasterUnit->GetAtkCoolDown(); !fasterUnit->IsDead() && !slowerUnit->IsDead(); slowerUnitTimer += fasterUnit->GetAtkCoolDown())
	{
		if (slowerUnitTimer > slowerUnit->GetAtkCoolDown())
		{
			fasterUnit->Attack(*slowerUnit);
			if (!fasterUnit->IsDead())
				slowerUnit->Attack(*fasterUnit);
			slowerUnitTimer -= slowerUnit->GetAtkCoolDown();
		}
		else if (slowerUnitTimer == slowerUnit->GetAtkCoolDown())
		{
			slowerUnit->Attack(*fasterUnit);
			if (!slowerUnit->IsDead())
				fasterUnit->Attack(*slowerUnit);
			slowerUnitTimer = 0.0;
		}
		else
		{
			slowerUnit->Attack(*fasterUnit);
		}
	}

	if (fasterUnit->IsDead())
		std::cout << slowerUnit->GetName() << " wins. Remaining HP: " << slowerUnit->GetHp() << std::endl;
	else
		std::cout << fasterUnit->GetName() << " wins. Remaining HP: " << fasterUnit->GetHp() << std::endl;
}
