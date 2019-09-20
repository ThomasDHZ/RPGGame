#include "Button.h"

Button::Button() : GUIObject()
{
}

Button::Button(Button& button)
{
	rec = button.rec;
	borderColor = button.borderColor;
	debugBorder = button.debugBorder;
}

Button::Button(Vec2 Pos, Rect rect, bool DebugBorder) : GUIObject(Pos, GUIObjectType::GButton)
{
	rec = rect;
	debugBorder = DebugBorder;
	borderColor = Colors::White;
}

Button::Button(Vec2 Pos, Rect rect, GUIObjectType type, bool DebugBorder) : GUIObject(Pos, type)
{
	rec = rect;
	debugBorder = DebugBorder;
	borderColor = Colors::White;
}

Button::~Button()
{
}

void Button::Update(Mouse& mouse)
{
	if (rec.PosInRec(mouse.GetPos()))
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

bool Button::ButtonPressed(Mouse& mouse)
{
	if (mouse.LeftIsPressed() &&
		rec.PosInRec(mouse.GetPos()))
	{
		return true;
	}
	return false;
}

Button Button::operator&()
{
	return Button();
}
