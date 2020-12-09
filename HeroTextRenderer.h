#pragma once
#include "TextRenderer.h"
class HeroTextRenderer : public TextRenderer
{
public:
	HeroTextRenderer();
	explicit HeroTextRenderer(const std::string &);
	void render(const Game &) const override;
};