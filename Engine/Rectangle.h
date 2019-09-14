#pragma once
#include "Graphics.h"
#include "Vec2.h"
class Rect
{
private:
	int left;
	int right;
	int top;
	int bottom;
public:
	Rect();
	Rect(int Left, int Right, int Top, int Bottom);
	~Rect();

	void Draw( Graphics& gfx, Color color);
	bool PosInRec(Vec2 pos);
};

