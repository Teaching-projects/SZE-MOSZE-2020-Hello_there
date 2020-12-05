#include "TextRenderer.h"


TextRenderer::TextRenderer(): Renderer(), outputStream(&std::cout){
}

TextRenderer::TextRenderer(std::ofstream *ofs): Renderer(), outputStream(ofs)
{
}

void TextRenderer::setOutputStream(std::ofstream *ost)
{
	outputStream = ost;
}