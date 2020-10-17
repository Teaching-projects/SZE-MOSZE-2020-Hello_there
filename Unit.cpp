#include "Unit.h"
#include <fstream>
#include <algorithm>

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
	std::ifstream input_file("units/" + fileName);
	if (input_file.is_open())
	{

		std::string name;
		std::string temp_hp;
		std::string temp_dmg;
		std::string temp_atkSpd;

		input_file.ignore(1, '{');
		input_file.ignore(1, '\n');
		input_file.ignore(1, '\t');

		std::getline(input_file, name, ',');
		name.erase(std::remove(name.begin(), name.end(), '\"'), name.end());
		name.erase(0, 6);

		input_file.ignore(1, '\n');
		input_file.ignore(1, '\t');
		std::getline(input_file, temp_hp, ',');
		temp_hp.erase(std::remove(temp_hp.begin(), temp_hp.end(), '\"'), temp_hp.end());
		temp_hp.erase(0, 4);

		input_file.ignore(1, '\n');
		input_file.ignore(1, '\t');
		std::getline(input_file, temp_dmg, ',');
		temp_dmg.erase(std::remove(temp_dmg.begin(), temp_dmg.end(), '\"'), temp_dmg.end());
		temp_dmg.erase(0, 5);

		input_file.ignore(1, '\n');
		input_file.ignore(1, '\t');
		std::getline(input_file, temp_atkSpd);
		temp_atkSpd.erase(std::remove(temp_atkSpd.begin(), temp_atkSpd.end(), '\"'), temp_atkSpd.end());
		temp_atkSpd.erase(0, 16);

		input_file.close();
		int hp = std::stoi(temp_hp);
		int dmg = std::stoi(temp_dmg);
		float atkSpd = std::stof(temp_atkSpd);

		return Unit(name, hp, dmg, atkSpd);
	}
	else
		throw fileName;
}

void Unit::Attack(Unit &targetUnit)
{
	targetUnit.TakeDamage(*this);
}
