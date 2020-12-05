#include "HeroTextRenderer.h"

HeroTextRenderer::HeroTextRenderer() :TextRenderer()
{
}

HeroTextRenderer::HeroTextRenderer(std::string s) : TextRenderer(s)
{

}

void HeroTextRenderer::render(const Game& g) const
{
	Map* m = g.getMap();
	Hero* h = g.getHero();
	int rowCount = m->GetRowCount();
	int colCount;

	std::vector<std::vector<char>> tiles(rowCount);

	for (int i = 0; i < rowCount; i++)
	{
		colCount = m->GetColCount(i);
		tiles[i] = std::vector<char>(colCount);

		for (int j = 0; j < colCount; j++)
		{
			if (m->get(i, j) == Map::Wall)
				tiles[i][j] = (char)(219);
			else
				tiles[i][j] = (char)(177);
		}
	}

	std::vector<std::pair<int, int>> monsterCoordinates = g.GetMonsterCoordinates();

	// place hero
	int x = h->GetXCoo();
	int y = h->GetYCoo();
	tiles[x][y] = 'H';
	int maxSteps = h->getLightRadius() * 2 + 1;
	if (maxSteps >= colCount) maxSteps = colCount;
	int startRow = x;
	int startCol = y;
	for (int i = 0; i < h->getLightRadius() && startRow > 0 && startRow < rowCount; i++) {
		startRow--;
	}
	for (int i = 0; i < h->getLightRadius() && startCol > 0 && startCol < colCount; i++) {
		startCol--;
	}
	int magic = (colCount - startCol);

	// print top border of map
	std::cout << char(201);
	for (int i = 0; i < maxSteps && i < magic; i++)
		std::cout << char(205) << char(205);
	std::cout << char(187) << std::endl;
	// print middle part
	for (int i = 0, row = startRow; i < maxSteps && row < rowCount; i++)
	{
		std::cout << char(186);
		for (int j = 0, col = startCol; j < maxSteps && col < colCount; j++)
		{
			char tile = tiles[row][col];

			int tileMonsterCount = 0;
			for (int k = 0; k < g.getMonsterCount(); k++)
			{
				if (monsterCoordinates[k].first == row && monsterCoordinates[k].second == col)
					tileMonsterCount++;
			}

			if (tileMonsterCount > 1)
				std::cout << 'M' << 'M';
			else if (tileMonsterCount == 1)
				std::cout << 'M' << ' ';
			else if (tile == 'H')
				std::cout << tile << ' ';
			else
				std::cout << tile << tile;
			col++;
		}
		std::cout << char(186) << std::endl;
		row++;
	}

	// print bottom part of the map
	std::cout << char(200);
	for (int i = 0; i < maxSteps && i < magic; i++)
		std::cout << char(205) << char(205);
	std::cout << char(188) << std::endl;
}
