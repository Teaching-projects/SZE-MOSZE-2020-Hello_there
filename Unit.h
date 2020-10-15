#pragma once

#include <string>
#include <iostream>

class Unit
{
private:
    const std::string name;
protected:
    int hp;
    int dmg;

public:
    Unit(std::string name, int hp, int dmg);
	virtual ~Unit(){}
    bool IsDead() const;
    int GetDmg() const;
    int Defend(Unit& );
	virtual void Attack(Unit& attackedUnit);
    std::string GetName() const;
    int GetHp() const;
	virtual std::string ToString() const;
    static Unit parseUnit(std::string &fileName);
};