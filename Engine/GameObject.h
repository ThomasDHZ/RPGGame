#pragma once
#include "Vec2.h"
#include "Graphics.h"
class GameObject
{
private:
protected:
	Vec2 Pos;
public:
	GameObject();
	GameObject(Vec2 pos);
	virtual ~GameObject();

	virtual void Update();
	virtual void Draw(Graphics& gfx);

	Vec2 GetPos() { return Pos; }
};

