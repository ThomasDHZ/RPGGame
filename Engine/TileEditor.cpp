#include "TileEditor.h"

TileEditor::TileEditor()
{
}

TileEditor::TileEditor(TileMap tileMap)
{
	panel = Panel(Vec2(400, 400), Rect(100, 140, 100, 140), Colors::Blue);
	CurrentTileMap = tileMap;
	int counter = 0;
	for (int x = 0; x <= 50; x++)
	{
		for (int y = 0; y <= 2; y++)
		{
			if (counter <= CurrentTileMap.GetTileCount() - 1)
			{
				const int constX = x * TileMap::TileSize;
				const int constY = y * TileMap::TileSize;

				ButtonList.emplace_back(TileButton(CurrentTileMap, counter, Vec2(constX, constY)));
			}
			counter++;
		}
	}
	SelectedButton = TileButton(CurrentTileMap, 0, Vec2(300, 300));
}

TileEditor::~TileEditor()
{

}

void TileEditor::Update(Mouse& mouse)
{
	panel.Update(mouse);
	for (auto button : ButtonList)
	{
		button.Update(mouse);
		
		if (button.ButtonPressed(mouse))
		{
			 SelectedButton.SetTileID(button.GetTileID());
		}
	}
}

void TileEditor::Draw(Graphics& gfx)
{
	panel.Draw(gfx);
	for (auto button : ButtonList)
	{
		button.Draw(gfx);
	}

	SelectedButton.Draw(gfx);
}
