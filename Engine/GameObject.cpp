#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::GameObject(GameObject& obj)
{
	Pos = obj.Pos;
}

GameObject::GameObject(Vec2 pos)
{
	Pos = pos;
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
