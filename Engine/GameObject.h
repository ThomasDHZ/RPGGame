#pragma once
#include "Vec2.h"
#include "Graphics.h"

enum DrawLayer
{
	DBackground,
	DSprite,
	DGUI
};

class GameObject
{
private:
protected:
	DrawLayer ObjectLayer;
	Sprite ObjectSprite;
	Vec2 Pos;
public:
	GameObject();
	GameObject(GameObject& obj);
	GameObject(Vec2 pos, DrawLayer layer);
	virtual ~GameObject();

	virtual void Update();
	virtual void Draw(Graphics& gfx);

	Sprite GetSprite() { return ObjectSprite; }
	Vec2 GetPos() { return Pos; }
	DrawLayer GetObjectLayer() { return ObjectLayer; }
};

