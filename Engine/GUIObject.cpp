#include "GUIObject.h"

GUIObject::GUIObject() : GameObject()
{
	GuiType = GUIObjectType::GNone;
}

GUIObject::GUIObject(GUIObject& obj)
{
	Pos = obj.Pos;
	GuiType = obj.GuiType;
}

GUIObject::GUIObject(GUIObjectType type)
{
	GuiType = type;
}

GUIObject::GUIObject(Vec2 pos, GUIObjectType type) : GameObject(pos, DrawLayer::DGUI)
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