#pragma once
#include "TextRenderer.h"
class ObserverTextRenderer : public TextRenderer
{
public:
	/**
	* @brief Returns a ObserverTextRenderer.
	* @return ObserverTextRenderer
	*/
	ObserverTextRenderer();
	/**
	* @brief Returns a ObserverTextRenderer.
	* @param s The name of the target file to save the render.
	* @return ObserverTextRenderer
	*/
	explicit ObserverTextRenderer(const std::string &s);
	/**
	* @brief Renders the whole map in text format.
	* @param game The Game that provides the map to render.
	* @return void
	*/
	void render(const Game &) const override;
};