#include "TileEditor.h"
#include "Grid.h"

TileEditor::TileEditor()
{
}

TileEditor::TileEditor(TileMap tileMap)
{
	panel = Panel(Vec2(400, 400), Rect(100, 140, 100, 140), Colors::Blue);
	//panel.AddGUIObject(std::make_unique<Button>(Vec2(245, 245), Rect(200, 260, 200, 460)));
	//panel.AddGUIObject(std::make_unique<Grid>(Vec2(245, 245), Rect(200, 260, 200, 460), 15));
	//panel.AddGUIObject(std::make_unique<TileButton>(tileMap, 4 , Vec2(TileMap::TileSize * 6, TileMap::TileSize * 6)));

	//CurrentTileMap = tileMap;
	//int counter = 0;
	//for (int x = 0; x <= 50; x++)
	//{
	//	for (int y = 0; y <= 2; y++)
	//	{
	//		if (counter <= CurrentTileMap.GetTileCount() - 1)
	//		{
	//			const int constX = x * TileMap::TileSize;
	//			const int constY = y * TileMap::TileSize;

	//			ButtonList.emplace_back(TileButton(CurrentTileMap, counter, Vec2(constX, constY)));
	//		}
	//		counter++;
	//	}
	//}
	//SelectedButton = TileButton(CurrentTileMap, 0, Vec2(300, 300));
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
