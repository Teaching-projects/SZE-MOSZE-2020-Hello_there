#include "SVGRenderer.h"

SVGRenderer::SVGRenderer(const std::string& s) : Renderer(), outputStreamName(s)
{
}

void SVGRenderer::setOutputStream(const std::string& s)
{
	outputStreamName = s;
}