#pragma once
#include "Game.h"
class Game;
class Renderer {
public:
	virtual void render(const Game&) const=0;
};