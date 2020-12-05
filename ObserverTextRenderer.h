#pragma once
#include "TextRenderer.h"
class ObserverTextRenderer :public TextRenderer {
public:
	ObserverTextRenderer();
	ObserverTextRenderer(std::string);
	void render(const Game&) const override;
};