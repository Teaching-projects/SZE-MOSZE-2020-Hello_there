#pragma once

#include <string>
#include <iostream>

class Unit
{
private:
    const std::string name;
    int hp;
    const int dmg;

public:
    Unit(std::string name, int hp, int dmg);

    bool IsDead() const;
    int GetDmg() const;
    void Defend(const Unit &atkUnit);
    std::string GetName() const;
    int GetHp() const;
    std::string ToString() const;
    static Unit parseUnit(std::string &fileName);
};