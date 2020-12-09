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
    double atkCooldown; ///< time it takes for the Monster to be able to hit again
    int x;              // row coordinate
    int y;              // column coordinate
	std::string texture; // name of the texture file
    friend class Hero;

protected:
    int hp;
    int dmg;
    int defense;
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

    Monster(const std::string &name, int hp, int dmg, double atkCooldown, int defense,std::string texture);

    virtual ~Monster() {}

	/**
	* @brief Returns true if the monster is alive
	* @return bool
	*/
    bool isAlive() const;

	/**
	* @brief Returns the damage value of monster.
	* @return int
	*/
    int getDamage() const;

	/**
	* @brief Returns the defense value of monster.
	* @return int
	*/
    int getDefense() const;

	/**
	* @brief Returns the name of the monster.
	* @return std::string
	*/
    std::string getName() const;

	/**
	* @brief Returns remaining hp of the mosnter.
	* @return int
	*/
    int getHealthPoints() const;

	/**
	* @brief Returns attack cooldown of monster.
	* @return double
	*/
    double getAttackCoolDown() const;

    /// \return int
    int GetXCoo() const;

	/// \return int
	int GetYCoo() const;
	/// \return string
	std::string GetTexture() const;

	/**
	* @brief Returns the damage inflicted by atkMonster.
	* @param const Monster attacking monster to take damage from.
	* @return int 
	*/
    int TakeDamage(const Monster &atkMonster /** [in] attacking Monster that causes this Monster some damage*/);

    /// returns an std::string that contains the Monster's name, hp and dmg
    virtual std::string ToString() const;

    /** 
     * \brief given a json file, this static function creates a Monster and returns it
     * \return Monster
     * \throw std::string&
    */
    static Monster *parse(const std::string &fileName /** [in] the json file name*/);

    void SetCoordinates(int x, int y);

    void fightTilDeath(Monster &m);
};