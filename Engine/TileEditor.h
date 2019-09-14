#pragma once
#include "Graphics.h"
#include "TileMap.h"
#include "Button.h"
#include "TileButton.h"
#include "Panel.h"

class TileEditor
{
private:
	Panel panel;
	TileMap CurrentTileMap;
	std::vector<TileButton> ButtonList;
	TileButton SelectedButton;
public:
	TileEditor();
	TileEditor(TileMap tileMap);
	~TileEditor();

	void Update(Mouse& mouse);
	void Draw(Graphics& gfx);
};

