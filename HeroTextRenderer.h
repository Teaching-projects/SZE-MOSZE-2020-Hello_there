#pragma once
#include "TextRenderer.h"
class HeroTextRenderer :public TextRenderer {
public:
	HeroTextRenderer();
	HeroTextRenderer(std::string);
	void render(const Game&) const override;
};