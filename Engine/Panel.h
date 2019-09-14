#pragma once
#include "Vec2.h"
#include "Rect.h"
#include "Mouse.h"
class Panel
{
private:
	Vec2 pos;
	Rect rec;
	Color panelColor;
	bool FocusFlag;
public:
	Panel();
	Panel(Vec2 Pos, Rect Rec, Color PanelColor);
	~Panel();

	void Update(Mouse& mouse);
	void Draw(Graphics& gfx);
};

