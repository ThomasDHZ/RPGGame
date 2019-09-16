#include "GUIObject.h"

GUIObject::GUIObject() : GameObject()
{
}

GUIObject::GUIObject(Vec2 pos, GUIObjectType type) : GameObject(pos)
{
	GuiType = type;
}

GUIObject::~GUIObject()
{
}

void GUIObject::Update(Mouse& mouse)
{

}

void GUIObject::Draw(Graphics& gfx)
{

}