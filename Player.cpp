#include "Player.h"

Player::Player(std::string name,int hp,int dmg) 
	: Unit(name, hp, dmg ), xp(0),lvl(1),maxHP(hp)
{
}
Player::Player(Unit u)
	: Unit(u.GetName(), u.GetHp(), u.GetDmg()), xp(0), lvl(1),maxHP(u.GetHp())
{
}

std::string Player::ToString()
{
	return Unit::ToString() + "LVL:" + std::to_string(lvl)+" XP:" + std::to_string(xp);
}

void Player::LvlUp()
{
	if (xp >= 100) {
		maxHP *= 1.1;
		hp = maxHP;
		dmg *= 1.1;
		lvl++;
		xp -= 100;
		std::cout << "Level up to level: " << lvl << std::endl;
		//std::cout<<this->ToString()<<std::endl<<std::endl<< std::endl;
		LvlUp();
		
	}
}
void Player::addXp(int number) {
	xp += number;
}