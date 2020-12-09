#pragma once
#include "TextRenderer.h"
class HeroTextRenderer : public TextRenderer
{
public:
	/**
	* @brief Retruns a HeroTextRenderer with the default output std::cout.
	* @return HeroTextRenderer
	*/
	HeroTextRenderer();
	/**
	* @brief Retruns a HeroTextRenderer with the given output stream.
	* @param string The name of the output stream
	* @return HeroTextRenderer
	*/
	explicit HeroTextRenderer(const std::string &string);
	/**
	* @brief Renders the map from the Hero's perspective in text format.
	* @param game The Game that provides the map to render.
	* @return void
	*/
	void render(const Game &) const override;
};