#pragma once

#include "Renderer.h"
#include <sstream>
class SVGRenderer : public Renderer {

protected:
	friend std::ofstream;
	std::ofstream* outputStream;


public:
	~SVGRenderer();
	SVGRenderer();
	SVGRenderer(std::string);
	SVGRenderer(const SVGRenderer&) = delete;
	SVGRenderer& operator=(const SVGRenderer&) = delete;
	void setOutputStream(std::string);
	


};
