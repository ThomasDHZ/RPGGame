#pragma once
#include "GameObject.h"
#include "Mouse.h"

enum GUIObjectType
{
	GNone,
	GPanel,
	GButton,
	GTileButton,
	GGrid
};

class GUIObject : public GameObject
{
private:
	GUIObjectType GuiType;
public:
	GUIObject();
	GUIObject(GUIObject& obj);
	GUIObject(GUIObjectType type);
	GUIObject(Vec2 pos, GUIObjectType type);
	virtual ~GUIObject();

	virtual void Update(Mouse& mouse);
	virtual void Draw(Graphics& gfx);

	GUIObjectType GetGUIObjectType() { return GuiType; }
};

