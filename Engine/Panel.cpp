#include "Panel.h"
#include "Button.h"

Panel::Panel() : GUIObject()
{
	rec = Rect();
	FocusFlag = false;
}

Panel::Panel(Vec2 Pos, Rect Rec, Color PanelColor) : GUIObject(Pos, GUIObjectType::GPanel)
{
	rec = Rec;
	panelColor = PanelColor;
	GUIObjectList.emplace_back(Button(Vec2(), Rect()));
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

	for (auto GuiObject : GUIObjectList)
	{
		GUIObject* obj = &GuiObject;

		switch (GuiObject.GetGUIObjectType())
		{
			case GUIObjectType::GPanel: static_cast<Panel*>(obj)->Update(mouse); break;
			case GUIObjectType::GButton: static_cast<Button*>(obj)->Update(mouse); break;
		}
	}
}

void Panel::Draw(Graphics& gfx)
{
	for (int x = Pos.GetX() + rec.GetLeft(); x <= Pos.GetX() + rec.GetRight() - 1; x++)
	{
		for (int y = Pos.GetY() + rec.GetTop(); y <= Pos.GetY() + rec.GetBottom() - 1; y++)
		{
			gfx.PutPixel(x, y, panelColor);
		}
	}

	for (auto GuiObject : GUIObjectList)
	{
		GUIObject* obj = &GuiObject;

		switch (GuiObject.GetGUIObjectType())
		{
			case GUIObjectType::GPanel: static_cast<Panel*>(obj)->Draw(gfx); break;
			case GUIObjectType::GButton: static_cast<Button*>(obj)->Draw(gfx); break;
		}
	}
}
