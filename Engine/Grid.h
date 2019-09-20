#pragma once
#include "GUIObject.h"
#include "Rect.h"
class Grid : public GUIObject
{
private:
	Rect rec;
	int RecSize;
public:
	Grid();
	Grid(Grid& grid);
	Grid(Vec2 Pos, Rect rect, int recSize);
    ~Grid();

	void Update(Mouse& mouse);
	void Draw(Graphics& gfx);

	Rect GetRect() { return rec; }
	int GetRecSize() { return RecSize; }
};

