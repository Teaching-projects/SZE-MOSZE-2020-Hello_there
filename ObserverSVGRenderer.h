#pragma once
#include "SVGRenderer.h"
class ObserverSVGRenderer : public SVGRenderer {
public:
	ObserverSVGRenderer(const std::string&);
	void render(const Game&) const override;
};
