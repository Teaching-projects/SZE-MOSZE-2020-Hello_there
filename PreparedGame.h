#include "Game.h"
#include <string>

class PreparedGame : private Game
{
private:
public:
    PreparedGame(std::string prepdGamePath);
    void Run() override;
};