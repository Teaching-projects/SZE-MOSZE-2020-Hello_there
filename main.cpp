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
#include "HeroSVGRenderer.h"


const std::map<int, std::string> error_messages = {
	{ 1 , "Bad number of arguments. Only a single scenario file should be provided." },
	{ 2 , "The provided scenario file is not accessible." },
};

void bad_exit(int exitcode) {
	std::cerr
		<< (error_messages.count(exitcode) ? error_messages.at(exitcode) : "Unknown error")
		<< std::endl;
	exit(exitcode);
}
int main(int argc, char **argv)
{
	if (argc != 2) bad_exit(1);
	if (!std::filesystem::exists("games/"+(std::string)argv[1])) bad_exit(2);

	PreparedGame g(argv[1]);
	g.registerRenderer(new HeroTextRenderer());
	g.registerRenderer(new HeroTextRenderer("HeroTXT.txt"));
	g.registerRenderer(new ObserverTextRenderer("ObserverTxtOut.txt"));
	g.registerRenderer(new ObserverSVGRenderer("ObserverSvgOut.svg"));
	g.registerRenderer(new HeroSVGRenderer("HeroSvgOut.svg"));
	g.Run();
	return 0;
}
