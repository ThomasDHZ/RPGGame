#include "Grid.h"

Grid::Grid() : GUIObject()
{
}

Grid::Grid(Grid& grid) : GUIObject()
{
	Pos = grid.Pos;
	rec = grid.rec;
	RecSize = grid.RecSize;
}

Grid::Grid(Vec2 Pos, Rect rect, int recSize) : GUIObject(Pos, GGrid)
{
	rec = rect;
	RecSize = recSize;
}

Grid::~Grid()
{
}

void Grid::Update(Mouse& mouse)
{
}

void Grid::Draw(Graphics& gfx)
{
	for (int x = rec.GetLeft(); x <= rec.GetRight() - 1; x++)
	{
		for (int y = rec.GetTop(); y <= rec.GetBottom() - 1; y++)
		{
			if (x % RecSize == 0 ||
				y % RecSize == 0)
			{
				gfx.PutPixel(x, y, Colors::White);
			}
	
		}
	}
}
