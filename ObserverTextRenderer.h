#pragma once
#include "TextRenderer.h"
class ObserverTextRenderer : public TextRenderer
{
public:
	ObserverTextRenderer();
	explicit ObserverTextRenderer(const std::string &s);
	void render(const Game &) const override;
};