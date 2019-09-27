#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::GameObject(GameObject& obj)
{
	Pos = obj.Pos;
	ObjectLayer = obj.ObjectLayer;
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
