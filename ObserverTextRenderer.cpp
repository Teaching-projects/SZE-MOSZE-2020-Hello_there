#include "ObserverTextRenderer.h"
ObserverTextRenderer::ObserverTextRenderer() :TextRenderer()
{
}

ObserverTextRenderer::ObserverTextRenderer(std::string s): TextRenderer(s)
{
}

void ObserverTextRenderer::render(const Game& g) const
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
			if (g.getMap()->get(i, j) == Map::Wall)
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
	// print top border of map
	colCount = m->GetColCount(0);
	(*outputStream) << char(201);
	for (int i = 0; i < colCount; i++)
		(*outputStream) << char(205) << char(205);
	(*outputStream) << char(187) << std::endl;

	// print middle part
	for (int i = 0; i < rowCount; i++)
	{
		colCount = m->GetColCount(i);
		(*outputStream) << char(186);
		for (int j = 0; j < colCount; j++)
		{
			char tile = tiles[i][j];

			int tileMonsterCount = 0;
			for (int k = 0; k < g.getMonsterCount(); k++)
			{
				if (monsterCoordinates[k].first == i && monsterCoordinates[k].second == j)
					tileMonsterCount++;
			}

			if (tileMonsterCount > 1)
				(*outputStream) << 'M' << 'M';
			else if (tileMonsterCount == 1)
				(*outputStream) << 'M' << ' ';
			else if (tile == 'H')
				(*outputStream) << tile << ' ';
			else
				(*outputStream) << tile << tile;
		}
		(*outputStream) << char(186) << std::endl;
	}

	// print bottom part of the map
	colCount = m->GetColCount(rowCount - 1);
	(*outputStream) << char(200);
	for (int i = 0; i < colCount; i++)
		(*outputStream) << char(205) << char(205);
	(*outputStream) << char(188) << std::endl;
}
