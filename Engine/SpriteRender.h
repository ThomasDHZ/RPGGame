#pragma once
#include <vector>
#include "Sprite.h"
#include "Vec2.h"
#include "Graphics.h"

class SpriteRender
{
private:
	Vec2 ScreenSize;
	std::vector<Sprite> SpriteLayerList;
	Sprite FinalImage;

	void CombineLayers();
public:
	SpriteRender();
	SpriteRender(Vec2 screenSize);
	~SpriteRender();

	void AddLayer();
	void Update();
	void Draw(Graphics& gfx);
};

