#pragma once

#include <string>
#include <iostream>

class Unit
{
private:
    const std::string name;
    int hp;
    int dmg;

public:
    Unit(std::string name, int hp, int dmg);
    ~Unit();

    const bool IsDead();
    const int Attack();
    void Defend(int dmg);
    const std::string GetName();
    const int GetHp();
    const std::string ToString();
};