#pragma once
#include "TextRenderer.h"
#include "Game.h"
class ObserverTextRenderer :public TextRenderer {
public:
	ObserverTextRenderer();
	ObserverTextRenderer(std::ofstream* ofs);
	void render(const Game&) const override;
	void test() { std::cout << "asd"; }
};