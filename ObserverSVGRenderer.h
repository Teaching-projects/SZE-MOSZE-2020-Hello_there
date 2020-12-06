#pragma once
#include "SVGRenderer.h"
class ObserverSVGRenderer : public SVGRenderer {
public:
	ObserverSVGRenderer(std::string);
	void render(const Game&) const override;
};
