#include "ObserverSVGRenderer.h"

ObserverSVGRenderer::ObserverSVGRenderer(std::string s): SVGRenderer(s)
{
}
void ObserverSVGRenderer::render(const Game& g) const
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
	// print middle part
	for (int i = 0; i < rowCount; i++)
	{
		colCount = m->GetColCount(i);

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
		//new line
	}
}