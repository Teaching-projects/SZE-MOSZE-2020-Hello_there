/**
 * \author BakiHUN
 * \brief Hero class
 *
 * The Hero class is responsible for managing the palayer character.
 *
 * \date 2020-12-09
 */
#pragma once
#include "Monster.h"
#include <string>
class Hero : public Monster
{
private:
	int maxHP;
	int xp = 0;
	int lvl = 1;
	const int xp_per_lvl;
	const int hp_per_lvl;
	const int dmg_per_lvl;

	const int def_per_lvl;
	const double cdr_per_lvl;

	void LvlUp();
	void addXp(int number);
	int light_radius;
	int light_radius_bonus_per_level;

public:
	/**
   * @brief Given a txt it returns the a game, with the map set.
   * @param const std::string &name
   * @param hp HealthPoints
   * @param dmg Damage
   * @param atkCooldown Cooldown of the attacks
   * @param defense Defense
   * @param texture Texture file name
   * @param xp_per_lvl Xp needed per lvl
   * @param hp_per_lvl HealthPoint increase with each level
   * @param dmg_per_lvl Damage increase with each level
   * @param cdr_per_lvl Cooldown reduction with each level
   * @param def_per_lvl Defense increase with each level
   * @param light_radius How far can the hero see.
   * @return Hero
   */
	Hero(const std::string &name, int hp, int dmg, double atkCooldown, int defense, const std::string &texture, const int xp_per_lvl, const int hp_per_lvl, const int dmg_per_lvl, const double cdr_per_lvl, const int def_per_lvl, const int light_radius);
	/**
   * @brief Given a txt it returns the a game, with the map set.
   * @param const std::string &name
   * @param hp HealthPoints
   * @param dmg Damage
   * @param atkCooldown Cooldown of the attacks
   * @param defense Defense
   * @param texture Texture file name
   * @param xp_per_lvl Xp needed per lvl
   * @param hp_per_lvl HealthPoint increase with each level
   * @param dmg_per_lvl Damage increase with each level
   * @param cdr_per_lvl Cooldown reduction with each level
   * @param def_per_lvl Defense increase with each level
   * @param light_radius How far can the hero see.
   * @param light_radius_bonus_per_level LightRadius increase with each level
   * @return Hero
   */
	Hero(const std::string &name, int hp, int dmg, double atkCooldown, int defense, const std::string &texture, const int xp_per_lvl, const int hp_per_lvl, const int dmg_per_lvl, const double cdr_per_lvl, const int def_per_lvl, const int light_radius, const int light_radius_bonus_per_level);
	/**
	* @brief Returns the Heros's name, hp, dmg, lvl, xp.
	* @return std::string
	*/
	std::string ToString() const override;
	/**
	* @brief Attack the other Monster.
	* @param targerMonster Monster that gets hit.
	* @return void
	*/
	void Attack(Monster &) override;
	/**
	* @brief Retruns the level of the hero.
	* @return int
	*/
	int getLevel() const;
	/**
	* @brief Returns a Hero pointer that is parsed from a file.
	* @param fileName The file containing the structure of the Hero
	* @return Hero*
	*/
	static Hero *parse(const std::string &fileName);
	/**
	* @brief Returns the light radius of the Hero.
	* @return int
	*/
	int getLightRadius() const;
};