/**
* \class Monster
*
* This class is responsible for creating Monsters and managing fights between them.
*
* \author Holdmedve
* \date 2020_10_09
*/

#pragma once

#include "JSON.h"

class Monster
{
private:
    const std::string name;
    float atkCooldown; ///< time it takes for the Monster to be able to hit again
    int x;             // row coordinate
    int y;             // column coordinate

    friend class Hero;

protected:
    int hp;
    int dmg;
    /// attack the other Monster and fight until one of them is dead
    virtual void Attack(Monster &targetMonster /** [in]*/);

public:
    /**
     * \brief Monster constructor
     * \param name the name of the Monster
     * \param hp health points
     * \param dmg damage
     * \param atkCooldown attack cooldown
    */
    Monster(const std::string &name, int hp, int dmg, float atkCooldown);
    virtual ~Monster() {}

    /// \return boolean
    bool isAlive() const;

    /// \return int
    int getDamage() const;

    /// \return std::string
    std::string getName() const;

    /// \return int
    int getHealthPoints() const;

    /// \return float
    float getAttackCoolDown() const;

    /// suffer the damage
    int TakeDamage(const Monster &atkMonster /** [in] attacking Monster that causes this Monster some damage*/);

    /// returns an std::string that contains the Monster's name, hp and dmg
    virtual std::string ToString() const;

    /** 
     * \brief given a json file, this static function creates a Monster and returns it
     * \return Monster
     * \throw std::string&
    */
    static Monster parse(const std::string &fileName /** [in] the json file name*/);

    void SetCoordinates(int x, int y);

    void fightTilDeath(Monster &m);
};