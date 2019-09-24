#include "SpriteRender.h"

SpriteRender::SpriteRender()
{
}

SpriteRender::SpriteRender(Vec2 screenSize)
{
	ScreenSize = screenSize;
	AddLayer();
	FinalImage = Sprite(ScreenSize.GetX(), ScreenSize.GetY());
}

SpriteRender::~SpriteRender()
{
}

void SpriteRender::CombineLayers()
{
	for (int x = SpriteLayerList.size(); x >= 0; x--)
	{
	    Color color = SpriteLayerList[x].GetPixel(x);
		if (SpriteLayerList[x].GetPixel(x) != color)
		{
			FinalImage.PutPixel(x, SpriteLayerList[x].GetPixel(x));
		}
	}
}

void SpriteRender::AddLayer()
{
	SpriteLayerList.emplace_back(Sprite(ScreenSize.GetX(), ScreenSize.GetY()));
}

void SpriteRender::Update()
{

	CombineLayers();
}

void SpriteRender::Draw(Graphics& gfx)
{
	gfx.DrawSprite(0, 0, FinalImage);
}