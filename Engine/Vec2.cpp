#include "Vec2.h"

Vec2::Vec2()
{
	x = 0;
	y = 0;
}

Vec2::Vec2(int X, int Y)
{
	x = X;
	y = Y;
}

Vec2::~Vec2()
{
}

void Vec2::SetY(int Y)
{
	y = Y;
}

void Vec2::SetX(int X)
{
	x = X;
}

Vec2 Vec2::operator+(const Vec2& rhs)
{
	Vec2 vec = Vec2(x + rhs.x, y + rhs.y);
	return vec;
}

Vec2 Vec2::operator-(const Vec2& rhs)
{
	Vec2 vec = Vec2(x - rhs.x, y - rhs.y);
	return vec;
}

Vec2& Vec2::operator+=(const Vec2& rhs)
{
	return *this = *this + rhs;
}

Vec2& Vec2::operator-=(const Vec2& rhs)
{
	return *this = *this - rhs;
}

bool Vec2::operator==(const Vec2& rhs)
{
	if (x == rhs.x &&
		y == rhs.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}
