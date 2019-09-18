#pragma once
#include "GUIObject.h"
#include "Rect.h"
#include "Mouse.h"
#include <memory>

class Panel : GUIObject
{
private:
	Rect rec;
	Color panelColor;
	bool FocusFlag;

	std::vector<std::unique_ptr<GUIObject>> GUIObjectList;

public:
	Panel();
	Panel(Vec2 Pos, Rect Rec, Color PanelColor);
	virtual ~Panel();

	virtual void Update(Mouse& mouse);
	virtual void Draw(Graphics& gfx);

	Panel& operator=(const Panel& rhs);
};

