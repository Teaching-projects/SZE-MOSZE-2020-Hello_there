#include "SVGRenderer.h"


SVGRenderer::SVGRenderer(std::string s) : Renderer()
{
	outputStream = new std::ofstream;
	outputStream->open(s);
}

void SVGRenderer::setOutputStream(std::string s)
{
	outputStream->open(s);
}