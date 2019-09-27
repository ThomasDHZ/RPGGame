#include "SpriteLayer.h"

SpriteLayer::SpriteLayer()
{

}

SpriteLayer::SpriteLayer(Vec2 screenSize)
{
	ScreenSize = screenSize;
	LayerSprite = Sprite(screenSize.GetX(), screenSize.GetY());
	LayerDebug = false;
}

SpriteLayer::~SpriteLayer()
{
}

void SpriteLayer::Update(Vec2 screenSize)
{
	ScreenSize = screenSize;

	for (int x = 0; x <= LayerSprite.GetWidth() - 1; x++)
	{
		for (int y = 0; y <= LayerSprite.GetHeight() - 1; y++)
		{
			LayerSprite.PutPixel(x, y, Colors::Magenta);
		}
	}
}

void SpriteLayer::AddSprite(LayerObject& sprite)
{
	for (int x = 0; x <= sprite.sprite.GetWidth() - 1; x++)
	{
		for (int y = 0; y <= sprite.sprite.GetHeight() - 1; y++)
		{
			LayerSprite.PutPixel(sprite.pos.GetX() + x, sprite.pos.GetY() + y, sprite.sprite.GetPixel(x, y));
		}
	}
}

void SpriteLayer::Draw(Graphics& gfx)
{
	for (int x = 0; x <= LayerSprite.GetWidth() -1; x++)
	{
		for (int y = 0; y <= LayerSprite.GetHeight() - 1; y++)
		{
			if (!LayerDebug)
			{
				if (LayerSprite.GetPixel(x, y) != Colors::Magenta)
				{
					gfx.PutPixel(x, y, LayerSprite.GetPixel(x, y));
				}
			}
			else
			{
				gfx.PutPixel(x, y, LayerSprite.GetPixel(x, y));
			}
		}
	}
}
