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

int main(int argc, char **argv)
{
    Game g("map_1.txt");
	Hero* h = new Hero("Joe", 500, 10, 12.0, 2, 30, 10, 2, 1.2, 1);
    g.PutHero(h, 1, 1);

    Monster *m1 = new Monster("Cookie Monster", 10, 10, 10.0,5);
    Monster *m2 = new Monster("Octopus Poppus", 10, 10, 10.0,6);
    Monster *m3 = new Monster("Lucky Bucky", 10, 10, 10.0,7);
    g.PutMonster(m1, 1, 2);
    g.PutMonster(m2, 1, 2);
    g.PutMonster(m3, 1, 5);
    g.Run();
    return 0;
}
