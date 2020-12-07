#pragma once
#include "SVGRenderer.h"
class HeroSVGRenderer :public SVGRenderer {
public:
	HeroSVGRenderer(std::string);
	void render(const Game&) const override;
};
