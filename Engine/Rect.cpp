#include "Rect.h"

Rect::Rect()
{
}

Rect::Rect(int Left, int Right, int Top, int Bottom)
{
	left = Left;
	right = Right;
	top = Top;
	bottom = Bottom;
}

Rect::~Rect()
{
}

void Rect::Draw(Graphics& gfx, Color color)
{
	for (int x = left; x <= right - 1; x++)
	{
		for (int y = top; y <= bottom - 1; y++)
		{
			if (x == left ||
				x == right - 1 ||
				y == top ||
				y == bottom - 1)
			{
				gfx.PutPixel(x, y, color);
			}
		}
	}
}

bool Rect::PosInRec(Vec2 pos)
{
	if (pos.GetX() >= left &&
		pos.GetX() <= right &&
		pos.GetY() >= top &&
		pos.GetY() <= bottom)
	{
		return true;
	}
	return false;
}
