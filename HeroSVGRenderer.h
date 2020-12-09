/**
 * \author BakiHUN
 * \brief Hero class
 *
 * The HeroSVGRenderer is responsible for rendering the map from the hero's perspective in SVG format.
 *
 * \date 2020-12-09
 */
#pragma once
#include "SVGRenderer.h"
class HeroSVGRenderer : public SVGRenderer
{
public:
	/**
	* @brief Returns a HeroSVGRenderer.
	* @param s The name of the target file to save the render.
	* @return HeroSVGRenderer
	*/
	explicit HeroSVGRenderer(const std::string &string);
	/**
	* @brief Renders the map from the Hero's perspective in SVG format.
	* @param game The Game that provides the map to render.
	* @return void
	*/
	void render(const Game &game) const override;
};
