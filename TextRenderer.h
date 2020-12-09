#pragma once
#include "Renderer.h"
#include <sstream>
class TextRenderer : public Renderer
{

protected:
	friend std::ofstream;
	std::ofstream *outputStream;

public:
	~TextRenderer();
	TextRenderer();
	explicit TextRenderer(std::string);
	TextRenderer(const TextRenderer &) = delete;
	TextRenderer &operator=(const TextRenderer &) = delete;
	void setOutputStream(std::string);
};
