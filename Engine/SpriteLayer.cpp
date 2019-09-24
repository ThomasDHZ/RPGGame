#include "SpriteLayer.h"

SpriteLayer::SpriteLayer()
{

}

SpriteLayer::SpriteLayer(Vec2 screenSize)
{
	ScreenSize = screenSize;
	LayerSprite = Sprite(screenSize.GetX(), screenSize.GetY());
}

SpriteLayer::~SpriteLayer()
{
}

void SpriteLayer::Update(Vec2 screenSize)
{
	ScreenSize = screenSize;

	for (auto sprite : SpriteList)
	{
		for (int x = 0; x <= sprite.sprite.GetWidth() - 1; x++)
		{
			for (int y = 0; y <= sprite.sprite.GetHeight() - 1; y++)
			{
				if (LayerSprite.GetPixel(x, y) != sprite.sprite.GetPixel(x, y))
				{
					if (sprite.sprite.GetPixel(x, y) != Colors::Black)
					{
						LayerSprite.PutPixel(sprite.pos.GetX() + x, sprite.pos.GetY() + y, sprite.sprite.GetPixel(x, y));
					}
					else
					{
						LayerSprite.PutPixel(sprite.pos.GetX() + x, sprite.pos.GetY() + y, Colors::Magenta);
					}
				}
			}
		}
	}
}

void SpriteLayer::AddSprite(LayerObject sprite)
{
	SpriteList.emplace_back(sprite);
}

void SpriteLayer::Draw(Graphics& gfx)
{
	for (int x = 0; x <= LayerSprite.GetWidth() -1; x++)
	{
		for (int y = 0; y <= LayerSprite.GetHeight() - 1; y++)
		{
			
				gfx.PutPixel(x, y, LayerSprite.GetPixel(x, y));
			
		}
	}
}
