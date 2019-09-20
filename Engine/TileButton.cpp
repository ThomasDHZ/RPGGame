#include "TileButton.h"

TileButton::TileButton() : Button()
{
}

TileButton::TileButton(TileButton& tileButton)
{
	Pos = tileButton.Pos;
	tileMap = tileButton.tileMap;
	tileID = tileButton.tileID;
}

TileButton::TileButton(TileMap map, unsigned int TileID, Vec2 Pos, bool DebugBorder) : Button(Pos, Rect(Pos.GetX(), Pos.GetX() + TileMap::TileSize, Pos.GetY(), Pos.GetY() + TileMap::TileSize), GUIObjectType::GTileButton, DebugBorder)
{
	tileMap = map;
	tileID = TileID;
}

TileButton::~TileButton()
{
}

void TileButton::Update(Mouse& mouse)
{
	Button::Update(mouse);
}

void TileButton::Draw(Graphics& gfx)
{
	const Vec2 pos = Vec2(Pos.GetX() / TileMap::TileSize, Pos.GetY() / TileMap::TileSize);
	tileMap.Draw(gfx, pos, tileID);

	Button::Draw(gfx);
}

void TileButton::SetTileID(unsigned int ID)
{
	tileID = ID;
}

