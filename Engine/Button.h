#pragma once
#include "Graphics.h"
#include "Mouse.h"
#include "Tile.h"
#include "Rect.h"
class Button
{
private:
	Rect rec;
	Color borderColor;
protected: 
	Vec2 pos;
public:
	Button();
	Button(Vec2 Pos);
	virtual ~Button();

	virtual void Update(Mouse& mouse);
	virtual void Draw(Graphics& gfx);
};

