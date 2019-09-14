#pragma once
#include "Colors.h"
#include <string>
class Sprite
{
private:
	Color* pPixels = nullptr;
	int Width;
	int Height;

public:
	Sprite();
	Sprite(int Width, int Height);
	Sprite(const std::string& filename);
	Sprite(const Sprite& rhs);
	~Sprite();
	Sprite& operator=(const Sprite& rhs);

	void PutPixel(int x, int y, Color c);
	Color GetPixel(int x, int y) const;
	int GetWidth() const;
	int GetHeight() const;
};

