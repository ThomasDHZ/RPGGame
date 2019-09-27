#include "GameObject.h"

GameObject::GameObject()
{
	Pos = Vec2();
	ObjectLayer = DrawLayer::DBackground;
	//ObjectSprite = Sprite();
}

GameObject::GameObject(GameObject& obj)
{
	Pos = obj.Pos;
	ObjectLayer = obj.ObjectLayer;
	//ObjectSprite = obj.ObjectSprite;
}

GameObject::GameObject(Vec2 pos, DrawLayer layer)
{
	Pos = pos;
	ObjectLayer = layer;
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
}

void GameObject::Draw(Graphics& gfx)
{
}
