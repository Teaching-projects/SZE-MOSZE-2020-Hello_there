#pragma once

#include <string>
#include <iostream>

class Unit
{
private:
    const std::string name;
    int hp;
    const int dmg;
    const float atkCooldown; // [secundum / attack]

public:
    Unit(std::string name, int hp, int dmg, float atkCooldown);

    bool IsDead() const;
    int GetDmg() const;
    std::string GetName() const;
    int GetHp() const;

    std::string ToString() const;
    static Unit parseUnit(std::string &fileName);
    void Attack(Unit &targetUnit);

private:
    void TakeDamage(const Unit &atkUnit);
};