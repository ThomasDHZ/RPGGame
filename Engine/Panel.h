#pragma once
#include "GUIObject.h"
#include "Rect.h"
#include "Mouse.h"
#include <memory>

class Panel : public GUIObject
{
private:
	Rect rec;
	Color panelColor;
	bool FocusFlag;

	//std::vector<std::unique_ptr<GUIObject>> GUIObjectList;
	//std::vector<std::unique_ptr<Panel>> panel;

public:
	Panel();
	Panel(Vec2 Pos, Rect Rec, Color PanelColor);
	virtual ~Panel();

	virtual void Update(Mouse& mouse);
	virtual void Draw(Graphics& gfx);

	void AddGUIObject(std::unique_ptr<GUIObject> GuiObj);

	Panel& operator=(const Panel& rhs);

	Rect GetRect() { return rec; }
};

