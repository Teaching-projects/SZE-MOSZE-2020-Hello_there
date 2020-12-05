#pragma once
#include "TextRenderer.h"
class ObserverTextRenderer :public TextRenderer {
public:
	ObserverTextRenderer();
	ObserverTextRenderer(std::ofstream* ofs);
	void render(const Game&) const override;
};