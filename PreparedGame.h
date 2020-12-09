#include "Game.h"
#include <string>

class PreparedGame : private Game
{
private:
public:
    PreparedGame(const std::string&);
    using Game::Run;
	using Game::registerRenderer;
};