#include "Button.h"

Button::Button()
{
}

Button::Button(Vec2 Pos)
{
	pos = Pos;
	rec = Rect(Pos.GetX(), Pos.GetX() + 16, Pos.GetY(), Pos.GetY() + 16);
	borderColor = Colors::White;
}

Button::~Button()
{
}

void Button::Update(Mouse& mouse)
{
	if (mouse.LeftIsPressed() &&
		rec.PosInRec(mouse.GetPos()))
	{
		int a = 334;
	}
	else if (rec.PosInRec(mouse.GetPos()))
	{
		borderColor = Colors::Red;
	}
	else
	{
		borderColor = Colors::White;
	}
}

void Button::Draw(Graphics& gfx)
{
	rec.Draw(gfx, borderColor);
}
