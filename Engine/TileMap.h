#pragma once
#include "Sprite.h"
#include "Graphics.h"
#include "Vec2.h"
#include <vector>
#include "Tile.h"
class TileMap
{
private:
	Sprite tileMap;
	std::vector<Tile> Tiles;
public:
	static constexpr int TileSize = 16;

	TileMap();
	TileMap(const std::string& filename);
	~TileMap();
	
	void Draw(Graphics& gfx, Vec2 TilePosition, int TileIndex);
	int GetTileCount() { return Tiles.size(); }
};

