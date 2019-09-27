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
	DrawLayer ObjectLayer;
protected:
	Vec2 Pos;
public:
	GameObject();
	GameObject(GameObject& obj);
	GameObject(Vec2 pos, DrawLayer layer);
	virtual ~GameObject();

	virtual void Update();
	virtual void Draw(Graphics& gfx);

	Vec2 GetPos() { return Pos; }
	DrawLayer GetObjectLayer() { return ObjectLayer; }
};

