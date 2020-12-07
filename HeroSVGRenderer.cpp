#include "HeroSVGRenderer.h"

HeroSVGRenderer::HeroSVGRenderer(std::string s) : SVGRenderer(s)
{
}

void HeroSVGRenderer::render(const Game &g) const
{
	Map *m = g.getMap();
	Hero *h = g.getHero();
	int rowCount = m->GetRowCount();
	int colCount = m->GetColCount(0);
	std::vector<std::pair<int, int>> monsterCoordinates = g.GetMonsterCoordinates();
	// place hero
	int x = h->GetXCoo();
	int y = h->GetYCoo();
	int maxSteps = h->getLightRadius() * 2 + 1;
	if (maxSteps >= colCount)
		maxSteps = colCount;
	int startRow = x;
	int startCol = y;
	for (int i = 0; i < h->getLightRadius() && startRow > 0 && startRow < rowCount; i++)
	{
		startRow--;
	}
	for (int i = 0; i < h->getLightRadius() && startCol > 0 && startCol < colCount; i++)
	{
		startCol--;
	}
	int width = (colCount - startCol) * 10;
	int height = (rowCount - startRow) * 10;
	std::ofstream stream(outputStreamName);
	stream << "<svg viewBox=\"0 0 " << width << ' ' << height << "\" xmlns=\"http://www.w3.org/2000/svg\" width=\"" << width << "\" height=\"" << height << "\">\n";
	for (int x = 0, row = startRow; x < maxSteps && row < rowCount; x++)
	{
		for (int y = 0, col = startCol; y < maxSteps && col < colCount; y++)
		{

			const int topx = x * 10;
			const int topy = y * 10;

			std::string img = "";
			// print middle part
			int tileMonsterCount = 0;
			for (int k = 0; k < g.getMonsterCount(); k++)
			{
				if (monsterCoordinates[k].first == row && monsterCoordinates[k].second == col)
					tileMonsterCount++;
			}
			if (h != nullptr && h->isAlive() && h->GetXCoo() == row && h->GetYCoo() == col)
			{
				img = h->GetTexture();
			}
			else if (tileMonsterCount != 0)
			{
				img = g.getMonsterTextureInField(row, col);
			}
			else
			{
				img = m->get(row, col) == Map::Wall ? g.getWallTexture()
													: g.getFreeTexture();
			}

			if (img != "")
			{
				stream << "<image x=\"" << topy << "\" y=\"" << topx << "\" width=\"10\" height=\"10\" href=\""
					   << img
					   << "\" />\n";
			}
			else
			{
				stream << "<rect fill=\"black\" x=\"" << topy << "\" y=\"" << topx << "\" width=\"10\" height=\"10\" />\n";
			}
			stream << std::flush;
			col++;
		}
		row++;
	}

	stream << "</svg>";
	stream.close();
	//new line
}
