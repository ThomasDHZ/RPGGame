#include "Panel.h"

Panel::Panel()
{ 
	pos = Vec2();
	rec = Rect();
	FocusFlag = false;
}

Panel::Panel(Vec2 Pos, Rect Rec, Color PanelColor)
{
	pos = Pos;
	rec = Rec;
	panelColor = PanelColor;
}

Panel::~Panel()
{
}

void Panel::Update(Mouse& mouse)
{
	if (mouse.LeftIsPressed() && 
		rec.PosInRec(mouse.GetPos()))
	{
		FocusFlag = true;
	}
}

void Panel::Draw(Graphics& gfx)
{
	for (int x = pos.GetX() + rec.GetLeft(); x <= pos.GetX() + rec.GetRight() - 1; x++)
	{
		for (int y = pos.GetY() + rec.GetTop(); y <= pos.GetY() + rec.GetBottom() - 1; y++)
		{
			gfx.PutPixel(x, y, panelColor);
		}
	}
}
