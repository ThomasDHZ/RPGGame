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
	GUIObjectList.emplace_back(std::make_unique<Button>(Vec2(245,245), Rect(200, 260, 200, 460)));
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

	for (int x = 0; x <= GUIObjectList.size() -1; x++)
	{
		switch (GUIObjectList[x].get()->GetGUIObjectType())
		{
			case GUIObjectType::GPanel: static_cast<Panel*>(GUIObjectList[x].get())->Update(mouse); break;
			case GUIObjectType::GButton: static_cast<Button*>(GUIObjectList[x].get())->Update(mouse); break;
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

	for (int x = 0; x <= GUIObjectList.size() - 1; x++)
	{
		switch (GUIObjectList[x].get()->GetGUIObjectType())
		{
		case GUIObjectType::GPanel: static_cast<Panel*>(GUIObjectList[x].get())->Draw(gfx); break;
		case GUIObjectType::GButton: static_cast<Button*>(GUIObjectList[x].get())->Draw(gfx); break;
		}
	}
}

Panel& Panel::operator=(const Panel& rhs)
{
	rec = rhs.rec;
	panelColor = rhs.panelColor;
	FocusFlag = FocusFlag;

	for (int x = 0; x <= rhs.GUIObjectList.size() - 1; x++)
	{
		switch (rhs.GUIObjectList[x].get()->GetGUIObjectType())
		{
			//case GUIObjectType::GPanel: auto panel = static_cast<Panel*>(GUIObjectList[x].get()); break;
			case GUIObjectType::GButton:
			{
				auto button = static_cast<Button*>(rhs.GUIObjectList[x].get());
				auto b = std::make_unique<Button>(button->GetPos(), button->GetRect());
				GUIObjectList.push_back(std::move(b));
				break;
			}
		}
	}

	return *this;
}