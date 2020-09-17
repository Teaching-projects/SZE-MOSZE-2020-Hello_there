#include "Unit.h"

Unit::Unit(std::string name, int hp, int dmg)
    : name(name), hp(hp), dmg(dmg)
{
}

bool Unit::IsDead() const
{
    return (hp <= 0) ? true : false;
}

int Unit::GetDmg() const
{
    return dmg;
}

void Unit::Defend(Unit atkUnit)
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