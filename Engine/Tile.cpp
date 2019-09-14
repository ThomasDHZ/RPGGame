#include "Tile.h"

Tile::Tile()
{
	TileID = 0;
	MappingOffset = Vec2();
}

Tile::Tile(int ID, Vec2 mappingOffset)
{
	TileID = ID;
	MappingOffset = mappingOffset;
}

Tile::~Tile()
{
}
