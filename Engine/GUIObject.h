#pragma once
#include "GameObject.h"
#include "Mouse.h"

enum GUIObjectType
{
	GPanel,
	GButton
};

class GUIObject : public GameObject
{
private:
	GUIObjectType GuiType;
public:
	GUIObject();
	GUIObject(Vec2 pos, GUIObjectType type);
	virtual ~GUIObject();

	virtual void Update(Mouse& mouse);
	virtual void Draw(Graphics& gfx);

	GUIObjectType GetGUIObjectType() { return GuiType; }
};

