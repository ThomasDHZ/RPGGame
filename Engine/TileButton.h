#pragma once
#include "Button.h"
#include "TileMap.h"
class TileButton : public Button
{
private:
	TileMap tileMap;
	unsigned int tileID;
public:
	TileButton();
	TileButton(TileMap map, unsigned int TileID,  Vec2 Pos);
	~TileButton();

	void Update(Mouse& mouse);
	void Draw(Graphics& gfx);
};

