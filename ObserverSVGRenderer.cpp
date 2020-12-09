#include "ObserverSVGRenderer.h"

ObserverSVGRenderer::ObserverSVGRenderer(const std::string& s): SVGRenderer(s)
{
}
void ObserverSVGRenderer::render(const Game& g) const
{
	Map* m = g.getMap();
	Hero* h = g.getHero();
	int height = m->GetRowCount() * 10;
	int width = m->GetColCount(0) * 10;
	int rowCount = m->GetRowCount();
	int colCount = m->GetColCount(0);
	std::vector<std::pair<int, int>> monsterCoordinates = g.GetMonsterCoordinates();
	std::ofstream stream(outputStreamName);
	stream << "<svg viewBox=\"0 0 " << width << ' ' << height << "\" xmlns=\"http://www.w3.org/2000/svg\" width=\"" << width << "\" height=\"" << height << "\">\n";
	for (int x = 0; x < rowCount; x++)
	{
		for (int y = 0; y < colCount; y++)
		{
			
			const int topx = x * 10;
			const int topy = y * 10;

			std::string img = "";
			// print middle part
			int tileMonsterCount = 0;
			for (int k = 0; k < g.getMonsterCount(); k++)
			{
				if (monsterCoordinates[k].first == x && monsterCoordinates[k].second == y)
					tileMonsterCount++;
			}
			if (h != nullptr && h->isAlive() && h->GetXCoo() == x && h->GetYCoo() == y)
			{
				img = h->GetTexture();
			}
			else if (tileMonsterCount != 0)
			{
				img = g.getMonsterTextureInField(x, y);
			}
			else
			{
				img = m->get(x, y) == Map::Wall ? g.getWallTexture()
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
		}
	}

	stream << "</svg>";
	stream.close();
	//new line
}