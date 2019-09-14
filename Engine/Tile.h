#pragma once
#include "Vec2.h"
class Tile
{
private:
	int TileID;
	Vec2 MappingOffset;
public:
	Tile();
	Tile(int ID, Vec2 mappingOffset);
	~Tile();

	Vec2 GetMappingOffset() { return MappingOffset; }
};

