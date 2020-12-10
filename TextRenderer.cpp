#include "TextRenderer.h"

TextRenderer::~TextRenderer()
{
	delete outputStream;
}

TextRenderer::TextRenderer(): Renderer(){
	outputStream = new std::ofstream;
	outputStream->basic_ios<char>::rdbuf(std::cout.rdbuf());
}

TextRenderer::TextRenderer(std::string s)
{
	outputStream = new std::ofstream;
	outputStream->open(s);

}

void TextRenderer::setOutputStream(std::string s)
{
	if (outputStream->is_open())
		outputStream->close();
	outputStream->open(s);
}