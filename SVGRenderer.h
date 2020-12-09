#pragma once

#include "Renderer.h"
#include <sstream>
class SVGRenderer : public Renderer
{

protected:
	friend std::ofstream;
	std::string outputStreamName;

public:
	explicit SVGRenderer(const std::string &);
	SVGRenderer(const SVGRenderer &) = delete;
	SVGRenderer &operator=(const SVGRenderer &) = delete;
	void setOutputStream(const std::string &);
};
