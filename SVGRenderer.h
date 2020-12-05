#pragma once

#include "Renderer.h"
#include <sstream>
class SVGRenderer : public Renderer {

private:
	friend std::ostream;
	std::ostream* outputStream;


public:
	SVGRenderer();
	SVGRenderer(std::ofstream*);
	void setOutputStream(std::ofstream*);


};
