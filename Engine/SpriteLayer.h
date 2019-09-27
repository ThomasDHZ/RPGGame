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
	bool DebugLayerFlag;
	bool ShowLayerFlag;

public:
	SpriteLayer();
	SpriteLayer(Vec2 screenSize);
	~SpriteLayer();

	void Update(Vec2 screenSize);
	void AddSprite(LayerObject& sprite);
	void Draw(Graphics& gfx);
	void SetDebugLayerFlag(bool flag);
	void SetShowLayerFlag(bool flag);

	Sprite GetSpriteLayer() const { return LayerSprite; }
	bool GetDebugLayerFlag() const { return DebugLayerFlag; }
	bool GetShowLayerFlag() const { return ShowLayerFlag; }
};

