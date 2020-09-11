#include "Unit.h"

Unit::Unit(std::string name, int hp, int dmg)
    : name(name), hp(hp), dmg(dmg)
{
}

Unit::~Unit()
{
}

const bool Unit::IsDead()
{
    if (hp <= 0)
        return true;
    return false;
}

const int Unit::Attack()
{
    return dmg;
}

void Unit::Defend(int dmg)
{
    if (dmg > hp)
    {
        hp = 0;
    }
    else
    {
        hp -= dmg;
    }
}

const std::string Unit::GetName()
{
    return name;
}

const int Unit::GetHp()
{
    return hp;
}

const std::string Unit::ToString()
{
    std::string s = name + ": HP: " + std::to_string(hp) + ", DMG: " + std::to_string(dmg) + "\n";
    return s;
}