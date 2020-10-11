#include "Unit.h"
#include <algorithm>

Unit::Unit(std::string name, int hp, int dmg)
	: name(name), hp(hp), dmg(dmg)
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

void Unit::Defend(const Unit &atkUnit)
{
	int dmgInflected = atkUnit.GetDmg();

	if (dmgInflected > hp)
		hp = 0;
	else
		hp -= dmgInflected;
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
Unit Unit::ParseUnit(const std::string &fileName)
{
	std::ifstream inputFile("units/" + fileName);
	if (inputFile.is_open())
	{
		std::map<std::string, std::string> unitValues;
		unitValues = JsonParser::Parse(inputFile);

		std::string name = unitValues["name"];
		int hp = std::stoi(unitValues["hp"]);
		int dmg = std::stoi(unitValues["dmg"]);
		return Unit(name, hp, dmg);
	}
	else
		throw fileName;
}