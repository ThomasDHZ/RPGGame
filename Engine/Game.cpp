/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	tileMap = TileMap("DQTiles.bmp");
	editor = TileEditor(tileMap);
	GraphicsLayerList.emplace_back(Vec2(800, 600));
	GraphicsLayerList.emplace_back(Vec2(800, 600));
	GraphicsLayerList.emplace_back(Vec2(800, 600));
	//button = TileButton(&tileMap, 1, Vec2{ 512,512 });
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	GraphicsLayerList[1].Update(Vec2(800, 600));
	GraphicsLayerList[2].Update(Vec2(800, 600));
	//editor.Update(wnd.mouse);
	///button.Update(wnd.mouse);
}

void Game::ComposeFrame()
{
	GraphicsLayerList[1].AddSprite(LayerObject(Vec2(0, 0), tileMap.GetTileMap()));
	GraphicsLayerList[1].AddSprite(LayerObject(Vec2(400, 0), tileMap.GetTileMap()));

	GraphicsLayerList[2].AddSprite(LayerObject(Vec2(100, 0), tileMap.GetTileMap()));
	GraphicsLayerList[2].AddSprite(LayerObject(Vec2(500, 0), tileMap.GetTileMap()));

	for (auto Obj : GameObjectList)
	{
		switch (Obj.GetObjectLayer())
		{
			case DrawLayer::DBackground: break;
			case DrawLayer::DSprite: break;
			case DrawLayer::DGUI: break;
		};
	}

	for (auto Layer : GraphicsLayerList)
	{
		Layer.Draw(gfx);
	}

	//editor.Draw(gfx);
	//button.Draw(gfx,1);
}
