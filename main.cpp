#include <iostream>
#include <map>
#include <string>
#include <filesystem>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <list>

#include "JSON.h"
#include "Hero.h"
#include "Monster.h"
#include "Game.h"
#include "MarkedMap.h"
#include "PreparedGame.h"
#include "ObserverTextRenderer.h"
#include "HeroTextRenderer.h"
#include "ObserverSVGRenderer.h"

int main(int argc, char **argv)
{

	/*MarkedMap *m = new MarkedMap("marked_map.txt");
	Game g(m);
	Hero *h = Hero::parse(std::string("Dark_Wanderer.json"));
	g.PutHero(h, 1, 1);

	Monster *m1 = new Monster("Cookie Monster", 10, 10, 10.0, 5);
	Monster *m2 = new Monster("Octopus Poppus", 10, 10, 10.0, 6);
	Monster *m3 = new Monster("Lucky Bucky", 10, 10, 10.0, 7);
	g.PutMonster(m1, 1, 2);
	g.PutMonster(m2, 1, 2);
	g.PutMonster(m3, 1, 5);

	g.Run();*/

	PreparedGame g("prepd_game_1.json");
	g.registerRenderer(new HeroTextRenderer());
	g.registerRenderer(new ObserverTextRenderer("Game.txt"));
	g.registerRenderer(new ObserverSVGRenderer("valami.svg"));
	g.Run();
	return 0;
}
