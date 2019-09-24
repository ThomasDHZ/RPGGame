#pragma once
#include "Vec2.h"
#include "Sprite.h"

struct LayerObject
{
	Vec2 pos;
	Sprite sprite;

	LayerObject(Vec2 Pos, Sprite sprites)
	{
		pos = Pos;
		sprite = sprites;
	}
};
