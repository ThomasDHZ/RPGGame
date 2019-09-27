#include "Panel.h"
#include "Button.h"
#include "Grid.h"
#include "TileButton.h"

Panel::Panel() : GUIObject()
{
	rec = Rect();
	FocusFlag = false;
}

Panel::Panel(Vec2 Pos, Rect Rec, Color PanelColor) : GUIObject(Pos, GUIObjectType::GPanel)
{
	rec = Rec;
	panelColor = PanelColor;
	ObjectSprite = Sprite(rec.GetWidth(), rec.GetHeight());

	for (int x = rec.GetLeft(); x <= rec.GetRight() - 1; x++)
	{
		for (int y = rec.GetTop(); y <= rec.GetBottom() - 1; y++)
		{
			ObjectSprite.PutPixel(x - rec.GetLeft(), y - rec.GetTop(), panelColor);
		}
	}
}

Panel::~Panel()
{
	int a = 34;
}

void Panel::Update(Mouse& mouse)
{
	if (mouse.LeftIsPressed() && 
		rec.PosInRec(mouse.GetPos()))
	{
		FocusFlag = true;
	}

	//for (int x = 0; x <= GUIObjectList.size() -1; x++)
	//{
	//	switch (GUIObjectList[x].get()->GetGUIObjectType())
	//	{
	//		case GUIObjectType::GPanel: static_cast<Panel*>(GUIObjectList[x].get())->Update(mouse); break;
	//		case GUIObjectType::GButton: static_cast<Button*>(GUIObjectList[x].get())->Update(mouse); break;
	//		case GUIObjectType::GTileButton: static_cast<TileButton*>(GUIObjectList[x].get())->Update(mouse); break;
	//		case GUIObjectType::GGrid: static_cast<Grid*>(GUIObjectList[x].get())->Update(mouse); break;
	//	}
	//}
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

	//for (int x = 0; x <= GUIObjectList.size() - 1; x++)
	//{
	//	switch (GUIObjectList[x].get()->GetGUIObjectType())
	//	{
	//	case GUIObjectType::GPanel: static_cast<Panel*>(GUIObjectList[x].get())->Draw(gfx); break;
	//	case GUIObjectType::GButton: static_cast<Button*>(GUIObjectList[x].get())->Draw(gfx); break;
	//	case GUIObjectType::GTileButton: static_cast<TileButton*>(GUIObjectList[x].get())->Draw(gfx); break;
	//	case GUIObjectType::GGrid: static_cast<Grid*>(GUIObjectList[x].get())->Draw(gfx); break;
	//	}
	//}
}

void Panel::AddGUIObject(std::unique_ptr<GUIObject> GuiObj)
{
	//GUIObjectList.emplace_back(std::move(GuiObj));
}

Panel& Panel::operator=(const Panel& rhs)
{
	rec = rhs.rec;
	panelColor = rhs.panelColor;
	FocusFlag = FocusFlag;

	//for (int x = 0; x < rhs.GUIObjectList.size(); x++)
	//{
	//	switch (rhs.GUIObjectList[x].get()->GetGUIObjectType())
	//	{
	//		case GUIObjectType::GPanel: 
	//		{
	//	/*		auto buttonPtr = static_cast<Panel*>(rhs.GUIObjectList[x].get());
	//			auto button = std::make_unique<Panel>(buttonPtr->GetPos());
	//			GUIObjectList.emplace_back(new Panel(buttonPtr->GetPos(), buttonPtr->GetRect(), Color()));*/
	//			break;
	//		}
	//		case GUIObjectType::GButton:
	//		{
	//			auto buttonPtr = static_cast<Button*>(rhs.GUIObjectList[x].get());
	//			auto button = std::make_unique<Button>(buttonPtr->GetPos(), buttonPtr->GetRect());
	//			GUIObjectList.push_back(std::move(button));
	//			break;
	//		}
	//		case GUIObjectType::GTileButton:
	//		{

	//			auto buttonPtr = static_cast<TileButton*>(rhs.GUIObjectList[x].get());
	//			auto button = std::make_unique<TileButton>(buttonPtr->GetTileMap(), buttonPtr->GetTileID(), buttonPtr->GetPos());
	//			GUIObjectList.push_back(std::move(button));
	//			break;
	//		}
	//		case GUIObjectType::GGrid:
	//		{
	//			auto buttonPtr = static_cast<Grid*>(rhs.GUIObjectList[x].get());
	//			auto button = std::make_unique<Grid>(buttonPtr->GetPos(), buttonPtr->GetRect(), buttonPtr->GetRecSize());
	//			GUIObjectList.push_back(std::move(button));
	//			break;
	//		}
	//	}
	//}

	return *this;
}