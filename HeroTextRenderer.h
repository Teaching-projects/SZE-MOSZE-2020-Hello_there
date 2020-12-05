#pragma once
#include "TextRenderer.h"
class HeroTextRenderer :public TextRenderer {
public:
	HeroTextRenderer();
	HeroTextRenderer(std::ofstream* ofs);
	void render(const Game&) const override;
};