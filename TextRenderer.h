#pragma once
#include "Renderer.h"
#include <sstream>
class TextRenderer : public Renderer {

private:
	friend std::ostream;
	std::ostream* outputStream;
	

public:
	//~TextRenderer();
	//virtual void render(const Game&) const = 0;
	TextRenderer();
	TextRenderer(std::ofstream*);
	void setOutputStream(std::ofstream*);
	

};