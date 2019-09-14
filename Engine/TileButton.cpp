#include "TileButton.h"

TileButton::TileButton() : Button()
{
}

TileButton::TileButton(TileMap map, unsigned int TileID, Vec2 Pos) : Button(Pos)
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
	Vec2 poz = Vec2(pos.GetX() / TileMap::TileSize, pos.GetY() / TileMap::TileSize);
	tileMap.Draw(gfx, poz, tileID);

	Button::Draw(gfx);
}