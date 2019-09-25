#pragma once
#include "Vec2.h"
#include <vector>
#include "Sprite.h"
#include <memory>
#include "LayerObject.h"
#include "Graphics.h"

class SpriteLayer
{
private:
	int LayerIndex;
	Vec2 ScreenSize;
	std::vector<LayerObject> SpriteList;
	Sprite LayerSprite;
	bool LayerDebug;

public:
	SpriteLayer();
	SpriteLayer(Vec2 screenSize);
	~SpriteLayer();

	void Update(Vec2 screenSize);
	void AddSprite(LayerObject sprite);
	void Draw(Graphics& gfx);

	Sprite GetSpriteLayer() const { return LayerSprite; }
};

