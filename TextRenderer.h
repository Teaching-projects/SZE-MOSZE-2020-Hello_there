#pragma once
#include "Renderer.h"
#include <sstream>
class TextRenderer : public Renderer {

protected:
	friend std::ofstream;
	std::ofstream* outputStream;
	

public:
	~TextRenderer();
	TextRenderer();
	TextRenderer(std::string);
	void setOutputStream(std::string);

};