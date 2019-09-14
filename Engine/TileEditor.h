#pragma once
#include "Graphics.h"
#include "TileMap.h"
#include "Button.h"
#include "TileButton.h"

class TileEditor
{
private:
	TileMap CurrentTileMap;
	std::vector<TileButton> ButtonList;
public:
	TileEditor();
	TileEditor(TileMap tileMap);
	~TileEditor();

	void Update(Mouse& mouse);
	void Draw(Graphics& gfx);
};

