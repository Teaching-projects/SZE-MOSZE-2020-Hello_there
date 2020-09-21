#include "Unit.h"

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

void Unit::Defend(const Unit atkUnit)
{
    std::cout << atkUnit.GetName() << " -> " << this->GetName() << std::endl;

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