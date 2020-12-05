#include "SVGRenderer.h"

SVGRenderer::SVGRenderer() : Renderer(), outputStream(&std::cout) {
}

SVGRenderer::SVGRenderer(std::ofstream* ofs) : Renderer(), outputStream(ofs)
{
}

void SVGRenderer::setOutputStream(std::ofstream* ost)
{
	outputStream = ost;
}