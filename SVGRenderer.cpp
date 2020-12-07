#include "SVGRenderer.h"

SVGRenderer::SVGRenderer(std::string s) : Renderer()
{
	outputStreamName = s;
}

void SVGRenderer::setOutputStream(std::string s)
{
	outputStreamName = s;
}