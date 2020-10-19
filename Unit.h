/**
* \class Unit
*
* This class is responsible for creating units and managing fights between them.
*
* \author Holdmedve
* \date 2020_10_09
*/

#pragma once

#include <string>
#include <iostream>

class Unit
{
private:
    const std::string name;
    const float atkCooldown; ///< time it takes for the unit to be able to hit again

    friend class Player;

protected:
    int hp;
    int dmg;

    /// suffer the damage
    int TakeDamage(const Unit &atkUnit /** [in] attacking Unit that causes this Unit some damage*/);

public:
    /**
     * \brief Unit constructor
     * \param name the name of the unit
     * \param hp health points
     * \param dmg damage
     * \param atkCooldown attack cooldown
    */
    Unit(std::string name, int hp, int dmg, float atkCooldown);
    virtual ~Unit() {}

    /// \return boolean
    bool IsDead() const;

    /// \return int
    int GetDmg() const;

    /// \return std::string
    std::string GetName() const;

    /// \return int
    int GetHp() const;

    /// \return float
    float GetAtkCoolDown() const;

    /// returns an std::string that contains the unit's name, hp and dmg
    virtual std::string ToString() const;

    /** 
     * \brief given a json file, this static function creates a unit and returns it
     * \return Unit
     * \throw std::string&
    */
    static Unit ParseUnit(std::string &fileName /** [in] the json file name*/);

    /// attack the other unit and fight until one of them is dead
    virtual void Attack(Unit &targetUnit /** [in]*/);
	static void Fight(Unit& first, Unit& second);
};