/**
* \class Player
*
* derived from Unit class, capable of gaining xp and leveling up
*
* \author Holdmedve
* \date 2020_10_09
*/

#pragma once
#include "Unit.h"
#include <string>
class Player : public Unit
{
private:
	int maxHP;
	int xp = 0;
	int lvl = 1;
	void LvlUp();
	void addXp(int number);

public:
	/**
     * \brief Player constructor
	 * \param u Unit that creates base/parent class
    */
	Player(const Unit &u);

	/// \return std::string
	std::string ToString() const override;

	/// \return int
	int getXp() const;

	/// deliver one hit
	void Attack(Unit &) override;

	/// \return int
	int getLvl() const;
};