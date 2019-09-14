#include "Sprite.h"
#include "ChiliWin.h"
#include <cassert>
#include <fstream>

Sprite::Sprite()
{
}

Sprite::Sprite(int width, int height)
{
	Width = width;
	Height = height;
	pPixels = new Color[width * height];
}

Sprite::Sprite(const std::string& filename)
{
	std::ifstream file(filename, std::ios::binary);
	assert(file);

	BITMAPFILEHEADER bmpFileHeader;
	file.read(reinterpret_cast<char*>(&bmpFileHeader), sizeof(bmpFileHeader));

	BITMAPINFOHEADER bmpInfoHeader;
	file.read(reinterpret_cast<char*>(&bmpInfoHeader), sizeof(bmpInfoHeader));

	assert(bmpInfoHeader.biBitCount == 24 || bmpInfoHeader.biBitCount == 32);
	assert(bmpInfoHeader.biCompression == BI_RGB);

	const bool is32b = bmpInfoHeader.biBitCount == 32;

	Width = bmpInfoHeader.biWidth;

	int yStart;
	int yEnd;
	int dy;

	if (bmpInfoHeader.biHeight < 0)
	{
		Height = -bmpInfoHeader.biHeight;
		yStart = 0;
		yEnd = Height;
		dy = 1;
	}
	else
	{
		Height = bmpInfoHeader.biHeight;
		yStart = Height - 1;
		yEnd = -1;
		dy = -1;
	}
	pPixels = new Color[Width * Height];

	file.seekg(bmpFileHeader.bfOffBits);
	const int padding = (4 - (Width * 3) % 4) % 4;

	for (int y = yStart; y != yEnd; y += dy)
	{
		for (int x = 0; x < Width; x++)
		{
			PutPixel(x, y, Color(file.get(), file.get(), file.get()));
			if (is32b)
			{
				file.seekg(1, std::ios::cur);
			}
		}
		if (!is32b)
		{
			file.seekg(padding, std::ios::cur);
		}
	}
}

Sprite::Sprite(const Sprite& rhs) : Sprite(rhs.Width, rhs.Height)
{
	const int nPixels = Width * Height;
	for (int x = 0; x < nPixels; x++)
	{
		pPixels[x] = rhs.pPixels[x];
	}
}

Sprite::~Sprite()
{
	delete[] pPixels;
	pPixels = nullptr;
}

Sprite& Sprite::operator=(const Sprite& rhs)
{
	Width = rhs.Width;
	Height = rhs.Height;

	delete[] pPixels;
	pPixels = new Color[Width * Height];

	const int nPixels = Width * Height;
	for (int x = 0; x < nPixels; x++)
	{
		pPixels[x] = rhs.pPixels[x];
	}

	return *this;
}

void Sprite::PutPixel(int x, int y, Color c)
{
	assert(x >= 0);
	assert(x < Width);
	assert(y >= 0);
	assert(y < Height);
	pPixels[y * Width + x] = c;
}

Color Sprite::GetPixel(int x, int y) const
{
	assert(x >= 0);
	assert(x < Width);
	assert(y >= 0);
	assert(y < Height);
	return pPixels[y * Width + x];
}

int Sprite::GetWidth() const
{
	return Width;
}

int Sprite::GetHeight() const
{
	return Height;
}