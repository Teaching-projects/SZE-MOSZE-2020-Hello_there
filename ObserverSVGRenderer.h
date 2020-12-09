#pragma once
#include "SVGRenderer.h"
class ObserverSVGRenderer : public SVGRenderer
{
public:
	/**
	* @brief Returns a ObserverSVGRenderer.
	* @param s The name of the target file to save the render.
	* @return ObserverSVGRenderer
	*/
	explicit ObserverSVGRenderer(const std::string &);
	/**
	* @brief Renders the whole map in SVG format.
	* @param game The Game that provides the map to render.
	* @return void
	*/
	void render(const Game &) const override;
};
