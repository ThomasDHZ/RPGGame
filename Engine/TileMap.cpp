#include "TileMap.h"

TileMap::TileMap()
{
}

TileMap::TileMap(const std::string& filename)
{
	tileMap = Sprite(filename);

	int tileWidth = tileMap.GetWidth() / TileSize;
	int tileHeight = tileMap.GetHeight() / TileSize;

	for (int y = 0; y <= tileHeight - 1; y++)
	{
		for (int x = 0; x <= tileWidth - 1; x++)
		{
			Tiles.emplace_back(Tile(x * y, Vec2(x, y)));
		}
	}
}

TileMap::~TileMap()
{
}

void TileMap::Draw(Graphics& gfx, Vec2 TilePosition, int TileIndex)
{
	for (int x = 0; x <= TileSize - 1; x++)
	{
		for (int y = 0; y <= TileSize - 1; y++)
		{
			gfx.PutPixel((TilePosition.GetX() * TileSize) + x, (TilePosition.GetY() * TileSize) + y, tileMap.GetPixel(x + (Tiles[TileIndex].GetMappingOffset().GetX() * TileSize), y + (Tiles[TileIndex].GetMappingOffset().GetY() * TileSize)));
		}
	}
}
