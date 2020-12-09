#pragma once
#include "TextRenderer.h"
class HeroTextRenderer :public TextRenderer {
public:
	HeroTextRenderer();
	HeroTextRenderer(const std::string&);
	void render(const Game&) const override;
};