#pragma once

#include "Renderer.h"
#include <sstream>
class SVGRenderer : public Renderer {

protected:
	friend std::ofstream;
	std::string outputStreamName;


public:
	SVGRenderer(std::string);
	SVGRenderer(const SVGRenderer&) = delete;
	SVGRenderer& operator=(const SVGRenderer&) = delete;
	void setOutputStream(std::string);
	


};
