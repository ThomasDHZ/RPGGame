#pragma once
#include "GUIObject.h"
#include "Rect.h"
#include "Mouse.h"
class Panel : GUIObject
{
private:
	Rect rec;
	Color panelColor;
	bool FocusFlag;

	std::vector<GUIObject> GUIObjectList;

public:
	Panel();
	Panel(Vec2 Pos, Rect Rec, Color PanelColor);
	virtual ~Panel();

	virtual void Update(Mouse& mouse);
	virtual void Draw(Graphics& gfx);
};

