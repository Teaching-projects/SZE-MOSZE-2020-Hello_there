#include "Game.h"
#include <string>

class PreparedGame : private Game
{
private:
public:
	/**
	* @brief Returns a PreparedGame.
	* @param s The name of the file that contains the Game.
	* @return PreparedGame
	*/
    explicit PreparedGame(const std::string &s);
    using Game::registerRenderer;
    using Game::Run;
};