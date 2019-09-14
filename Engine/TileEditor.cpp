#include "TileEditor.h"

TileEditor::TileEditor()
{
}

TileEditor::TileEditor(TileMap tileMap)
{
	CurrentTileMap = tileMap;
	int counter = 0;
	for (int x = 0; x <= 50; x++)
	{
		for (int y = 0; y <= 2; y++)
		{
			if (counter <= CurrentTileMap.GetTileCount() - 1)
			{
				ButtonList.emplace_back(TileButton(CurrentTileMap, counter, Vec2(x * 16, y * 16)));
			}
			counter++;
		}
	}
}

TileEditor::~TileEditor()
{

}

void TileEditor::Update(Mouse& mouse)
{
	for (auto button : ButtonList)
	{
		button.Update(mouse);
	}
}

void TileEditor::Draw(Graphics& gfx)
{
	for (auto button : ButtonList)
	{
		button.Draw(gfx);
	}
}
