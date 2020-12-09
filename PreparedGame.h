#include "Game.h"
#include <string>

class PreparedGame : private Game
{
private:
public:
    explicit PreparedGame(const std::string &);
    using Game::registerRenderer;
    using Game::Run;
};