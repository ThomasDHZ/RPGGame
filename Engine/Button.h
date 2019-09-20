#pragma once
#include "GUIObject.h"
#include "Mouse.h"
#include "Tile.h"
#include "Rect.h"
class Button : public GUIObject
{
private:
	Rect rec;
	Color borderColor;
	bool debugBorder;

public:
	Button();
	Button(Button& button);
	Button(Vec2 Pos, Rect rect, bool DebugBorder = true);
	Button(Vec2 Pos, Rect rect, GUIObjectType type, bool DebugBorder = true);
	virtual ~Button();

	virtual void Update(Mouse& mouse);
	virtual void Draw(Graphics& gfx);
	virtual bool ButtonPressed(Mouse& mouse);

	Rect GetRect() { return rec; }

	Button operator&();
};

